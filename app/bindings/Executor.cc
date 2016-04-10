#include "Executor.h"
#include "CgiExecutor.h"

dapps::Executor::~Executor()
{
}

dapps::Executor* dapps::Executor::create(std::string _type)
{
	if(_type == "CGI")
	{
		return new CgiExecutor();
	}
	else
	{
		return NULL;
	}
}
