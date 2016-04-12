#include "RegistryRequestProcessor.h"
#include "../commons/sockets/TcpClient.h"
#include "../commons/containers/Buffer.h"
#include "../commons/utilities/DappsErrors.h"
#include "../commons/mongodb/MongoClient.h"
#include "../commons/http/HttpResponse.h"
#include "../commons/utilities/StringUtils.h"
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
	std::cout << "going to send request to browser" << std::endl;
	HttpResponse* res = new HttpResponse();

	std::cout << "created response" << std::endl;
	HttpSocket* socket = (HttpSocket*)_context->get("httpSocket");

	HttpResponse* httpResponse = HttpResponse::createSuccessResponse(response.str());
	std::cout << "created response" << std::endl;

	socket->write(httpResponse);

	std::cout << "sent response" << std::endl;
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
	std::string& dappsVersion =  urlParts[0];
	std::string& appURI = urlParts[1];
	std::string& appURLParam = urlPartsLen > 2 ? urlParts[2] : _empty;
	
	MongoClient* mongoClient = new MongoClient();
	//std::string appId = mongoClient->getApplicationIdByURI(appURI.c_str());
	std::string appName = mongoClient->getApplicationName(appURI.c_str());
	std::cout << "AppId: '" << appName << "' got '" << socket->getRequestBody().str() << "' request" << std::endl;
	delete mongoClient;
	
	std::string json = "{\"AppName\":\"" + appName + "\"}";
	Buffer buffer;
	std::size_t bodyLen = json.length();
	buffer.append(StringUtils::toString(bodyLen) + "\r\n" + json );
	TcpClient* tcpCliet = new TcpClient(_context,"127.0.0.1", 8081, buffer);
}
