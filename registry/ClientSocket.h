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
#include "../utilities/LoggingUtil.h"

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
		public:
			ClientSocket(RegistryServer*);
			~ClientSocket();
			void write(char*);
			static void writeData(uv_stream_t*, uv_stream_t*, std::string);
			static void onClientRead(uv_stream_t*, ssize_t , const uv_buf_t*);
			static void onClientWrite(uv_write_t*, int);
			static void allocBuffer(uv_handle_t*, size_t, uv_buf_t*);
	};
}
#endif //__ClientSocket__
