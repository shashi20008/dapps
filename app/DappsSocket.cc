#include "DappsSocket.h"
#include "../commons/utilities/StringUtils.h"

dapps::DappsSocket::DappsSocket(DappsServer* _dappsServer)
{
	m_dappsServer = _dappsServer;
	m_context = new DappsContext(this);
	m_reqBodyLen = 0;
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

void dapps::DappsSocket::parseLength(const char* buf, ssize_t size)
{
	ssize_t i;
	for(i = 0; i < size; i++)
	{
		m_buffer.append(buf[i]);
		if(m_buffer.endsWith("\r\n"))
		{
			std::string lenStr = m_buffer.str();
			lenStr = lenStr.substr(0, lenStr.length() - 2);
			StringUtils::fromString(lenStr, &m_reqBodyLen);
			m_buffer.clear();
			
			if(m_reqBodyLen == 0)
			{
				// @TODO: return error response.
				throw DappsException("Invalid request body length");
			}
		}
	}
	if(i < size)
	{
		feed(buf + i, size - i);
	}
}

void dapps::DappsSocket::feed(const char* buf, ssize_t size)
{
	if(!m_reqBodyLen)
	{
		parseLength(buf, size);
	}
	else
	{
		m_buffer.append(buf, 0, size);
		
		// @TODO: Implement a setLength so that extra bytes can be ignored.
		if(m_buffer.size() >= m_reqBodyLen)
		{
			std::cout << "Got entire request of " << m_buffer.size() << std::endl;
		}
	}
}
