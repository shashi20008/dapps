#ifndef __dapps_DAPPS_APPLICATION_FACTORY__
#define __dapps_DAPPS_APPLICATION_FACTORY__

#include "DappsApplication.h"
#include <map>
#include <uv.h>

namespace dapps
{
	typedef std::map<std::string, DappsApplication*> ApplicationsMap;
	typedef std::pair<std::string, DappsApplication*> ApplicationsPair;
	
	class DappsApplicationFactory
	{
		static bool m_initialized;
		static std::string m_deploymentDir;
		static ApplicationsMap* m_applications;
		
		static void scanForApplications();
		static void onScan(uv_fs_t*);
		
		public:
			static void initialize(std::string);
			static DappsApplication* getApp(std::string);
	};
}

#endif //__dapps_DAPPS_APPLICATION_FACTORY__
