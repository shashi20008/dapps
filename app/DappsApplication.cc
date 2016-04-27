#include "DappsApplication.h"
#include "../commons/exceptions/DappsException.h"
#include "../commons/utilities/PathUtils.h"
#include "../commons/mongodb/MongoClient.h"
#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include "../commons/containers/JSONTypes.h"
#include "../dapps.h"

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
	char* configFilePath = PathUtils::join(m_appPath.c_str(), DappsApplication::DAPPS_CONFIG_FILENAME.c_str());
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
	delete[] configFilePath;
}

//@TODO: Add implementation to update this app's details in DB.
void dapps::DappsApplication::updateDB()
{
	struct addrinfo hints, *res;

	char hostname[1024];
	hostname[1023] = '\0';
	gethostname(hostname, 1023);

	memset (&hints, 0, sizeof (hints));
	hints.ai_family = PF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags |= AI_CANONNAME;

	MongoClient* mongoClient = new MongoClient();
	getaddrinfo (hostname, NULL, &hints, &res);
	
	JSON_t* appConfig = Dapps::get()->config->getConfig();
	int port = appConfig->get("server")->getInt("port");

	std::cout<<"Host: " <<res->ai_canonname <<" port:" << port<<std::endl;
	bool insertFlag = mongoClient->updateApplicationDetails(res->ai_canonname, port, m_appName);
	std::cout<<"AppDetails inserted: " <<insertFlag <<std::endl;

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
