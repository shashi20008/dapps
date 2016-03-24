#ifndef __dapps__DAPPS_REQUEST_PROCESSOR__
#define __dapps__DAPPS_REQUEST_PROCESSOR__

#include "../commons/containers/JSONTypes.h"
#include "DappsSocket.h"

namespace dapps
{
	class DappsRequestProcessor
	{
		static DappsRequestProcessor* m_self;
		
		public:
			static DappsRequestProcessor* get();
			void process(JSON_t*, DappsSocket*);
	};
}

#endif //__dapps__DAPPS_REQUEST_PROCESSOR__
