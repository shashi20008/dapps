#include "RegistryServer.h"
#include <map>
#include "../utilities/StringUtils.h"

dapps::RegistryServer::RegistryServer(dapps::Dapps* _app) {
	this->m_app = _app;
	ServerSetup();
}

dapps::RegistryServer::~RegistryServer() {
	std::cout << "registryServer destructor executed" << std::endl;
}

void dapps::RegistryServer::ServerSetup() {
	m_loop = uv_default_loop();

	m_server = (uv_tcp_t*) malloc(sizeof(uv_tcp_t));
    uv_tcp_init(m_loop, m_server);

    // Save current object reference for use in callbacks
    m_server->data = this;
    uv_ip4_addr("0.0.0.0", 8080, &m_addr);
	uv_tcp_bind(m_server, (const struct sockaddr*)&m_addr, 0);
  
    int r = uv_listen((uv_stream_t*) m_server, 1, this->OnNewConnection);
    if (r) {
        fprintf(stderr, "Listen error %s\n", uv_strerror(r));
    }
    uv_run(m_loop, UV_RUN_DEFAULT);
}

void dapps::RegistryServer::OnNewConnection(uv_stream_t *server, int status) {
	// TODO: validate that _this is not null
	RegistryServer* _this = (RegistryServer*) server->data;

    if (status < 0) {
        fprintf(stderr, "New connection error %s\n", uv_strerror(status));
        return;
    }

    uv_tcp_t* client = (uv_tcp_t*) malloc(sizeof(uv_tcp_t));
    
    client->data = server->data;
    std::string message = "Hello from Server!";
    uv_tcp_init(_this->m_loop, client);
    if (uv_accept(server, (uv_stream_t*) client) == 0) {
        uv_read_start((uv_stream_t*) client, AllocBuffer, OnClientRead);
        writeData((uv_stream_t*) server, (uv_stream_t*) client, message);
    }
}

void dapps::RegistryServer::OnClientRead(uv_stream_t* _client, ssize_t nread, const uv_buf_t* buf) {
	// TODO: validate that _this is not null
	RegistryServer* _this = (RegistryServer*) _client->data;
  if (nread == -1) {
    fprintf(stderr, "error on_client_read");
    uv_close((uv_handle_t*) _client, NULL);
    return;
  }
  std::string str = buf->base;
  std::cout<<str.c_str()<< "::length::" <<str.length() <<std::endl; 
  str = dapps::StringUtils::trim(str);
  //if(str == std::string("hello\r\n"))
  if(str!= "\r\n")
  {
  	std::map<std::string, std::string> testData;

   	testData["hello"] = "Hi";
	testData["how are you?"] = "I am good, how are you?";
	
  	std::string message = testData[str];

  	writeData((uv_stream_t*) _this->m_server, (uv_stream_t*) _client, message);
  }
}

void dapps::RegistryServer::AllocBuffer(uv_handle_t* handle,size_t suggested_size,uv_buf_t* buf) {
	buf->base = (char*) malloc(suggested_size);
	buf->len = suggested_size;
}

void dapps::RegistryServer::writeData(uv_stream_t* server, uv_stream_t* _client, std::string message){
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

void dapps::RegistryServer::onClientWrite(uv_write_t *req, int status) {
	uv_tcp_t *client = (uv_tcp_t*) malloc(sizeof(uv_tcp_t));
	if (status == -1) {
		fprintf(stderr, "error on_client_write");
		uv_close((uv_handle_t*) client, NULL);
		return;
	}
}








