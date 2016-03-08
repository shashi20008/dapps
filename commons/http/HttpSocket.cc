#include "HttpSocket.h"

dapps::HttpSocket::HttpSocket(dapps::DappsContext* _context, AbstractClientSocket* _socket, AbstractHttpClient* _client)
{
	m_requestHeaders = new HttpHeadersMap();
	m_parseComplete = false;
	m_headersParsed = false;
	m_commandParsed = false;
	m_bodyPresent = false;
	
	m_contentLength = 0;
	
	m_context = _context;
	m_socket = _socket;
	m_client = _client;
}

std::string dapps::HttpSocket::getRequestMethod()
{
	return m_requestMethod;
}

std::string dapps::HttpSocket::getRequestPath()
{
	return m_requestPath;
}

std::string dapps::HttpSocket::getHttpVersion()
{
	return m_httpVersion;
}

dapps::HttpHeadersMap* dapps::HttpSocket::getRequestHeaders()
{
	return m_requestHeaders;
}

std::string dapps::HttpSocket::getRequestHeader(std::string headerName)
{
	HttpHeadersMap::iterator itr = m_requestHeaders->find(headerName);
	return (itr == m_requestHeaders->end() ? itr->second : "");
}

dapps::Buffer dapps::HttpSocket::getRequestBody()
{
	return m_requestBody;
}

dapps::JSON_t* dapps::HttpSocket::getRequestBodyJson()
{
	return NULL;
}

bool dapps::HttpSocket::isHeadersParsed()
{
	return m_headersParsed;
}

bool dapps::HttpSocket::isParsingComplete()
{
	return m_parseComplete;
}

bool dapps::HttpSocket::isCommandParsed()
{
	return m_commandParsed;
}

void dapps::HttpSocket::parseCommand(std::string tempBuffer)
{
	//std::cout << "parsing command" << std::endl;
	m_commandParsed = true;
	std::vector<std::string> splitedVector = StringUtils::split(tempBuffer, ' ');
	m_requestMethod = StringUtils::trim(splitedVector[0]);
	m_requestPath = StringUtils::trim(splitedVector[1]);
	m_httpVersion = StringUtils::trim(splitedVector[2]);
	//std::cout << "command parsed" << std::endl;
}

void dapps::HttpSocket::parseHeaders(std::string tempBuffer)
{
	//std::cout << "parsing header: " << tempBuffer << std::endl;
	if(tempBuffer.empty()){
		m_headersParsed =  true;
		
		if(!m_bodyPresent)
		{
			m_parseComplete = true;
		}
	}
	else 
	{
		std::vector<std::string> splitedVector = StringUtils::split(tempBuffer, ':');
		std::string headerKey = StringUtils::trim(splitedVector[0]);
		std::string headerValue = StringUtils::trim(splitedVector[1]);
		
		m_requestHeaders->insert(HttpHeader(headerKey, headerValue));
		if(StringUtils::toUpperCase(headerKey) == "CONTENT-LENGTH")
		{
			m_bodyPresent = true;
			StringUtils::fromString(headerValue, &m_contentLength);
			m_requestBody = Buffer(m_contentLength);
		}
	}
	//std::cout << "header Parsed" << std::endl;
}

void dapps::HttpSocket::feed(std::string str)
{
}

void dapps::HttpSocket::feed(const char* buffer, ssize_t nread)
{
	if(m_parseComplete)
	{
		// We already have all we need.
		return;
	}
	
	// @TODO: try to avoid multiple append function calls.
	for(ssize_t i = 0; i < nread; i++)
	{
		if(!m_headersParsed)
		{
			m_token.append(buffer[i]);
			if(m_token.endsWith("\r\n"))
			{
				if(!m_commandParsed)
				{
					parseCommand(StringUtils::trim(m_token.str()));
					m_token.clear();
				}
				else
				{
					parseHeaders(StringUtils::trim(m_token.str()));
					m_token.clear();
				}
			}
		}
		else if(m_bodyPresent && m_contentLength > m_requestBody.size())
		{
			std::size_t bytesLeftInBuffer = nread - i;
			std::size_t bytesLeftToRead = m_contentLength - m_requestBody.size();
			std::size_t bytesToRead = (bytesLeftInBuffer >= bytesLeftToRead ? bytesLeftToRead : bytesLeftInBuffer);
			m_requestBody.append(buffer, bytesToRead, i);
			
			if(m_contentLength <= m_requestBody.size())
			{
				m_parseComplete = true;
			}
			break;
		} 
	}
	
	if(m_parseComplete)
	{
		m_client->process(m_context, this);
	}
}

void dapps::HttpSocket::write(HttpResponse* _httpResponse)
{
}
