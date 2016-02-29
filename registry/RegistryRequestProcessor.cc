#include "RegistryRequestProcessor.h"

dapps::RegistryRequestProcessor::RegistryRequestProcessor(dapps::DappsContext* _context, dapps::HttpSocket* _socket)
{
	m_context = _context;
	m_httpSocket  = _socket;
}
