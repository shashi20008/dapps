#ifndef __dapps_OUT_OF_BOUNDS_EXCEPTION__
#define __dapps_OUT_OF_BOUNDS_EXCEPTION__

#include "DappsException.h"
#include <string>

namespace dapps
{
	class OutOfBoundsException : public DappsException
	{
		public:
			OutOfBoundsException(std::string);
			~OutOfBoundsException() throw();
	};
}

#endif //__dapps_OUT_OF_BOUNDS_EXCEPTION__
