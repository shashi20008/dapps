#include "HttpResponse.h"
#include "HttpConstants.h"
#include "../utilities/StringUtils.h"
#include <iostream>

dapps::HttpResponse::HttpResponse()
{
	m_headers = new HttpHeadersMap();
	m_status = 0;
}

dapps::HttpResponse* dapps::HttpResponse::setResponseHeaders(dapps::HttpHeadersMap* headers)
{
	if(m_headers != NULL)
	{
		delete m_headers;
	}
	m_headers = headers;
	return this;
}

dapps::HttpResponse* dapps::HttpResponse::setResponseHeader(std::string headerName, std::string headerVal)
{
	if(m_headers == NULL)
	{
		m_headers = new HttpHeadersMap();
	}
	m_headers->insert(HttpHeader(headerName, headerVal));
	return this;
}

dapps::HttpResponse* dapps::HttpResponse::setResponseBody(dapps::Buffer body)
{
	m_body = body;
	return this;
}

dapps::HttpResponse* dapps::HttpResponse::setResponseBody(dapps::JSON_t* bodyJson)
{
	return this;
}

dapps::HttpResponse* dapps::HttpResponse::setHttpVersion(std::string _version)
{
	m_httpVersion = _version;
	return this;
}

dapps::HttpHeadersMap* dapps::HttpResponse::getResponseHeaders()
{
	return m_headers;
}

std::string dapps::HttpResponse::getResponseHeader(std::string headerName)
{
	return "";
}

dapps::Buffer dapps::HttpResponse::getResponseBody()
{
	return m_body;
}

dapps::JSON_t* dapps::HttpResponse::getResponseBodyJson()
{
	return NULL;
}

std::string dapps::HttpResponse::getHttpVersion()
{
	return m_httpVersion;
}

dapps::Buffer dapps::HttpResponse::getTCPPayload()
{
	Buffer payload;	
	payload.append(m_httpVersion + " " + StringUtils::toString(m_status) + HttpConstants::getStatusMessage(m_status) + "\r\n");
	HttpHeadersMap::iterator it = m_headers->begin();
	while(it != m_headers->end())
	{
		payload.append(it->first + ": " + it->second + "\r\n");
		it++;
	}
	payload.append("\r\n");
	payload.append(m_body.c_str());
	return payload;
}

// Statics
dapps::HttpResponse* dapps::HttpResponse::createSuccessResponse(std::string _body, dapps::HttpHeadersMap* _additionalHeaders)
{
	HttpResponse* _response = new HttpResponse();
	_response->m_status = HttpConstants::HTTP_STATUS_CODE_OK;
	_response->m_body.append(_body);
	std::size_t _bodyLen = _response->m_body.size();
	_response->m_headers->insert(HttpHeader(HttpConstants::HTTP_HEADER_CONTENT_LENGTH, StringUtils::toString(_bodyLen)));
	_response->m_headers->insert(HttpHeader(HttpConstants::HTTP_HEADER_CONTENT_TYPE, "application/json"));
	if(_additionalHeaders != NULL)
	{
		_response->m_headers->insert(_additionalHeaders->begin(), _additionalHeaders->end());
	}
	return _response;
			
}

dapps::HttpResponse* dapps::HttpResponse::createFailureResponse(std::string _body, dapps::HttpHeadersMap* _additionalHeaders)
{
	HttpResponse* _response = createSuccessResponse(_body, _additionalHeaders);
	_response->m_status = HttpConstants::HTTP_STATUS_CODE_BAD_REQUEST;
	return _response;
}

dapps::HttpResponse* dapps::HttpResponse::createResponse(int _status, std::string _body, dapps::HttpHeadersMap* _additionalHeaders)
{
	HttpResponse* _response = createSuccessResponse(_body, _additionalHeaders);
	_response->m_status = _status;
	return _response;
}
