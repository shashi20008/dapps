#ifndef __dapps_HTTP_SOCKET__
#define __dapps_HTTP_SOCKET__

#include <map>
#include <string>

namespace dapps
{
	typedef std::map<std::string, std::string> HttpHeadersMap;
	typedef std::map<std::string, std::string> HttpHeader;
	
	class HttpSocket
	{
		private:
			HttpHeadersMap* m_headers;
			HttpHeadersMap* m_trailers;
			std::string m_body;
			std::string m_httpMethod;
			std::string m_path;
			std::string m_httpVersion;
	};
}

#endif //__dapps_HTTP_SOCKET__
