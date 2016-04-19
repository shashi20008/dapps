#ifndef __dapps_ABSTRACT_CLIENT_SOCKET__
#define __dapps_ABSTRACT_CLIENT_SOCKET__

#include <cstddef>
#include <uv.h>
#include "../containers/DappsContext.h"
#include "../http/HttpSocket.h"

namespace dapps
{
	class AbstractClientSocket
	{
		protected:
			DappsContext* m_context; 
			uv_tcp_t* m_client;
		public:
			virtual ~AbstractClientSocket();
			virtual void write(char*, std::size_t) = 0;
			virtual void feed(const char*, ssize_t) = 0;
			virtual void cleanup() = 0;
			static void onClientRead(uv_stream_t*, ssize_t , const uv_buf_t*);
			static void onWriteComplete(uv_write_t*, int);
			static void allocBuffer(uv_handle_t*, size_t, uv_buf_t*);
			static void onSocketClose(uv_handle_t*);
	};
}

#endif //__dapps_ABSTRACT_CLIENT_SOCKET__
