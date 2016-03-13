#ifndef __dapps_ABSTRACT_HTTP_CLIENT__
#define __dapps_ABSTRACT_HTTP_CLIENT__

#include "../dapps-commons.h"
#include "HttpSocket.h"
#include "../containers/DappsContext.h"

namespace dapps
{
	class AbstractHttpApplication
	{
		public:
			virtual void process(DappsContext*, HttpSocket*) = 0;
	};
}

#endif //__dapps_ABSTRACT_HTTP_CLIENT__
