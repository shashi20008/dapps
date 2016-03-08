#ifndef __dapps_COMMONS__
#define __dapps_COMMONS__
namespace dapps
{
	// typedefs 
	typedef std::map<std::string, std::string> HttpHeadersMap;
	typedef std::pair<std::string, std::string> HttpHeader;
	
	// Forward declarations to satisfy circular dependencies
	class Buffer;
	class DappsContext;
	class DappsException;
	class JSONParseException;
	class AbstractHttpClient;
	class HttpSocket;
	class JSON;
	class AbstractClientSocket;
	class LoggingUtil;
	class StringUtils;
	class HttpSocket;
	class HttpResponse;
}
#endif //__dapps_COMMONS__
