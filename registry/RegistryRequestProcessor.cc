#include "RegistryRequestProcessor.h"
#include "../app/DappsRequestProcessor.h"
#include "../commons/sockets/TcpClient.h"
#include "../commons/containers/Buffer.h"
#include "../commons/containers/ServerSchema.h"
#include "../commons/utilities/DappsErrors.h"
#include "../commons/mongodb/MongoClient.h"
#include "../commons/http/HttpResponse.h"
#include "../commons/utilities/StringUtils.h"
#include "../commons/json/JSON.h"
#include <iostream>

dapps::RegistryRequestProcessor* dapps::RegistryRequestProcessor::m_self =  NULL;

dapps::RegistryRequestProcessor::RegistryRequestProcessor()
{
}

dapps::RegistryRequestProcessor* dapps::RegistryRequestProcessor::get()
{
	if(m_self == NULL)
	{
		m_self = new RegistryRequestProcessor();
	}
	return m_self;
}
void dapps::RegistryRequestProcessor::finishRequest(DappsContext* _context, Buffer response) 
{
	HttpSocket* socket = (HttpSocket*)_context->get("httpSocket");

	HttpResponse* httpResponse = HttpResponse::createSuccessResponse(response.str());
	socket->write(httpResponse);
	
	JSON_t* _request = (JSON_t*) _context->get("request");
	delete _request;
}
void dapps::RegistryRequestProcessor::process(dapps::DappsContext* _context)
{
	std::cout << "got to RegistryRequestProcessor::process" << std::endl;

	HttpSocket* socket = (HttpSocket*)_context->get("httpSocket");

	std::vector<std::string> urlParts = StringUtils::split(socket->getRequestPath(), '/', 3, true);
	std::size_t urlPartsLen = urlParts.size();
	if(urlPartsLen < 2)
	{
		// @TODO: return error response instead.
		//socket->write(DappsErrors::INVALID_REQUEST_URI->getJSONString());
		HttpResponse* response = HttpResponse::createSuccessResponse(DappsErrors::INVALID_REQUEST_URI->getJSONString());
		socket->write(response);
		return;
	}
	
	// @TODO: move _empty to a static constants file.
	std::string _empty = "";
	// std::string& dappsVersion =  urlParts[0]; // ?? Is there any use for this
	std::string& appURI = urlParts[1];
	// std::string& appURLParam = urlPartsLen > 2 ? urlParts[2] : _empty; // We should pass this to app server.
	
	MongoClient* mongoClient = new MongoClient();
	std::string appName = mongoClient->getApplicationName(appURI.c_str());
	delete mongoClient;
	std::cout << "AppId: '" << appName << "' got '" << socket->getRequestBody().str() << "' request" << std::endl;
	
	
	std::string json = "{\"AppName\":\"" + appName + "\"}";
	JSON_t* _request = JSON::parse(json);
	_context->put("request", _request);

	DappsRequestProcessor* _processor = DappsRequestProcessor::get();
	_processor->process(_context, _request);
}
