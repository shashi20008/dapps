#ifndef __dapps_DAPPS_SERVER__
#define __dapps_DAPPS_SERVER__

#include "../dapps.h"
#include "uv.h"

namespace dapps
{
	class DappsServer
	{
		Dapps* m_app;
		uv_loop_t* m_loop;
		uv_tcp_t* m_server;
		struct sockaddr_in m_addr;
		
		void init();
		
		public:
			DappsServer(Dapps*);
			static void onNewConnection(uv_stream_t*, int);
			static void rejectIncomingConnection(uv_stream_t* server);
			static void onRejectConnection(uv_handle_t*);
			Dapps* getApp();
			uv_loop_t* getLoop();
			uv_tcp_t* getServer();
	};
}

#endif //__dapps_DAPPS_SERVER__
