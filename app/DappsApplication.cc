#include "DappsApplication.h"
#include "../commons/exceptions/DappsException.h"
#include "../commons/utilities/PathUtils.h"
#include <iostream>

const std::string dapps::DappsApplication::DAPPS_CONFIG_FILENAME = "dapps.json";

dapps::DappsApplication::DappsApplication(std::string path)
{
	std::cout << "path from app:: " << path <<std::endl;
	m_appPath = path;
	loadConfig();
	updateDB();
}

// @TODO: check if its worth making async
void dapps::DappsApplication::loadConfig()
{
	std::string configFilePath = PathUtils::join(m_appPath.c_str(), DappsApplication::DAPPS_CONFIG_FILENAME.c_str());
	m_appConfig = new ConfigProcessor(configFilePath);
	JSON_t* config =  m_appConfig->getConfig();
	m_appName = config->getString("AppName");
	m_appExecutableName = config->getString("main");
	m_appType = config->getString("type");
	try
	{
		m_mountPath = config->getString("mountPath");
	}
	catch(DappsException e)
	{
	}
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
