#ifndef __RegistryServer__
#define __RegistryServer__

#include <string>
#include <cstring>
#include <iostream>
#include <stdlib.h>
#include <uv.h>
#include <fstream>
// #include <string>
// #include <map>
// #include <vector>

namespace dapps
{
	class RegistryServer
	{
		private:
			uv_loop_t* m_loop;
			uv_tcp_t* m_server;
			//uv_tcp_t *client;
			struct sockaddr_in m_addr;

		public:
			RegistryServer();
			~RegistryServer();
			void ServerSetup();
			static void writeData(uv_stream_t*, uv_stream_t*, std::string);
			static void OnNewConnection(uv_stream_t*, int);
			static void OnClientRead(uv_stream_t*, ssize_t , const uv_buf_t*);
			static void onClientWrite(uv_write_t*, int);
			static void AllocBuffer(uv_handle_t*, size_t, uv_buf_t*);
	};
}
#endif //__RegistryServer__
