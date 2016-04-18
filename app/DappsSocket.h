#ifndef __dapps_DAPPS_SOCKET__
#define __dapps_DAPPS_SOCKET__

#include "DappsServer.h"
#include "../commons/sockets/AbstractClientSocket.h"

namespace dapps
{
	class DappsSocket : public AbstractClientSocket
	{
		DappsServer* m_dappsServer;
		Buffer m_buffer;
		std::size_t m_reqBodyLen;
		
		public:
			DappsSocket(DappsServer*);
			~DappsSocket();
			void write(char*, std::size_t);
			void feed(const char*, ssize_t);
			void cleanup();
			void parseLength(const char*, ssize_t);
	};
}

#endif //__dapps_DAPPS_SOCKET__
