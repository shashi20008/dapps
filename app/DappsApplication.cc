#include "DappsApplication.h"

const std::string dapps::DappsApplication::DAPPS_CONFIG_FILENAME = "dapps.json";

dapps::DappsApplication::DappsApplication(std::string path)
{
	m_appPath = path;
	loadConfig();
}

// @TODO: check if its worth making async
void dapps::DappsApplication::loadConfig()
{
	std::string configFilePath = m_appPath + DappsApplication::DAPPS_CONFIG_FILENAME;
	m_appConfig = new ConfigProcessor(configFilePath);
	
}

std::string dapps::DappsApplication::getAppPath()
{
	return m_appPath;
}

dapps::ConfigProcessor* dapps::DappsApplication::getAppConfig()
{
	return m_appConfig;
}

std::string dapps::DappsApplication::getAppExecutableName()
{
	return dapps::DappsApplication::m_appExecutableName;
}

std::string dapps::DappsApplication::getAppType()
{
	return m_appType;
}

std::string dapps::DappsApplication::getAppName()
{
	return m_appName;
}
