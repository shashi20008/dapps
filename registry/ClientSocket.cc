#include "ClientSocket.h"
#include "../utilities/StringUtils.h"
#include <map>

dapps::ClientSocket::ClientSocket(dapps::RegistryServer* _registryServer) 
{
	m_registryServer = _registryServer;
	m_client = (uv_tcp_t*) malloc(sizeof(uv_tcp_t));
	m_stringBuffer = new std::string();

	m_client->data = (void*) this;
	uv_tcp_init(m_registryServer->getLoop(), m_client);
	if (uv_accept((uv_stream_t*) m_registryServer->getServer(), (uv_stream_t*) m_client) == 0) {
		uv_read_start((uv_stream_t*) m_client, allocBuffer, onClientRead);
	}
}

dapps::ClientSocket::~ClientSocket() {
	std::cout << "ClientSocket destructor executed" << std::endl;
}

void dapps::ClientSocket::onClientRead(uv_stream_t* _client, ssize_t nread, const uv_buf_t* buf) {
	// TODO: validate that _this is not null
	ClientSocket* _this = (ClientSocket*) _client->data;
	if (nread == -1) {
		fprintf(stderr, "error on_client_read");
		uv_close((uv_handle_t*) _client, NULL);
		return;
	}
	std::string str = buf->base;
	std::cout<<str.c_str()<< "::length::" <<str.length() <<std::endl; 
	//str = dapps::StringUtils::trim(str);
	_this->m_stringBuffer->append(str);

	if(str.find("\r\n\r\n") != std::string::npos)
	{
		std::cout << "done:: " << _this->m_stringBuffer->c_str() << std::endl;
	}
}

void dapps::ClientSocket::allocBuffer(uv_handle_t* handle,size_t suggested_size,uv_buf_t* buf) {
	buf->base = (char*) malloc(suggested_size);
	buf->len = suggested_size;
}

void dapps::ClientSocket::writeData(uv_stream_t* server, uv_stream_t* _client, std::string message){
	RegistryServer* _this = (RegistryServer*) server->data;
	uv_write_t *write_req = (uv_write_t *) malloc(sizeof(uv_write_t));
	    
	//std::string message = "hello from server \r\n";
	// TODO: unallocate buffer on callback.
	uv_buf_t* buf = (uv_buf_t*)malloc(message.length());
	buf->len = message.length();
	buf->base = (char*) malloc(buf->len);
	std::strcpy(buf->base, message.c_str());

	int buf_count = 1;

	write_req->data = (void*) _this;
	std::cout<<"going to execute uv_write"<<std::endl;
	uv_write(write_req, _client, buf, buf_count, onClientWrite);
}

void dapps::ClientSocket::onClientWrite(uv_write_t *req, int status) {
	uv_tcp_t *client = (uv_tcp_t*) malloc(sizeof(uv_tcp_t));
	if (status == -1) {
		fprintf(stderr, "error on_client_write");
		uv_close((uv_handle_t*) client, NULL);
		return;
	}
}