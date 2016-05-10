#ifndef __dapps_CGI_EXECUTOR__
#define __dapps_CGI_EXECUTOR__

#include "Executor.h"
#include "../../commons/containers/Buffer.h"
#include "uv.h"

namespace dapps
{
	class CgiExecutor : public Executor
	{
		uv_pipe_t* m_outputPipe;
		uv_process_options_t* m_process_options;
		Buffer m_output;
		DappsSocket* m_socket;
		JSON_t* m_request;
		
		void initializeProcessOptions(uv_process_options_t*, dapps::DappsApplication*, std::string);
		static void allocBuffer(uv_handle_t*,size_t,uv_buf_t*);
		static void onRead(uv_stream_t*, ssize_t, const uv_buf_t*);
		static void onExit(uv_process_t*, int64_t, int);
		static void cleanup(uv_handle_t*);
		public:
			CgiExecutor();
			~CgiExecutor();
			void execute(DappsApplication*, DappsSocket*, JSON_t*, std::string);
	};
}

#endif //__dapps_CGI_EXECUTOR__
