#ifndef __dapps_ServerSchema__
#define __dapps_ServerSchema__

#include <string>
#include <bson.h>

namespace dapps
{
	class ServerSchema
	{
		private:
			std::string ip;
			int port;
		public:
			static ServerSchema* getDocument(const bson_t*);
			std::string getIp();
			int getPort();
			
	};
}

#endif //__ServerSchema__
