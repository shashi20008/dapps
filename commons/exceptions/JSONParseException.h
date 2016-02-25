#ifndef __dapps_JSON_PARSE_EXCEPTION__
#define __dapps_JSON_PARSE_EXCEPTION__

#include "DappsException.h"

namespace dapps
{
	class JSONParseException : public DappsException
	{
		public:
			JSONParseException(std::string msg);
			~JSONParseException() throw();
	};
}

#endif
