#include "RegistryRequestProcessor.h"
#include "../commons/exceptions/DappsException.h"
#include "../commons/mongodb/MongoClient.h"
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

void dapps::RegistryRequestProcessor::process(dapps::DappsContext* _context, dapps::HttpSocket* socket)
{
	std::cout << "got to RegistryRequestProcessor::process" << std::endl;
	std::vector<std::string> urlParts = StringUtils::split(socket->getRequestPath(), '/', 3, true);
	std::size_t urlPartsLen = urlParts.size();
	if(urlPartsLen < 2)
	{
		// @TODO: return error response instead.
		throw DappsException("Invalid Request received");
	}
	
	// @TODO: move _empty to a static constants file.
	std::string _empty = "";
	std::string& dappsVersion =  urlParts[0];
	std::string& appURI = urlParts[1];
	std::string& appURLParam = urlPartsLen > 2 ? urlParts[2] : _empty;
	
	MongoClient* mongoClient = new MongoClient();
	std::string appId = mongoClient->getApplicationIdByURI(appURI.c_str());
	std::cout << "AppId: '" << appId << "' got '" << socket->getRequestBody().str() << "' request" << std::endl;
}
