#ifndef __dapps__
#define __dapps__

#include "dapps-common.h"
#include "utilities/ArgsProcessor.h"
#include "utilities/ConfigProcessor.h"
#include "registry/RegistryServer.h"
#include "app/DappsServer.h"
#include "commons/utilities/LoggingUtil.h"

namespace dapps
{
	class Dapps
	{
		static Dapps* m_self;
		Dapps();

		public:
			static Dapps* get();
			ArgsProcessor* args;
			ConfigProcessor* config; 
			RegistryServer* registry;
			DappsServer* appServer;
			LoggingUtil* loggingUtil;
	};
}
#endif //__dapps__
