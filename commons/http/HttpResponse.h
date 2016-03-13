#ifndef __dapps_HTTP_RESPONSE__
#define __dapps_HTTP_RESPONSE__

#include "HttpSocket.h"
#include "../containers/Buffer.h"
#include "../containers/JSONTypes.h"
#include <string>

namespace dapps
{
	class HttpResponse
	{
		// @TODO: add trailers.
		HttpHeadersMap* m_headers;
		int m_status;
		std::string m_httpVersion;
		dapps::Buffer m_body;
		
		public:
			HttpResponse();
			HttpResponse* setResponseHeaders(HttpHeadersMap*);
			HttpResponse* setResponseHeader(std::string, std::string);
			HttpResponse* setResponseBody(Buffer);
			HttpResponse* setResponseBody(JSON_t*);
			HttpResponse* setHttpVersion(std::string);
			
			HttpHeadersMap* getResponseHeaders();
			std::string getResponseHeader(std::string);
			Buffer getResponseBody();
			JSON_t* getResponseBodyJson();
			std::string getHttpVersion();
			Buffer getTCPPayload();
			
			static HttpResponse* createSuccessResponse(std::string _body, HttpHeadersMap* _additionalHeaders = NULL);
			static HttpResponse* createFailureResponse(std::string _body, HttpHeadersMap* _additionalHeaders = NULL);
			static HttpResponse* createResponse(int _status, std::string _body, HttpHeadersMap* _additionalHeaders = NULL);
	};
}

#endif //__dapps_HTTP_RESPONSE__
