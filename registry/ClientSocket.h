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
			RegistryServer* m_registryServer;
			HttpSocket* m_httpSocket;
		public:
			ClientSocket(RegistryServer*);
			~ClientSocket();
			void write(char*, std::size_t);
			void feed(const char*, ssize_t);
	};
}
#endif //__ClientSocket__
