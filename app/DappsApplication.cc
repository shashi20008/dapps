#include "DappsApplication.h"
#include "../commons/utilities/PathUtils.h"
#include <iostream>

const std::string dapps::DappsApplication::DAPPS_CONFIG_FILENAME = "dapps.json";

dapps::DappsApplication::DappsApplication(std::string path)
{
	m_appPath = path;
	loadConfig();
	updateDB();
}

// @TODO: check if its worth making async
void dapps::DappsApplication::loadConfig()
{
	std::string configFilePath = PathUtils::join(m_appPath.c_str(), DappsApplication::DAPPS_CONFIG_FILENAME.c_str());
	m_appConfig = new ConfigProcessor(configFilePath);
	m_appName = m_appConfig->getConfig()->getString("AppName");
	m_appExecutableName = m_appConfig->getConfig()->getString("main");
	m_appType = m_appConfig->getConfig()->getString("type");
}

//@TODO: Add implementation to update this app's details in DB.
void dapps::DappsApplication::updateDB()
{
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
