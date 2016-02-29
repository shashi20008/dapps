#ifndef __dapps_REGISTRY_REQUEST_PROCESSOR__
#define __dapps_REGISTRY_REQUEST_PROCESSOR__

#include "../commons/containers/DappsContext.h"
#include "../commons/http/HttpSocket.h"

namespace dapps
{
	class RegistryRequestProcessor
	{
		private:
			DappsContext* m_context;
			HttpSocket* m_httpSocket;
			
		public:
			RegistryRequestProcessor(DappsContext*, HttpSocket*);
			
	};
}

#endif //__dapps_REGISTRY_REQUEST_PROCESSOR__
