#ifndef __dapps_ABSTRACT_HTTP_CLIENT__
#define __dapps_ABSTRACT_HTTP_CLIENT__

#include "../../dapps-common.h"
#include "HttpSocket.h"

namespace dapps
{
	class AbstractHttpClient
	{
		public:
			virtual void process(HttpSocket*) = 0;
	};
}

#endif //__dapps_ABSTRACT_HTTP_CLIENT__
