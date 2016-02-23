#ifndef __dapps_LOGGING_UTIL__
#define __dapps_LOGGING_UTIL__

#include <iostream>
#include <string>

namespace dapps
{
	typedef int LogLevel;
	class LoggingUtil
	{
		private:
			bool logToFile;
			bool suppressStdout;
			std::string outputLogFile;
			std::string errorLogFile;
			
		public:
			LoggingUtil();
			LoggingUtil(std::string outputLogFile, std::string errorLogFile);
			LoggingUtil(std::string outputLogFile, std::string errorLogFile, bool logToFile, bool suppressStdout = false);
			void logVerbose(std::string message, std::string moduleName="DAPPS");
			void logDebug(std::string message, std::string moduleName="DAPPS");
			void log(std::string message, std::string moduleName="DAPPS");
	};
}

#endif //__dapps_LOGGING_UTIL__
