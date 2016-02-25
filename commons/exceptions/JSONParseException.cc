#include "JSONParseException.h"

dapps::JSONParseException::JSONParseException(std::string msg) : DappsException(msg)
{
	
}

dapps::JSONParseException::~JSONParseException() throw()
{
}
