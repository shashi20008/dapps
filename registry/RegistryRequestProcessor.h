#ifndef __dapps_REGISTRY_REQUEST_PROCESSOR__
#define __dapps_REGISTRY_REQUEST_PROCESSOR__

#include "../commons/containers/DappsContext.h"
#include "../commons/http/HttpSocket.h"
#include "../commons/http/AbstractHttpClient.h"

namespace dapps
{
	class RegistryRequestProcessor : public AbstractHttpClient
	{
		private:
			static RegistryRequestProcessor* m_self;
			RegistryRequestProcessor();
			
		public:
			static RegistryRequestProcessor* get();
			void process(DappsContext*, HttpSocket*);
			
	};
}

#endif //__dapps_REGISTRY_REQUEST_PROCESSOR__
