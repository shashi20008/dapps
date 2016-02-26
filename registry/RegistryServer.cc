#include "RegistryServer.h"
#include "ClientSocket.h"

dapps::RegistryServer::RegistryServer(dapps::Dapps* _app) 
{
	this->m_app = _app;
	this->m_logger = m_app->loggingUtil;
	serverSetup();
}

dapps::RegistryServer::~RegistryServer() 
{
	std::cout << "registryServer destructor executed" << std::endl;
}

void dapps::RegistryServer::serverSetup() 
{
	m_loop = uv_default_loop();

	m_server = (uv_tcp_t*) malloc(sizeof(uv_tcp_t));
	uv_tcp_init(m_loop, m_server);

	// Save current object reference for use in callbacks
	m_server->data = this;
	uv_ip4_addr("0.0.0.0", 8080, &m_addr);
	uv_tcp_bind(m_server, (const struct sockaddr*)&m_addr, 0);

	int r = uv_listen((uv_stream_t*) m_server, 1, this->onNewConnection);
	if (r) {
	fprintf(stderr, "Listen error %s\n", uv_strerror(r));
	}
	m_logger->log("Server listening\r\n");
	uv_run(m_loop, UV_RUN_DEFAULT);
}

void dapps::RegistryServer::rejectIncomingConnection(uv_stream_t* server)
{
	uv_tcp_t* _client = (uv_tcp_t*) malloc(sizeof(uv_tcp_t));
	uv_tcp_init(server->loop, _client);
	if (uv_accept(server, (uv_stream_t*) _client) == 0)
	{
		uv_close((uv_handle_t*)_client, onRejectConnection);
	}
}

void dapps::RegistryServer::onRejectConnection(uv_handle_t* _handle)
{
	free(_handle);
}

void dapps::RegistryServer::onNewConnection(uv_stream_t* server, int status) 
{
	// TODO: validate that _this is not null
	RegistryServer* _this = (RegistryServer*) server->data;
	if(_this == NULL)
	{
		std::cerr << "Invalid context passed to callback. Rejecting..\r\n";
		// What else can we do? This is 'C'.. 
		// Let's just reject this connection.
		RegistryServer::rejectIncomingConnection(server);
		return;
	}
	
	if (status < 0) {
		fprintf(stderr, "New connection error %s\n", uv_strerror(status));
		return;
	}
	ClientSocket* clientObject =  new ClientSocket(_this);
}

dapps::Dapps* dapps::RegistryServer::getApp() 
{
	return m_app;
}

uv_loop_t* dapps::RegistryServer::getLoop() 
{
	return m_loop;
}

uv_tcp_t* dapps::RegistryServer::getServer() 
{
	return m_server;
}









