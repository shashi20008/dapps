#ifndef __dapps_MONGO_CLIENT__
#define __dapps_MONGO_CLIENT__

#include <mongoc.h>
#include <bson.h>
#include <string>
#include "../containers/ServerSchema.h"
#include "../containers/JSONTypes.h"

namespace dapps
{
	// Singleton class.
	class MongoClient
	{
		private:
			mongoc_client_t* m_mongoClient;
			mongoc_collection_t* m_appsCollection;
			mongoc_collection_t* m_serversCollection;
			
			
		public:
			MongoClient();
			bson_t* getApplicationByURI(const char*);
			std::string getApplicationIdByURI (const char*);
			std::string getApplicationName(const char*);
			std::string getServer ( std::string);
			std::string getConnectionString(JSON_t*);
			bool updateApplicationDetails(std::string , int , std::string );
			
			static const char* DAPPS_DB_NAME;
			static const char* APPS_COLLECTION_NAME;
			static const char* SERVERS_COLLECTION_NAME;
	};
}

#endif //__dapps_MONGO_CLIENT__
