#include "DappsRequestProcessor.h"

dapps::DappsRequestProcessor* dapps::DappsRequestProcessor::m_self = NULL;
dapps::DappsRequestProcessor* dapps::DappsRequestProcessor::get()
{
	if(m_self == NULL)
	{
		m_self = new DappsRequestProcessor();
	}
	return m_self;
}

void dapps::DappsRequestProcessor::process(dapps::JSON_t* request, dapps::DappsSocket* socket)
{
}
