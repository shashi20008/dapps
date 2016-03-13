#ifndef __dapps_HTTP_SOCKET__
#define __dapps_HTTP_SOCKET__

#include "../dapps-commons.h"
#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <sys/types.h>
#include "../containers/Buffer.h"
#include "../containers/DappsContext.h"
#include "../containers/JSONTypes.h"
#include "AbstractHttpApplication.h"
#include "../sockets/AbstractClientSocket.h"
#include "../utilities/StringUtils.h"
#include "HttpResponse.h"

namespace dapps
{
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
			bool m_bodyPresent;
			std::size_t m_contentLength;
			
			Buffer m_token;
			
			DappsContext* m_context;
			AbstractClientSocket* m_socket;
			AbstractHttpApplication* m_client;
		
		public:
			HttpSocket(DappsContext*, AbstractClientSocket*, AbstractHttpApplication*);
			std::string getRequestMethod();
			std::string getRequestPath();
			std::string getHttpVersion();
			HttpHeadersMap* getRequestHeaders();
			std::string getRequestHeader(std::string);
			Buffer getRequestBody();
			JSON_t* getRequestBodyJson();
			
			bool isHeadersParsed();
			bool isCommandParsed();
			bool isParsingComplete();
			void feed(std::string);
			void feed(const char*, ssize_t);
			void write(HttpResponse*);

			void parseCommand(std::string);
			void parseHeaders(std::string);
	};
}

#endif //__dapps_HTTP_SOCKET__
