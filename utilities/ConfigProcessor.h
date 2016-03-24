#ifndef __dapps_CONFIG_PROCESSOR__
#define __dapps_CONFIG_PROCESSOR__

#include "../commons/json/JSON.h"

namespace dapps
{
	class ConfigProcessor
	{
		private:
			JSON_t* m_config;
		public:
			ConfigProcessor(std::string filename);
			
	};
}

#endif //__dapps_CONFIG_PROCESSOR__
