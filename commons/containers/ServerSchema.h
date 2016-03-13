#ifndef __dapps_ServerSchema__
#define __dapps_ServerSchema__

#include <string>
#include <map>
#include <bson.h>

namespace dapps
{
	class ServerSchema
	{
		private:
			std::map <std::string, void*> serverMap;
		public:
			static ServerSchema* getDocument(const bson_t*);
			std::string getIp();
			std::string getPort();
			
	};
}

#endif //__ServerSchema__
