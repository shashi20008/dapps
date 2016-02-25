#include "LoggingUtil.h"

dapps::LoggingUtil::LoggingUtil()
{
	this->m_logToFile = false;
	this->m_suppressStdout = false;
	this->m_outputLogFile = "";
	this->m_errorLogFile = "";
	this->m_logLevel = LOG_LEVEL_DEBUG;
}

dapps::LoggingUtil::LoggingUtil(std::string outputLogFile, std::string errorLogFile)
{
	this->m_logToFile = true;
	this->m_suppressStdout = false;
	this->m_outputLogFile = outputLogFile;
	this->m_errorLogFile = errorLogFile;
	this->m_logLevel = LOG_LEVEL_DEBUG;
}

dapps::LoggingUtil::LoggingUtil(std::string outputLogFile, std::string errorLogFile, bool logToFile, bool suppressStdout)
{
	this->m_logToFile = logToFile;
	this->m_suppressStdout = suppressStdout;
	this->m_outputLogFile = outputLogFile;
	this->m_errorLogFile = errorLogFile;
	this->m_logLevel = LOG_LEVEL_DEBUG;
}

void dapps::LoggingUtil::logVerbose(std::string message, std::string moduleName)
{
	if(this->m_logLevel >= LOG_LEVEL_VERBOSE)
	{
		this->log(message, moduleName);
	}
}

void dapps::LoggingUtil::logDebug(std::string message, std::string moduleName)
{
	if(this->m_logLevel >= LOG_LEVEL_DEBUG)
	{
		this->log(message, moduleName);
	}
}

void dapps::LoggingUtil::log(std::string message, std::string moduleName)
{
	std::cout << moduleName << ":\t " << message;
}

dapps::LogLevel dapps::LoggingUtil::LOG_LEVEL_VERBOSE = 0;
dapps::LogLevel dapps::LoggingUtil::LOG_LEVEL_DEBUG = 1;
dapps::LogLevel dapps::LoggingUtil::LOG_LEVEL_APPLICATION = 2;
