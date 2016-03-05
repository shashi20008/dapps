#include "RegistryRequestProcessor.h"
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
}
