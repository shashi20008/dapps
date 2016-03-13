#ifndef __ClientSocket__
#define __ClientSocket__

#include <string>
#include <cstring>
#include <iostream>
#include <stdlib.h>
#include <uv.h>
#include <fstream>
#include "RegistryServer.h"
#include "../commons/sockets/AbstractClientSocket.h"
#include "../commons/containers/DappsContext.h"
#include "../commons/http/HttpSocket.h"
#include "../commons/utilities/LoggingUtil.h"

namespace dapps
{
	class ClientSocket : public AbstractClientSocket
	{
		public:
			LoggingUtil* m_logger;
			
		private:
			DappsContext* m_context;
			uv_tcp_t* m_client;
			RegistryServer* m_registryServer;
			std::string* m_stringBuffer;
			HttpSocket* m_httpSocket;
		public:
			ClientSocket(RegistryServer*);
			~ClientSocket();
			void write(char*, std::size_t);
			static void onClientRead(uv_stream_t*, ssize_t , const uv_buf_t*);
			static void onWriteComplete(uv_write_t*, int);
			static void allocBuffer(uv_handle_t*, size_t, uv_buf_t*);
			static void onSocketClose(uv_handle_t*);
	};
}
#endif //__ClientSocket__
