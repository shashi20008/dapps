#ifndef __RegistryServer__
#define __RegistryServer__

#include <string>
#include <cstring>
#include <iostream>
#include <stdlib.h>
#include <uv.h>
#include <fstream>
#include "../dapps.h"

namespace dapps
{
	class RegistryServer
	{
		private:
			Dapps* m_app;
			uv_loop_t* m_loop;
			uv_tcp_t* m_server;
			//uv_tcp_t *client;
			struct sockaddr_in m_addr;

		public:
			RegistryServer(Dapps* );
			~RegistryServer();
			void serverSetup();
			static void onNewConnection(uv_stream_t*, int);
			Dapps* getApp();
			uv_loop_t* getLoop();
			uv_tcp_t* getServer();

	};
}
#endif //__RegistryServer__
