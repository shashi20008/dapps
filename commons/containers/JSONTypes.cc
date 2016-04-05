#include "JSONTypes.h"
#include "../exceptions/DappsException.h"
#include <stdexcept>

const dapps::JSONValueType dapps::JSON_t::VALUE_TYPE_INVALID = -1;
const dapps::JSONValueType dapps::JSON_t::VALUE_TYPE_OBJECT = 0;
const dapps::JSONValueType dapps::JSON_t::VALUE_TYPE_ARRAY = 1;
const dapps::JSONValueType dapps::JSON_t::VALUE_TYPE_STRING = 2;
const dapps::JSONValueType dapps::JSON_t::VALUE_TYPE_FLOAT = 3;
const dapps::JSONValueType dapps::JSON_t::VALUE_TYPE_INTEGER = 4;
const dapps::JSONValueType dapps::JSON_t::VALUE_TYPE_BOOLEAN = 5;
const dapps::JSONValueType dapps::JSON_t::VALUE_TYPE_NULL = 6;


dapps::JSONObject* dapps::JSON_t::getObject()
{
	if(m_type != VALUE_TYPE_OBJECT)
	{
		throw DappsException("tried to get JSON object on non object type.");
	}
	return this->m_val.m_object;
}

dapps::JSONArray* dapps::JSON_t::getArray()
{
	if(m_type != VALUE_TYPE_ARRAY)
	{
		throw DappsException("tried to get JSON array on non array type.");
	}
	return this->m_val.m_array;
}

std::string dapps::JSON_t::getString()
{
	if(m_type != VALUE_TYPE_STRING)
	{
		throw DappsException("tried to get JSON string on non string type.");
	}
	return this->m_val.m_str;
}

double dapps::JSON_t::getDouble()
{
	if(m_type != VALUE_TYPE_FLOAT)
	{
		throw DappsException("tried to get dobule on non double json type.");
	}
	return this->m_val.m_floatVal;
}

int64_t dapps::JSON_t::getInt()
{
	if(m_type != VALUE_TYPE_INTEGER)
	{
		throw DappsException("tried to get Integer on non Integer json type.");
	}
	return this->m_val.m_intVal;
}

bool dapps::JSON_t::getBool()
{
	if(m_type != VALUE_TYPE_BOOLEAN)
	{
		throw DappsException("tried to get boolean on non boolean json type.");
	}
	return this->m_val.m_bool;
}

// Object accessors.
dapps::JSON_t* dapps::JSON_t::get(std::string key)
{
	JSONObject* _obj = getObject();
	JSONObject::iterator it = _obj->find(key);
	if(it == _obj->end()) 
	{
		throw DappsException("No such key in JSON Object:: " + key);
	}
	return it->second;
}

dapps::JSONObject* dapps::JSON_t::getObject(std::string key)
{
	JSONObject* _obj = getObject();
	JSONObject::iterator it = _obj->find(key);
	if(it == _obj->end()) 
	{
		throw DappsException("No such key in JSON Object:: " + key);
	}
	return it->second->getObject();
}

dapps::JSONArray* dapps::JSON_t::getArray(std::string key)
{
	JSONObject* _obj = getObject();
	JSONObject::iterator it = _obj->find(key);
	if(it == _obj->end()) 
	{
		throw DappsException("No such key in JSON Object:: " + key);
	}
	return it->second->getArray();
}

std::string dapps::JSON_t::getString(std::string key)
{
	JSONObject* _obj = getObject();
	JSONObject::iterator it = _obj->find(key);
	if(it == _obj->end()) 
	{
		throw DappsException("No such key in JSON Object:: " + key);
	}
	return it->second->getString();
}

double dapps::JSON_t::getDouble(std::string key)
{
	JSONObject* _obj = getObject();
	JSONObject::iterator it = _obj->find(key);
	if(it == _obj->end()) 
	{
		throw DappsException("No such key in JSON Object:: " + key);
	}
	return it->second->getDouble();
}

int64_t dapps::JSON_t::getInt(std::string key)
{
	JSONObject* _obj = getObject();
	JSONObject::iterator it = _obj->find(key);
	if(it == _obj->end()) 
	{
		throw DappsException("No such key in JSON Object:: " + key);
	}
	return it->second->getInt();
}

bool dapps::JSON_t::getBool(std::string key)
{
	JSONObject* _obj = getObject();
	JSONObject::iterator it = _obj->find(key);
	if(it == _obj->end()) 
	{
		throw DappsException("No such key in JSON Object:: " + key);
	}
	return it->second->getBool();
}


// Array accessors.
dapps::JSON_t* dapps::JSON_t::get(std::size_t index)
{
	JSONArray* _obj = getArray();
	if(index < _obj->size()) 
	{
		return _obj->at(index);
	}
	else {
		throw DappsException("Index out of range in JSON Array");
	}
	return NULL;
}

dapps::JSONObject* dapps::JSON_t::getObject(std::size_t index)
{
	JSONArray* _obj = getArray();
	if(index < _obj->size()) 
	{
		JSON_t* _json = _obj->at(index);
		return _json->getObject();
	}
	else {
		throw DappsException("Index out of range in JSON Array");
	}
	return NULL;
}

dapps::JSONArray* dapps::JSON_t::getArray(std::size_t index)
{
	JSONArray* _obj = getArray();
	if(index < _obj->size()) 
	{
		JSON_t* _json = _obj->at(index);
		return _json->getArray();
	}
	else {
		throw DappsException("Index out of range in JSON Array");
	}
	return NULL;
}

std::string dapps::JSON_t::getString(std::size_t index)
{
	JSONArray* _obj = getArray();
	if(index < _obj->size()) 
	{
		JSON_t* _json = _obj->at(index);
		return _json->getString();
	}
	else {
		throw DappsException("Index out of range in JSON Array");
	}
	return NULL;
}

double dapps::JSON_t::getDouble(std::size_t index)
{
	JSONArray* _obj = getArray();
	if(index < _obj->size()) 
	{
		JSON_t* _json = _obj->at(index);
		return _json->getDouble();
	}
	else {
		throw DappsException("Index out of range in JSON Array");
	}
	return 0.0;
}

int64_t dapps::JSON_t::getInt(std::size_t index)
{
	JSONArray* _obj = getArray();
	if(index < _obj->size()) 
	{
		JSON_t* _json = _obj->at(index);
		return _json->getInt();
	}
	else {
		throw DappsException("Index out of range in JSON Array");
	}
	return 0;
}

bool dapps::JSON_t::getBool(std::size_t index)
{
	JSONArray* _obj = getArray();
	if(index < _obj->size()) 
	{
		JSON_t* _json = _obj->at(index);
		return _json->getBool();
	}
	else {
		throw DappsException("Index out of range in JSON Array");
	}
	return NULL;
}
