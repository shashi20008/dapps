#include "HttpSocket.h"

dapps::HttpSocket::HttpSocket(dapps::DappsContext* _context, AbstractClientSocket* _socket, AbstractHttpClient* _client)
{
	m_requestHeaders = new HttpHeadersMap();
	m_parseComplete = false;
	m_headersParsed = false;
	m_commandParsed = false;
	m_bodyPresent = false;
	
	m_responseHeaders = new HttpHeadersMap();
	m_responseTrailers = new HttpHeadersMap();
	
	m_context = _context;
	m_socket = _socket;
	m_client = _client;
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

dapps::HttpSocket* dapps::HttpSocket::setResponseHeaders(dapps::HttpHeadersMap* headers)
{
	m_responseHeaders = headers;
	return this;
}

dapps::HttpSocket* dapps::HttpSocket::setResponseHeader(std::string headerName, std::string headerVal)
{
	return this;
}

dapps::HttpSocket* dapps::HttpSocket::setResponseTrailers(dapps::HttpHeadersMap* trailers)
{
	m_responseTrailers = trailers;
	return this;
}

dapps::HttpSocket* dapps::HttpSocket::setResponseTrailer(std::string trailerName, std::string trailerVal)
{
	return this;
}

dapps::HttpSocket* dapps::HttpSocket::setResponseBody(dapps::Buffer body)
{
	m_responseBody = body;
	return this;
}

dapps::HttpSocket* dapps::HttpSocket::setResponseBody(dapps::JSON_t* bodyJson)
{
	return this;
}

dapps::HttpHeadersMap* dapps::HttpSocket::getResponseHeaders()
{
	return m_responseHeaders;
}

std::string dapps::HttpSocket::getResponseHeader(std::string headerName)
{
	return "";
}

dapps::HttpHeadersMap* dapps::HttpSocket::getResponseTrailers()
{
	return m_responseTrailers;
}

std::string dapps::HttpSocket::getResponseTrailer(std::string trailerName)
{
	return "";
}

dapps::Buffer dapps::HttpSocket::getResponseBody()
{
	return m_responseBody;
}

dapps::JSON_t* dapps::HttpSocket::getResponseBodyJson()
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
	m_commandParsed = true;
	std::vector<std::string> splitedVector = StringUtils::split(tempBuffer, ' ');
	m_requestMethod = splitedVector[0];
	m_requestPath = splitedVector[1];
	m_httpVersion = splitedVector[2];
	std::cout<<m_requestMethod <<m_requestPath<<m_httpVersion<<std::endl;
}

void dapps::HttpSocket::parseHeaders(std::string tempBuffer)
{
	if(tempBuffer.empty()){
		HttpHeadersMap::iterator itr = m_requestHeaders->begin();
		while(itr!= m_requestHeaders->end()){
			std::cout<<"key:: "<<itr->first<<" value:: "<<itr->second<<std::endl;
			itr++;
		}
		m_headersParsed =  true;
	}
	else 
	{
		std::vector<std::string> splitedVector = StringUtils::split(tempBuffer, ':');
		m_requestHeaders->insert(HttpHeader(splitedVector[0],splitedVector[1]));
		std::string check = StringUtils::toUpperCase(splitedVector[0]);
		if(StringUtils::toUpperCase(splitedVector[0]) == "CONTENT-LENGTH")
		{
			m_bodyPresent = true;
			//TODO:: replece atoi with some other function
			m_contentLength = atoi(splitedVector[1].c_str());
		}
	}
}

void dapps::HttpSocket::feed(std::string str)
{
}

void dapps::HttpSocket::feed(const char* buffer, ssize_t nread)
{	
	std::string tempBuffer;
	bool markPossibleEnd = false;
	int startPos = 0;
	
	std::cout<<buffer<<std::endl;
	for(int i = 0; i < nread; i++)
	{
		if(buffer[i] == '\r')
		{
			markPossibleEnd = true;
		} 
		else if (markPossibleEnd && buffer[i] == '\n')
		{
			if(!m_commandParsed)
			{	
				tempBuffer = StringUtils::trim(std::string(buffer).substr(startPos,i-startPos));
				startPos = i+1;
				parseCommand(tempBuffer);
			}
			else if(!m_headersParsed)
			{	
				tempBuffer = StringUtils::trim(std::string(buffer).substr(startPos,i-startPos));
				startPos = i+1;
				parseHeaders(tempBuffer);
			}
		}
		else if(m_headersParsed && m_bodyPresent)
		{		
			m_requestBody.append(buffer[i]);
		}
		else
		{

		}
	}
	std::cout<<"m_requestBody"<<m_requestBody.c_str()<<std::endl;
	std::cout<<"for loop end"<<std::endl;
}

void dapps::HttpSocket::write()
{
}
