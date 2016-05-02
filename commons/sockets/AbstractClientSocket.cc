#include "AbstractClientSocket.h"
#include <cstdlib>
#include <iostream>

dapps::AbstractClientSocket::~AbstractClientSocket()
{
}

void dapps::AbstractClientSocket::onClientRead(uv_stream_t* _client, ssize_t nread, const uv_buf_t* buf) {
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
	
	AbstractClientSocket* _this = (AbstractClientSocket*)((DappsContext*) _client->data)->getThis();
	_this->feed(buf->base, nread);
	
	// free the buffer space. UV won't re-use it.
	free(buf->base);
}

void dapps::AbstractClientSocket::allocBuffer(uv_handle_t* handle,size_t suggested_size,uv_buf_t* buf) {
	buf->base = (char*) malloc(suggested_size);
	buf->len = suggested_size;
}

void dapps::AbstractClientSocket::onWriteComplete(uv_write_t* writeReq, int status) {
	if (status < 0) {
		fprintf(stderr, "error on_client_write");
		// @TODO: if the connection is not stale yet, retry write once more.
	}

	delete[] ((char*)writeReq->data);
	free(writeReq);
	uv_close((uv_handle_t*) writeReq->handle, onSocketClose);
}

void dapps::AbstractClientSocket::onSocketClose(uv_handle_t* _handle)
{
	AbstractClientSocket* _this = (AbstractClientSocket*) ((DappsContext*)_handle->data)->getThis();
	std::cout << "gonna call cleanup" <<std::endl;
	_this->cleanup();
}
