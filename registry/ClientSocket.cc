#include "ClientSocket.h"
#include "../commons/utilities/StringUtils.h"
#include "RegistryRequestProcessor.h"
#include "../app/bindings/Executor.h"
#include <map>

dapps::ClientSocket::ClientSocket(dapps::RegistryServer* _registryServer) 
{
	m_context = new DappsContext(this);
	m_httpSocket =  new HttpSocket(m_context, this , RegistryRequestProcessor::get());
	m_context->put("httpSocket", m_httpSocket);
	
	m_registryServer = _registryServer;
	m_logger = m_registryServer->m_logger;
	
	m_client = (uv_tcp_t*) malloc(sizeof(uv_tcp_t));

	m_client->data = m_context;
	
	uv_tcp_init(m_registryServer->getLoop(), m_client);
	if (uv_accept((uv_stream_t*) m_registryServer->getServer(), (uv_stream_t*) m_client) == 0) {
		uv_read_start((uv_stream_t*) m_client, allocBuffer, onClientRead);
	}
}

dapps::ClientSocket::~ClientSocket() {
	free(m_client);
	Executor* _executor = (Executor*)m_context->get("executor");
	delete _executor;
	delete m_httpSocket;
	delete m_context;
	std::cout << "ClientSocket destructor executed" << std::endl;
}

void dapps::ClientSocket::write(char* buffer, std::size_t length)
{
	uv_write_t* writeReq;
	uv_buf_t* uvBuffer;
	writeReq = (uv_write_t*) malloc(sizeof(uv_write_t));
	uvBuffer = (uv_buf_t*) malloc(sizeof(uv_buf_t));
	
	writeReq->data = buffer;
	
	uvBuffer->base = buffer;
	uvBuffer->len = length;
	uv_write(writeReq, (uv_stream_t*)m_client, uvBuffer, 1, onWriteComplete);
	std::cout << "write request put" <<std::endl;
	free(uvBuffer);
}

void dapps::ClientSocket::feed(const char* buf, ssize_t size)
{
	this->m_httpSocket->feed(buf, size);
}

void dapps::ClientSocket::cleanup()
{
	std::cout << "came to cleanup" << std::endl;
	m_registryServer->cleanupConn(this);
}
