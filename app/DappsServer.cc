#include "DappsServer.h"
#include "DappsApplicationFactory.h"
#include <cstdlib>
#include <iostream>

dapps::DappsServer::DappsServer(dapps::Dapps* _app)
{
	m_app = _app;
	init();
	std::cout << "init complete" <<std::endl;
}

dapps::DappsServer::~DappsServer()
{
	
}

void dapps::DappsServer::init()
{
	ArgsValList* appsDir = m_app->args->get("appsDir");
	if(appsDir != NULL && appsDir->size() > 0)
	{
		DappsApplicationFactory::initialize(appsDir->at(0));
	} else 
	{
		throw DappsException("No Applications deployment directory specified.");
	}
}

dapps::Dapps* dapps::DappsServer::getApp() 
{
	return m_app;
}
