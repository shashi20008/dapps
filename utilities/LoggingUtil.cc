#include "LoggingUtil.h"

dapps::LoggingUtil::LoggingUtil()
{
	this->logToFile = false;
	this->suppressStdout = false;
	this->outputLogFile = "";
	this->errorLogFile = "";
}

dapps::LoggingUtil::LoggingUtil(std::string outputLogFile, std::string errorLogFile)
{
	this->logToFile = true;
	this->suppressStdout = false;
	this->outputLogFile = outputLogFile;
	this->errorLogFile = errorLogFile;
}

dapps::LoggingUtil::LoggingUtil(std::string outputLogFile, std::string errorLogFile, bool logToFile, bool suppressStdout)
{
	this->logToFile = logToFile;
	this->suppressStdout = suppressStdout;
	this->outputLogFile = outputLogFile;
	this->errorLogFile = errorLogFile;
}

void dapps::LoggingUtil::logVerbose(std::string message, std::string moduleName)
{
}

void dapps::LoggingUtil::logDebug(std::string message, std::string moduleName)
{
}

void dapps::LoggingUtil::log(std::string message, std::string moduleName)
{
}
