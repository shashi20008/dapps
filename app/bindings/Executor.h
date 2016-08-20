#ifndef __dapps_EXECUTOR__
#define __dapps_EXECUTOR__

#include <string>
#include "../DappsApplication.h"
#include "../../commons/containers/JSONTypes.h"

namespace dapps
{
	class Executor
	{
		public:
			~Executor();
			virtual void execute(DappsApplication*, JSON_t*, std::string) = 0;
			static Executor* create(std::string);
	};
}

#endif //__dapps_EXECUTOR__
