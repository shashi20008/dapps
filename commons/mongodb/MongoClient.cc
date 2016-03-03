#include "MongoClient.h"
#include <bcon.h>
#include <iostream>

const char* dapps::MongoClient::DAPPS_DB_NAME = "dapps";
const char* dapps::MongoClient::APPS_COLLECTION_NAME = "applications";
const char* dapps::MongoClient::SERVERS_COLLECTION_NAME = "servers";

dapps::MongoClient::MongoClient()
{
	m_mongoClient = mongoc_client_new("mongodb://127.0.0.1/");
	m_appsCollection = mongoc_client_get_collection(m_mongoClient, DAPPS_DB_NAME, APPS_COLLECTION_NAME);
	m_serversCollection = mongoc_client_get_collection(m_mongoClient, DAPPS_DB_NAME, SERVERS_COLLECTION_NAME);
}

bson_t* dapps::MongoClient::getApplicationByURI(const char* uri)
{
	bson_t* query;
	const bson_t* resDoc;
	mongoc_cursor_t* cursor;
	query = BCON_NEW("uriPattern", uri);
	cursor = mongoc_collection_find(m_appsCollection, MONGOC_QUERY_NONE, 0, 0, 0, query, NULL, NULL);
	if(mongoc_cursor_next(cursor, &resDoc))
	{
		return bson_copy(resDoc);
	}
	return NULL;
}

std::string dapps::MongoClient::getApplicationIdByURI (const char* uri)
{
	bson_iter_t itr;
	uint32_t length;
	bson_t* doc = getApplicationByURI(uri);
	if(doc && bson_has_field(doc, "uriPattern") && bson_iter_init(&itr, doc) && bson_iter_find(&itr, "appId"))
	{
		std::string appId = bson_iter_utf8(&itr, &length);
		return appId;
	}
	return "";
}
