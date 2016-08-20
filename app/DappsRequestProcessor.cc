#include "DappsRequestProcessor.h"
#include <iostream>
#include "../commons/json/JSON.h"
#include "DappsApplication.h"
#include "DappsApplicationFactory.h"
#include "bindings/Executor.h"

dapps::DappsRequestProcessor* dapps::DappsRequestProcessor::m_self = NULL;
dapps::DappsRequestProcessor* dapps::DappsRequestProcessor::get()
{
	if(m_self == NULL)
	{
		m_self = new DappsRequestProcessor();
	}
	return m_self;
}

void dapps::DappsRequestProcessor::process(DappsContext* _context, dapps::JSON_t* request)
{
	std::cout << "came to process.. Got:: " << JSON::stringify(request) << std::endl;
	std::string appName = request->getString("AppName");
	DappsApplication* app = DappsApplicationFactory::getApp(appName);
	if(app == NULL) 
	{
		// @TODO: send back error response
		return;
	}
	Executor* executor = Executor::create(app->getAppType());
	if(executor == NULL)
	{
		// @TODO: send back error reponse
		return;
	}
	_context->put("executor", executor);
	executor->execute(app, _context, request, "");
}
