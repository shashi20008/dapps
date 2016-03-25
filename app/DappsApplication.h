#ifndef __dapps_DAPPS_APPLICATION__
#define __dapps_DAPPS_APPLICATION__

#include "../commons/containers/JSONTypes.h"
#include "../utilities/ConfigProcessor.h"
#include <string>

namespace dapps
{
	class DappsApplication
	{
		std::string m_appPath;
		ConfigProcessor* m_appConfig;
		std::string m_appExecutableName;
		std::string m_appType;
		std::string m_appName;
		
		void loadConfig();
		
		public:
			DappsApplication(std::string);
			std::string getAppPath();
			ConfigProcessor* getAppConfig();
			std::string getAppExecutableName();
			std::string getAppType();
			std::string getAppName();
			
			const static std::string DAPPS_CONFIG_FILENAME;
	};
}

#endif //__dapps_DAPPS_APPLICATION__
