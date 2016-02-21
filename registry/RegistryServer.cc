#include "RegistryServer.h"

dapps::RegistryServer::RegistryServer() {
	ServerSetup();
}

dapps::RegistryServer::~RegistryServer() {
	std::cout << "registryServer destructor executed" << std::endl;
}

void dapps::RegistryServer::ServerSetup() {
	loop = uv_default_loop();

	server = (uv_tcp_t*) malloc(sizeof(uv_tcp_t));
    uv_tcp_init(loop, server);

    // Save current object reference for use in callbacks
    server->data = this;
    uv_ip4_addr("0.0.0.0", 8080, &addr);
	uv_tcp_bind(server, (const struct sockaddr*)&addr, 0);
  
    int r = uv_listen((uv_stream_t*) server, 1, this->OnNewConnection);
    if (r) {
        fprintf(stderr, "Listen error %s\n", uv_strerror(r));
    }
    uv_run(loop, UV_RUN_DEFAULT);
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
    uv_tcp_init(_this->loop, client);
    if (uv_accept(server, (uv_stream_t*) client) == 0) {
        uv_read_start((uv_stream_t*) client, AllocBuffer, OnClientRead);
    } else {
        uv_close((uv_handle_t*) client, NULL);
    }
}

void dapps::RegistryServer::OnClientRead(uv_stream_t *_client, ssize_t nread, const uv_buf_t* buf) {
  if (nread == -1) {
    fprintf(stderr, "error on_client_read");
    uv_close((uv_handle_t*) _client, NULL);
    return;
  }
  std::cout << "reading client"<<std::endl;
  std::cout<<buf->base<<std::endl; 
}

void dapps::RegistryServer::AllocBuffer(uv_handle_t* handle,size_t suggested_size,uv_buf_t* buf) {
	buf->base = (char*) malloc(suggested_size);
	buf->len = suggested_size;
}







