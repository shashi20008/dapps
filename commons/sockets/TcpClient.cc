#include "TcpClient.h"
#include "AbstractClientSocket.h"
#include "../../registry/RegistryRequestProcessor.h"
#include <iostream>
#include <cstdlib>

dapps::TcpClient::~TcpClient()
{

}

dapps::TcpClient::TcpClient(DappsContext* context, std::string ip, int port, Buffer buffer)
{
	m_ip = ip;
	m_port = port;
	m_buffer = buffer;
	m_context = context;
	
	uv_loop_t* loop = uv_default_loop();
	uv_tcp_t* client = (uv_tcp_t*) malloc(sizeof(uv_tcp_t));
	client->data = (void*) this;
	
	uv_tcp_init(loop, client);
	
	sockaddr_in req_addr;
	uv_ip4_addr(m_ip.c_str(), m_port, &req_addr);
	
	uv_connect_t* connect_req = (uv_connect_t*) malloc(sizeof(uv_connect_t));
	connect_req->data = (void*) this;
	uv_tcp_connect(connect_req, client, (const sockaddr*) &req_addr, on_connect);
	
}

void dapps::TcpClient::on_connect(uv_connect_t *req, int status) {
	if (status < 0) {
		std::cout<<"Error:: " << uv_strerror(status) << std::endl;
		return;
	}
	TcpClient* _this = (TcpClient*)req->data;
	std::size_t len = _this->m_buffer.size();

	//uv_buf_t* buff = (uv_buf_t*) malloc(sizeof(uv_buf_t));
    uv_buf_t buff = uv_buf_init(_this->m_buffer.c_str(), sizeof(m_buffer.c_str()));

	buff.len = len;
    buff.base = _this->m_buffer.c_str();

	uv_stream_t* tcp = req->handle;

	uv_write_t* write_req = (uv_write_t*) malloc(sizeof(uv_write_t));;
	int buff_count = 1;

	uv_write(write_req, tcp, &buff, buff_count, on_write_end);
}


void dapps::TcpClient::on_write_end(uv_write_t *req, int status) {
	if (status < 0) {
		std::cout<<"Error:: " << uv_strerror(status) << std::endl;
		return;
	}

	uv_read_start(req->handle, AbstractClientSocket::allocBuffer, on_read);
}

void dapps::TcpClient::on_read(uv_stream_t *server, ssize_t nread, const uv_buf_t* buf) {
	TcpClient* _this = (TcpClient*) server->data;
	if(nread == UV_EOF) {
		std::cout<<"result: " << _this->m_rcvBuffer.c_str() << std::endl;
		RegistryRequestProcessor* _processor = RegistryRequestProcessor::get();
		_processor->finishRequest(_this->m_context, _this->m_rcvBuffer);

		return;
	}
	if (nread < 0) {
		std::cout<<"Error:: " << uv_strerror(nread) << std::endl;
		return;
	}
	_this->m_rcvBuffer.append(buf->base,buf->len);	
	
}

