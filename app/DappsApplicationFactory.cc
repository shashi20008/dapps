#include "DappsApplicationFactory.h"
#include "DappsApplication.h"
#include "bindings/CgiExecutor.h"
#include "../commons/exceptions/DappsException.h"
#include "../commons/utilities/PathUtils.h"
#include <iostream>
#include <cstdlib>

bool dapps::DappsApplicationFactory::m_initialized;
std::string dapps::DappsApplicationFactory::m_deploymentDir;
dapps::ApplicationsMap* dapps::DappsApplicationFactory::m_applications;

void dapps::DappsApplicationFactory::initialize(std::string deploymentDir)
{
	m_deploymentDir = deploymentDir;
	m_applications = new ApplicationsMap();
	scanForApplications();
}

void dapps::DappsApplicationFactory::scanForApplications()
{
	uv_loop_t* _loop = uv_default_loop();
	uv_fs_t* _fsReq = (uv_fs_t*) malloc(sizeof(uv_fs_t));
	
	uv_fs_scandir(_loop, _fsReq, m_deploymentDir.c_str(), O_RDONLY, DappsApplicationFactory::onScan);
}


void dapps::DappsApplicationFactory::onScan(uv_fs_t* _req)
{
	uv_dirent_t _entry;
	
	while(uv_fs_scandir_next(_req, &_entry) != UV_EOF)
	{
		char* fullPath = PathUtils::join(m_deploymentDir.c_str(), _entry.name);
		std::cout << "loading app from: " << fullPath << std::endl;
		
		try
		{
			DappsApplication* _app = new DappsApplication(fullPath);
			m_applications->insert(ApplicationsPair(_app->getAppName(), _app));
		}
		catch(DappsException e)
		{
			std::cout << "couldn't load application in dir:: " << fullPath << std::endl;
			std::cout << "\tbecause: " << e.what() << std::endl;
		}
		
		delete[] fullPath;
	}
	uv_fs_req_cleanup(_req);
	free(_req);

	uv_loop_t* _loop = uv_default_loop();

	uv_fs_event_t *fs_event_req = (uv_fs_event_t*)malloc(sizeof(uv_fs_event_t));
    uv_fs_event_init(_loop, fs_event_req);
    uv_fs_event_start(fs_event_req, DappsApplicationFactory::runCommand, m_deploymentDir.c_str(), 0);
}

void dapps::DappsApplicationFactory::runCommand(uv_fs_event_t *handle, const char *filename, int events, int status) {
	char path[1024];
    size_t size = 1023;
    uv_fs_event_getpath(handle, path, &size);
    path[size] = '\0';

    std::cout<<"Path:"<<path<<" " <<m_deploymentDir.c_str()<<" file:"<<filename<<std::endl;
  //   try
		// {
		// 	DappsApplication* _app = new DappsApplication(fullPath);
		// 	m_applications->insert(ApplicationsPair(_app->getAppName(), _app));
		// }
		// catch(DappsException e)
		// {
		// 	std::cout << "couldn't load application in dir:: " << fullPath << std::endl;
		// 	std::cout << "\tbecause: " << e.what() << std::endl;
		// }
}

dapps::DappsApplication* dapps::DappsApplicationFactory::getApp(std::string _name)
{
	ApplicationsMap::iterator it = m_applications->find(_name);
	if(it !=  m_applications->end())
	{
		return it->second;
	}
	return NULL;
}
