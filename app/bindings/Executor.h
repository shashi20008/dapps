#ifndef __dapps_EXECUTOR__
#define __dapps_EXECUTOR__

#include <string>
#include "../DappsApplication.h"

namespace dapps
{
	class Executor
	{
		public:
			~Executor();
			virtual void execute(DappsApplication*, std::string args) = 0;
	};
}

#endif //__dapps_EXECUTOR__
