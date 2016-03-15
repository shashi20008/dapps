#include "ServerSchema.h"
#include <iostream>

std::string dapps::ServerSchema::getPort()
{
	std::map<std::string, void*>::iterator it;
	it = serverMap.find("port");
	std::string port = (char*) it->second;
	return port;
}

std::string dapps::ServerSchema::getIp()
{
	std::map<std::string, void*>::iterator it;
	it = serverMap.find("ip");
	std::string ip = (char*) it->second;
	return ip;
}

dapps::ServerSchema* dapps::ServerSchema::getDocument(const bson_t* resDoc)
 {
 	ServerSchema* schemaObject = new ServerSchema;
 	schemaObject->serverMap.clear();
 	bson_iter_t itr;
 	std::string key;
 	uint32_t length;
 	const bson_value_t *value;

 	//std::string s = bson_as_json(resDoc, NULL);
	if(resDoc && bson_iter_init(&itr, resDoc))
	{
		while(bson_iter_next(&itr))
		{
			key = bson_iter_key(&itr);
			value = bson_iter_value(&itr);

			if(value->value_type == BSON_TYPE_DOUBLE) {
				double* val = new double[1];
				*val = bson_iter_double (&itr);
				schemaObject->serverMap.insert(std::pair<std::string,void*>(key,val));
				} 
				else if(value->value_type == BSON_TYPE_UTF8)
				{
					schemaObject->serverMap.insert(std::pair<std::string,void*>(key,(void*)bson_iter_utf8 (&itr, &length)));
				}
		}
	}
	for(std::map<std::string, void*>::const_iterator it = schemaObject->serverMap.begin();it != schemaObject->serverMap.end(); ++it)
	{
    	std::cout << it->first << " " << it->second << "\n";
	}
 	return schemaObject;
 }

