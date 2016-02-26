#ifndef __RegistryServer__
#define __RegistryServer__

#include <string>
#include <cstring>
#include <iostream>
#include <stdlib.h>
#include <uv.h>
#include <fstream>
#include "../dapps.h"
#include "../utilities/LoggingUtil.h"

namespace dapps
{
	class RegistryServer
	{
		public:
			LoggingUtil* m_logger;
			
		private:
			Dapps* m_app;
			uv_loop_t* m_loop;
			uv_tcp_t* m_server;
			struct sockaddr_in m_addr;

		public:
			RegistryServer(Dapps* );
			~RegistryServer();
			void serverSetup();
			static void rejectIncomingConnection(uv_stream_t* server);
			static void onNewConnection(uv_stream_t*, int);
			static void onRejectConnection(uv_handle_t*);
			Dapps* getApp();
			uv_loop_t* getLoop();
			uv_tcp_t* getServer();

	};
}
#endif //__RegistryServer__
