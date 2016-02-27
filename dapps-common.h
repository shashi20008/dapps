#ifndef __dapps_COMMON__
#define __dapps_COMMON__
namespace dapps
{
	// Forward declarations to satisfy circular dependencies
	class Dapps;
	class RegistryServer;
	class JSON;
	class LoggingUtil;
	class StringUtils;
	class ArgsProcessor;
	
	// From Commons
	class AbstractHttpClient;
	class AbstractClientSocket;
	class HttpSocket;
}
#endif //__dapps_COMMON__
