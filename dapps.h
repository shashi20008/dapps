#ifndef __dapps__
#define __dapps__

#include "utilities/ArgsProcessor.h"
#include "registry/RegistryServer.h"

namespace dapps
{
	// Satisfy compiler
	class Dapps;

	class Dapps
	{
		public:
			ArgsProcessor* args;
			RegistryServer* registry;
	};
}
#endif //__dapps__
