#ifndef __dapps_EXECUTOR__
#define __dapps_EXECUTOR__

#include <string>
#include "../DappsApplication.h"
#include "../../commons/containers/JSONTypes.h"
#include "../../commons/containers/DappsContext.h"

namespace dapps
{
	class Executor
	{
		public:
			virtual ~Executor();
			virtual void execute(DappsApplication*, DappsContext* _context, JSON_t*, std::string) = 0;
			static Executor* create(std::string);
	};
}

#endif //__dapps_EXECUTOR__
