#include <cstddef>
#include <uv.h>
#include <string>
#include "../containers/Buffer.h"
#include "../containers/DappsContext.h"

namespace dapps
{
	class TcpClient
	{
		private:
			std::string m_ip;
			int m_port; 
			Buffer m_buffer;
			Buffer m_rcvBuffer;
			DappsContext* m_context;
		public:
			TcpClient(DappsContext*, std::string, int , Buffer );
			~TcpClient();
			static void on_connect(uv_connect_t* , int );
			static void on_write_end(uv_write_t* , int );
			static void on_read(uv_stream_t* , ssize_t , const uv_buf_t* );
	};
}
