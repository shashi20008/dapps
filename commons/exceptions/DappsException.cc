#include "DappsException.h"

dapps::DappsException::DappsException(std::string m) : message(m)
{
}

dapps::DappsException::~DappsException() throw()
{
}

const char* dapps::DappsException::what() const throw()
{
	return message.c_str();
}
