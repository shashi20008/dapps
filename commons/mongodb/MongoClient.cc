#include "MongoClient.h"
#include <bcon.h>
#include <iostream>
#include <mongoc.h>
#include <bson.h>
#include <string>
#include <map>
#include "../utilities/StringUtils.h"
#include "../containers/JSONTypes.h"
#include "../containers/ServerSchema.h"
#include "../../dapps.h"

const char* dapps::MongoClient::DAPPS_DB_NAME = "dapps";
const char* dapps::MongoClient::APPS_COLLECTION_NAME = "applications";
const char* dapps::MongoClient::SERVERS_COLLECTION_NAME = "servers";

dapps::MongoClient::MongoClient()
{
	JSON_t* appConfig = Dapps::get()->config->getConfig();
	m_mongoClient = mongoc_client_new(getConnectionString(appConfig).c_str());
	m_appsCollection = mongoc_client_get_collection(m_mongoClient, DAPPS_DB_NAME, APPS_COLLECTION_NAME);
	m_serversCollection = mongoc_client_get_collection(m_mongoClient, DAPPS_DB_NAME, SERVERS_COLLECTION_NAME);
}

std::string dapps::MongoClient::getConnectionString(JSON_t* appConfig) {
	std::string connectionString = "mongodb://";
	std::string mongoHost = appConfig->get("mongoServer")->getString("host");
	std::string mongoPort = appConfig->get("mongoServer")->getString("port");

	connectionString.append(mongoHost);
	if(!mongoPort.empty())
		connectionString.append(":" + mongoPort);

	connectionString.append("/");

	return connectionString;
}

bool dapps::MongoClient::updateApplicationDetails(std::string ip, int port, std::string appName) {

	std::cout<<"updateApplicationDetails"<<std::endl;
	bson_error_t error;
	bson_t* doc = BCON_NEW("ip", ip.c_str(), 
							"port", BCON_INT32(port),
							"appname",appName.c_str());
	const bson_t* resDoc;
	mongoc_cursor_t* cursor;
	
	cursor = mongoc_collection_find(m_serversCollection, MONGOC_QUERY_NONE, 0, 0, 0, doc, NULL, NULL);
	std::cout<<"check for duplicates"<<std::endl;
	if(!mongoc_cursor_next(cursor, &resDoc))
	{
		std::cout<<"Registering new app"<<std::endl;
		return mongoc_collection_insert (m_serversCollection, MONGOC_INSERT_NONE, doc, NULL, &error);
	}
	return true;
}

bson_t* dapps::MongoClient::getApplicationByURI(const char* uri)
{
	bson_t* query;
	const bson_t* resDoc;
	mongoc_cursor_t* cursor;
	query = BCON_NEW("mountPoint", uri);
	cursor = mongoc_collection_find(m_appsCollection, MONGOC_QUERY_NONE, 0, 0, 0, query, NULL, NULL);
	if(mongoc_cursor_next(cursor, &resDoc))
	{
		return bson_copy(resDoc);
	}
	return NULL;
}

dapps::ServerSchema* dapps::MongoClient::readApplicationDetails(std::string appName)
{
	bson_t* query;
	bson_iter_t itr;
	uint32_t length;
	const bson_t* resDoc;
	mongoc_cursor_t* cursor;
	query = BCON_NEW("appname", appName.c_str());
	cursor = mongoc_collection_find(m_serversCollection, MONGOC_QUERY_NONE, 0, 0, 0, query, NULL, NULL);
	if(mongoc_cursor_next(cursor, &resDoc))
	{
		ServerSchema* serverSchema = ServerSchema::getDocument(resDoc);
		return serverSchema;
		
	}
	return NULL;
}

std::string dapps::MongoClient::getApplicationIdByURI (const char* uri)
{
	bson_iter_t itr;
	uint32_t length;
	bson_t* doc = getApplicationByURI(uri);
	if(doc && bson_has_field(doc, "mountPoint") && bson_iter_init(&itr, doc) && bson_iter_find(&itr, "appId"))
	{
		std::string appId = bson_iter_utf8(&itr, &length);
		return appId;
	}
	return "";
}

std::string dapps::MongoClient::getApplicationName(const char* uri)
{
	bson_iter_t itr;
	uint32_t length;
	bson_t* doc = getApplicationByURI(uri);
	if(doc && bson_has_field(doc, "mountPoint") && bson_iter_init(&itr, doc) && bson_iter_find(&itr, "appName"))
	{
		std::string appName = bson_iter_utf8(&itr, &length);
		return appName;
	}
	return "";
}

std::string getServer (std::string appIdStr )
{
	int appId;
	dapps::StringUtils::fromString( appIdStr, &appId);
	mongoc_cursor_t* cursor;
	bson_t* query = BCON_NEW("pipeline", "[", "{",
												"$match", "{", 
													"appId", BCON_INT32(appId), 
												"}",
											"}",
											// "{",
											// 	"$group", "{", 
											// 		"_id","$appId",
											// 		"port","$port",
											// 		"ip", "$ip",
											// 		"minload", "{", 
											// 			"$min","$load",
											// 		"}",
											// 	"}",
											// "}",
										"]");
	
	const bson_t* resDoc;
	double minValue = 2;
	bson_iter_t itr;
 	std::string key;
 	double value;

	mongoc_client_t* m_mongoClient = mongoc_client_new("mongodb://127.0.0.1/");
	mongoc_collection_t* m_serversCollection = mongoc_client_get_collection(m_mongoClient, "dapps", "servers");
	cursor = mongoc_collection_aggregate(m_serversCollection, MONGOC_QUERY_NONE, query, NULL, NULL);
	while(mongoc_cursor_next(cursor, &resDoc))
	{
		if(resDoc && bson_iter_init(&itr, resDoc))
		{
			while(bson_iter_next(&itr))
			{
				key = bson_iter_key(&itr);
				if(key == "load")
				{
					value = bson_iter_double (&itr);
					if(value < minValue){
						minValue = value;
						dapps::ServerSchema* schemaObject = dapps::ServerSchema::getDocument(resDoc);
					}
				}
			}
		}
		
	}
	return "temp";
}

