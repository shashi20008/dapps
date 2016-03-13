#include "ClientSocket.h"
#include "../commons/utilities/StringUtils.h"
#include "RegistryRequestProcessor.h"
#include <map>

dapps::ClientSocket::ClientSocket(dapps::RegistryServer* _registryServer) 
{
	m_context = new DappsContext(this);
	m_httpSocket =  new HttpSocket(m_context, this , RegistryRequestProcessor::get());
	
	m_registryServer = _registryServer;
	m_logger = m_registryServer->m_logger;
	
	m_client = (uv_tcp_t*) malloc(sizeof(uv_tcp_t));
	m_stringBuffer = new std::string();

	m_client->data = m_context;
	
	uv_tcp_init(m_registryServer->getLoop(), m_client);
	if (uv_accept((uv_stream_t*) m_registryServer->getServer(), (uv_stream_t*) m_client) == 0) {
		uv_read_start((uv_stream_t*) m_client, allocBuffer, onClientRead);
	}
}

dapps::ClientSocket::~ClientSocket() {
	std::cout << "ClientSocket destructor executed" << std::endl;
}

void dapps::ClientSocket::write(char* buffer, std::size_t length)
{
	uv_write_t* writeReq;
	uv_buf_t* uvBuffer;
	writeReq = (uv_write_t*) malloc(sizeof(uv_write_t));
	uvBuffer = (uv_buf_t*) malloc(sizeof(uv_buf_t));
	
	writeReq->data = m_context;
	
	uvBuffer->base = buffer;
	uvBuffer->len = length;
	uv_write(writeReq, (uv_stream_t*)m_client, uvBuffer, 1, onWriteComplete);
}

void dapps::ClientSocket::onClientRead(uv_stream_t* _client, ssize_t nread, const uv_buf_t* buf) {
	// EAGAIN
	if(nread == 0)
	{
		return;
	}
	// EOF
	else if (nread == UV_EOF)
	{
		// Client cancelled the request.
		// @TODO: clean everything up.
		// @TODO: cancel all pending callbacks and operations.
		std::cout << "Client cancelled the request." << std::endl;
		return;
	}
	// Error 
	else if (nread < 0) 
	{
		fprintf(stderr, "error on_client_read, %s\n", uv_strerror(nread));
		uv_close((uv_handle_t*) _client, NULL);
		return;
	}
	
	ClientSocket* _this = (ClientSocket*)((DappsContext*) _client->data)->getThis();
	_this->m_httpSocket->feed(buf->base, nread);
	
	// free the buffer space. UV won't re-use it.
	free(buf->base);
}

void dapps::ClientSocket::allocBuffer(uv_handle_t* handle,size_t suggested_size,uv_buf_t* buf) {
	buf->base = (char*) malloc(suggested_size);
	buf->len = suggested_size;
}

void dapps::ClientSocket::onWriteComplete(uv_write_t* writeReq, int status) {
	ClientSocket* _this = (ClientSocket*)((DappsContext*) writeReq->data)->getThis();
	if (status < 0) {
		fprintf(stderr, "error on_client_write");
		// @TODO: if the connection is not stale yet, retry write once more.
	}
	uv_close((uv_handle_t*) _this->m_client, onSocketClose);
}

void dapps::ClientSocket::onSocketClose(uv_handle_t* _handle)
{
	// @TODO: connection closed. Cleanup.
}
