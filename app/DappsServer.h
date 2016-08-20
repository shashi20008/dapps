#ifndef __dapps_DAPPS_SERVER__
#define __dapps_DAPPS_SERVER__

#include "../dapps.h"

namespace dapps
{
	class DappsServer
	{
		Dapps* m_app;
		
		void init();
		
		public:
			DappsServer(Dapps*);
			~DappsServer();
			Dapps* getApp();
	};
}

#endif //__dapps_DAPPS_SERVER__
