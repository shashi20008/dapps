#include "OutOfBoundsException.h"

dapps::OutOfBoundsException::OutOfBoundsException(std::string msg) : DappsException(msg)
{
}

dapps::OutOfBoundsException::~OutOfBoundsException() throw()
{
}
