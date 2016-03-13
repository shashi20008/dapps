#include "DappsSocket.h"

dapps::DappsSocket::DappsSocket(DappsServer* _dappsServer)
{
	m_dappsServer = _dappsServer;
	m_context = new DappsContext(this);
	m_client = (uv_tcp_t*) malloc(sizeof(uv_tcp_t));

	m_client->data = m_context;
	
	uv_tcp_init(m_dappsServer->getLoop(), m_client);
	if (uv_accept((uv_stream_t*) m_dappsServer->getServer(), (uv_stream_t*) m_client) == 0) {
		uv_read_start((uv_stream_t*) m_client, allocBuffer, onClientRead);
	}
}

dapps::DappsSocket::~DappsSocket()
{
	//@TODO: clean everything up
}

void dapps::DappsSocket::write(char* buffer, std::size_t length)
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

void dapps::DappsSocket::feed(const char* buf, ssize_t size)
{
}
