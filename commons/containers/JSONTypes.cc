#include "JSONTypes.h"
#include "../exceptions/DappsException.h"

const dapps::JSONValueType dapps::JSON_t::VALUE_TYPE_INVALID = -1;
const dapps::JSONValueType dapps::JSON_t::VALUE_TYPE_OBJECT = 0;
const dapps::JSONValueType dapps::JSON_t::VALUE_TYPE_ARRAY = 1;
const dapps::JSONValueType dapps::JSON_t::VALUE_TYPE_STRING = 2;
const dapps::JSONValueType dapps::JSON_t::VALUE_TYPE_FLOAT = 3;
const dapps::JSONValueType dapps::JSON_t::VALUE_TYPE_INTEGER = 4;
const dapps::JSONValueType dapps::JSON_t::VALUE_TYPE_BOOLEAN = 5;


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
	return this->m_val.m_floatVal;
}

bool dapps::JSON_t::getBool()
{
	if(m_type != VALUE_TYPE_BOOLEAN)
	{
		throw DappsException("tried to get boolean on non boolean json type.");
	}
	return this->m_val.m_bool;
}
