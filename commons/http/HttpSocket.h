#ifndef __dapps_HTTP_SOCKET__
#define __dapps_HTTP_SOCKET__

#include <map>
#include <string>
#include <iostream>
#include <vector>
#include "../containers/Buffer.h"
#include "../containers/DappsContext.h"
#include "../containers/JSONTypes.h"
#include "AbstractHttpClient.h"
#include "../sockets/AbstractClientSocket.h"
#include "../utilities/StringUtils.h"

namespace dapps
{
	typedef std::map<std::string, std::string> HttpHeadersMap;
	typedef std::pair<std::string, std::string> HttpHeader;
	
	class HttpSocket
	{
		private:
			HttpHeadersMap* m_requestHeaders;
			Buffer m_requestBody;
			std::string m_requestMethod;
			std::string m_requestPath;
			std::string m_httpVersion;
			bool m_parseComplete;
			bool m_headersParsed;
			bool m_commandParsed;
			
			HttpHeadersMap* m_responseHeaders;
			HttpHeadersMap* m_responseTrailers;
			Buffer m_responseBody;
			
			DappsContext* m_context;
			AbstractClientSocket* m_socket;
			AbstractHttpClient* m_client;
		
		public:
			HttpSocket(DappsContext*, AbstractClientSocket*, AbstractHttpClient*);
			HttpHeadersMap* getRequestHeaders();
			std::string getRequestHeader(std::string);
			Buffer getRequestBody();
			JSON_t* getRequestBodyJson();
			
			HttpSocket* setResponseHeaders(HttpHeadersMap*);
			HttpSocket* setResponseHeader(std::string, std::string);
			HttpSocket* setResponseTrailers(HttpHeadersMap*);
			HttpSocket* setResponseTrailer(std::string, std::string);
			HttpSocket* setResponseBody(Buffer);
			HttpSocket* setResponseBody(JSON_t*);
			HttpHeadersMap* getResponseHeaders();
			std::string getResponseHeader(std::string);
			HttpHeadersMap* getResponseTrailers();
			std::string getResponseTrailer(std::string);
			Buffer getResponseBody();
			JSON_t* getResponseBodyJson();
			
			bool isHeadersParsed();
			bool isCommandParsed();
			bool isParsingComplete();
			void feed(std::string);
			void feed(const char*, ssize_t);
			void write();

			void parseCommand(std::string);
			void parseHeaders(std::string);
	};
}

#endif //__dapps_HTTP_SOCKET__
