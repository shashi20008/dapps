#include "CgiExecutor.h"
#include "../../commons/utilities/PathUtils.h"
#include "../../registry/RegistryRequestProcessor.h" // @FixMe: Undo this somehow
#include "../../commons/utilities/DappsErrors.h"
#include <cstdlib>
#include <iostream>

dapps::CgiExecutor::CgiExecutor()
{
}

dapps::CgiExecutor::~CgiExecutor()
{
}

void dapps::CgiExecutor::initializeProcessOptions(uv_process_options_t* options, dapps::DappsApplication* app, std::string args)
{
	char* execFile = PathUtils::join("./", app->getAppExecutableName().c_str());
	const char* path = app->getAppPath().c_str();
	
	uv_stdio_container_t* childStdio = (uv_stdio_container_t*)calloc(sizeof(uv_stdio_container_t), 3);
	childStdio[0].flags = UV_IGNORE;
	
	// Set pipe to capture stdout
	childStdio[1].flags = (uv_stdio_flags)(UV_CREATE_PIPE | UV_WRITABLE_PIPE);
	childStdio[1].data.stream = (uv_stream_t*) m_outputPipe;
	
	// Redirect child stderr to our stderr.
	childStdio[2].flags = UV_INHERIT_FD;
	childStdio[2].data.fd = 2;
	
	options->exit_cb = CgiExecutor::onExit;
    options->file = execFile; // @TODO: delete after use
    options->args = 0;
    options->env = 0;
    options->cwd = path;
    options->flags = 0;
    options->stdio_count = 3;
    options->stdio = childStdio;
    options->uid = 0;
    options->gid = 0;

    std::cout << path << std::endl;
    std::cout << execFile <<std::endl;
}

void dapps::CgiExecutor::execute(DappsApplication* app, DappsContext* _context, JSON_t* req, std::string args)
{
	m_request = req;
	m_context = _context;
	uv_loop_t* _loop = uv_default_loop();
	
	m_outputPipe = (uv_pipe_t*) malloc(sizeof(uv_pipe_t));
	uv_pipe_init(_loop, m_outputPipe, 1);
	m_outputPipe->data = (void*) this;
	
	uv_process_t* _processReq = (uv_process_t*) malloc(sizeof(uv_process_t));
	_processReq->data = (void*) this;
	
	m_process_options = (uv_process_options_t*) malloc(sizeof(uv_process_options_t));
	initializeProcessOptions(m_process_options, app, args);
	
	int r;
	if((r = uv_spawn(_loop, _processReq, m_process_options)))
	{
		std::cout << "Process creation error:: " << uv_strerror(r) << std::endl;
		this->m_output.append(DappsErrors::INVALID_EXECUTABLE_FOR_APP->getJSONString());
		RegistryRequestProcessor::get()->finishRequest(this->m_context, this->m_output);
		return;
	}
	uv_read_start((uv_stream_t*) m_outputPipe, allocBuffer, onRead);
}

void dapps::CgiExecutor::onRead(uv_stream_t* _pipe, ssize_t nread, const uv_buf_t* buf)
{
	if(nread > 0)
	{
		CgiExecutor* _this = (CgiExecutor*) _pipe->data;
		_this->m_output.append(buf->base, nread);
	}
	else if(nread == UV_EOF)
	{
		// Pipe closed..
		// Ignore. Process exit callback will be called soon.
	}
	else
	{
		std::cout << "an error occurred:: " << uv_strerror(nread) <<std::endl;
	}
	free(buf->base);
}

void dapps::CgiExecutor::allocBuffer(uv_handle_t* handle,size_t suggested_size,uv_buf_t* buf) 
{
	buf->base = (char*) malloc(suggested_size);
	buf->len = suggested_size;
}

void dapps::CgiExecutor::onExit(uv_process_t* processReq, int64_t exitStatus, int termSignal)
{
	CgiExecutor* _this = (CgiExecutor*) processReq->data;
	uv_read_stop((uv_stream_t*)_this->m_outputPipe);

	RegistryRequestProcessor::get()->finishRequest(_this->m_context, _this->m_output);
	//Cleanup
	free((void*)(_this->m_process_options->file));
	free(_this->m_process_options->stdio);
	free(_this->m_process_options);
	uv_close((uv_handle_t*) _this->m_outputPipe, cleanup);
	uv_close((uv_handle_t*) processReq, cleanup);
}

void dapps::CgiExecutor::cleanup(uv_handle_t* _handle)
{
	free(_handle);
}
