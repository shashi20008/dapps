#include "HttpSocket.h"

dapps::HttpSocket::HttpSocket(dapps::DappsContext* _context, AbstractClientSocket* _socket, AbstractHttpClient* _client)
{
	m_requestHeaders = NULL;
	m_parseComplete = false;
	m_headersParsed = false;
	
	m_responseHeaders = NULL;
	m_responseTrailers = NULL;
	
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

void write()
{
}
