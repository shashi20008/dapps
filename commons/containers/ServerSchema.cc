#include "ServerSchema.h"
#include "../exceptions/DappsException.h"
#include <iostream>

int dapps::ServerSchema::getPort()
{
	return port;
}

std::string dapps::ServerSchema::getIp()
{
	return ip;
}

dapps::ServerSchema* dapps::ServerSchema::getDocument(const bson_t* resDoc)
 {
 	ServerSchema* schemaObject = new ServerSchema;
 	bson_iter_t itr;
 	uint32_t length;


 	if(resDoc && bson_iter_init(&itr, resDoc))
		{
			bool rc =  bson_iter_find(&itr, "ip");
			if(!rc)
				throw DappsException("Server ip not present in db");

			schemaObject->ip = bson_iter_utf8(&itr, &length);

			rc = bson_iter_find(&itr, "port");
			if(!rc)
				throw DappsException("Server port not present in db");

			schemaObject->port = bson_iter_int32(&itr);


			
		}

 	return schemaObject;
 }

