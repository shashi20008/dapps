#ifndef __RegistryServer__
#define __RegistryServer__

#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <uv.h>
// #include <string>
// #include <map>
// #include <vector>

namespace dapps
{
	class RegistryServer
	{
		private:
			uv_loop_t* loop;
			uv_tcp_t* server;
			//uv_tcp_t *client;
			struct sockaddr_in addr;

		public:
			RegistryServer();
			~RegistryServer();
			void ServerSetup();
			static void OnNewConnection(uv_stream_t*, int);
			static void OnClientRead(uv_stream_t*, ssize_t , const uv_buf_t*);
			static void AllocBuffer(uv_handle_t*, size_t, uv_buf_t*);
	};
}
#endif //__RegistryServer__
