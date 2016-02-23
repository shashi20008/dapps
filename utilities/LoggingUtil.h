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
			bool m_logToFile;
			bool m_suppressStdout;
			std::string m_outputLogFile;
			std::string m_errorLogFile;
			LogLevel m_logLevel;
			
		public:
			LoggingUtil();
			LoggingUtil(std::string outputLogFile, std::string errorLogFile);
			LoggingUtil(std::string outputLogFile, std::string errorLogFile, bool logToFile, bool suppressStdout = false);
			void logVerbose(std::string message, std::string moduleName="DAPPS");
			void logDebug(std::string message, std::string moduleName="DAPPS");
			void log(std::string message, std::string moduleName="DAPPS");
			
			static LogLevel LOG_LEVEL_VERBOSE;
			static LogLevel LOG_LEVEL_DEBUG;
			static LogLevel LOG_LEVEL_APPLICATION;
	};
}

#endif //__dapps_LOGGING_UTIL__
