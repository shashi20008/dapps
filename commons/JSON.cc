#include <iostream>
#include <cstring>
#include <cstdlib>
#include "JSON.h"
#include "JSONTypes.h"
#include "../utilities/StringUtils.h"
#include "exceptions/JSONParseException.h"

dapps::JSON_t* dapps::JSON::parse(std::string input)
{
	uint64_t i = 0;
	skipWhiteSpace(input, i);
	
	if(input[i] == '{')
	{
		return parseObject(input, i);
	}
	else if(input[i] == '[')
	{
		return parseArray(input, i);
	}
	else
	{
		throw new JSONParseException("Invalid JSON object");
	}
	return NULL;
}

void dapps::JSON::skipWhiteSpace(std::string& input, uint64_t& counter)
{
	char cur = input[counter];
	while(cur == ' ' || cur == '\t' || cur == '\r' || cur == '\n')
	{
		counter++;
		cur = input[counter];
	}
}

dapps::JSON_t* dapps::JSON::parseObject(std::string& input, uint64_t& counter)
{
	bool endOfObject = false;
	char cur = input[counter];
	if(cur != '{')
	{
		throw new JSONParseException("Invalid JSON object");
	}
	JSONObject* _object = new JSONObject();
	counter++;
	skipWhiteSpace(input, counter);
	
	while(input[counter] != '}') // Repeat until end of object.
	{
		std::string _key = parseKey(input, counter);
		
		JSONParserFunc parser = getParserFunc(input, counter);
		
		if(parser == NULL) {
			// Invalid JSON. Throw
			throw new JSONParseException("Invalid JSON object");
		}
		JSON_t* _val = (*parser) (input, counter);
		
		// Put it on the _object
		_object->insert(JSONPair(_key, _val));
		skipWhiteSpace(input, counter);
		if(input[counter] == ',')
		{
			counter++;
		}
		else if(!endOfObject)
		{
			// Mark end of object here.
			// Otherwise faulty JSONs might 'cause crash.
			endOfObject = true;
		}
		else
		{
			// @TODO: throw
			throw new JSONParseException("Invalid JSON object");
		}
		
		skipWhiteSpace(input, counter);
	}
	counter++;
	skipWhiteSpace(input, counter);
	
	JSON_t* _container = new JSON_t();
	_container->m_type = JSON_t::VALUE_TYPE_OBJECT;
	_container->m_val.m_object = _object;
	
	return _container;
}

dapps::JSON_t* dapps::JSON::parseString(std::string& input, uint64_t& counter)
{
	if(input[counter] != '"')
	{
		// throw instead.
		throw new JSONParseException("Invalid JSON object");
	}
	std::string str = "";
	char* strBuffer = new char[101];
	int strCounter = 0;
	counter++;
	char prev = '\0';
	char cur = input[counter];
	
	while(cur != '"' && prev != '\\')
	{
		strBuffer[strCounter++] = cur;
		counter++;
		prev = cur;
		cur = input[counter];
		
		if(strCounter == 100)
		{
			str.append(strBuffer, strCounter);
			strCounter = 0;
		}
	}
	str.append(strBuffer, strCounter);
	
	counter++;
	skipWhiteSpace(input, counter);
	
	char* retStr = new char[str.length() + 1];
	std::strcpy(retStr, str.c_str());
	
	//Cleanup
	delete strBuffer;
	
	JSON_t* _container = new JSON_t();
	_container->m_type = JSON_t::VALUE_TYPE_STRING;
	_container->m_val.m_str = retStr;
	return _container;
}

dapps::JSON_t* dapps::JSON::parseNumber(std::string& input, uint64_t& counter)
{
	JSON_t* _val = new JSON_t();
	char cur = input[counter];
	
	if((cur < '0' || cur > '9') && cur != '-')
	{
		// not a number.
		// throw
		throw new JSONParseException("Invalid JSON object");
	}
	std::string numStr = "";
	char* numBuffer = new char[101];
	int numCounter = 0;
	bool hasDecimal = false;
	while((cur >= '0' && cur <= '9') || cur == '.' || cur == '-')
	{
		numBuffer[numCounter++] = cur;
		
		if(cur == '.')
		{
			hasDecimal = true;
		}
		
		// Setup for next itr
		counter++;
		cur = input[counter];
		
		if(numCounter == 100)
		{
			numStr.append(numBuffer, numCounter);
			numCounter = 0;
		}
	}
	numStr.append(numBuffer, numCounter);
	
	if(hasDecimal)
	{
		_val->m_type = JSON_t::VALUE_TYPE_FLOAT;
		_val->m_val.m_floatVal = strtod(numStr.c_str(), NULL);
	}
	else
	{
		_val->m_type = JSON_t::VALUE_TYPE_INTEGER;
		_val->m_val.m_intVal = JSON::strtoll(numStr.c_str());
	}
	//cleanup
	delete numBuffer;
	
	return _val;
}

// @TODO: refactor
int64_t dapps::JSON::strtoll(const char* numStr)
{
	int64_t retVal = 0;
	int i = 0;
	if(numStr[i] == '-')
	{
		i++;
	}
	while(numStr[i] != '\0' && numStr[i] >= '0' && numStr[i] <= '9')
	{
		retVal = (retVal * 10) + (numStr[i] - '0');
		i++;
	}
	
	if(numStr[0] == '-')
	{
		retVal *= -1;
	}
	return retVal;
}

// Almost duplicate of parseString. Move commons out.
std::string dapps::JSON::parseKey(std::string& input, uint64_t& counter)
{
	if(input[counter] != '"')
	{
		throw new JSONParseException("Invalid JSON object");
	}
	std::string key = "";
	char* keyBuffer = new char[101];
	int keyCounter = 0;
	counter++;
	char cur = input[counter];
	
	while(cur != '"') // JSON key will not have '"' character
	{
		keyBuffer[keyCounter++] = cur;
		counter++;
		cur = input[counter];
		
		if(keyCounter == 100)
		{
			key.append(keyBuffer, keyCounter);
			keyCounter = 0;
		}
	}
	key.append(keyBuffer, keyCounter);
	
	// Ensure it indeed it the key by looking for ':'
	counter++;
	skipWhiteSpace(input, counter);
	if(input[counter] != ':')
	{
		throw new JSONParseException("Invalid JSON object");
	}
	counter++;
	skipWhiteSpace(input, counter);
	
	// Cleanup
	delete keyBuffer;
	
	return key;
}

dapps::JSON_t* dapps::JSON::parseArray(std::string& input, uint64_t& counter)
{
	if(input[counter] != '[') {
		throw new JSONParseException("Invalid JSON object");
	}
	
	JSONArray* _array = new JSONArray();
	skipWhiteSpace(input, counter);
	
	JSON_t* _container = new JSON_t();
	_container->m_type = JSON_t::VALUE_TYPE_ARRAY;
	_container->m_val.m_array = _array;
	return _container;
}

dapps::JSONValueType dapps::JSON::getJSONValueType(std::string& input, uint64_t& counter)
{
	if(input[counter] == '{')
	{
		return JSON_t::VALUE_TYPE_OBJECT;
	}
	else if(input[counter] == '[')
	{
		return JSON_t::VALUE_TYPE_ARRAY;
	}
	else if(input[counter] == '"')
	{
		return JSON_t::VALUE_TYPE_STRING;
	}
	else if((input[counter] >= '0' && input[counter] <= '9') || input[counter] == '-')
	{
		return JSON_t::VALUE_TYPE_INTEGER;
	}
	return JSON_t::VALUE_TYPE_INVALID;
}

dapps::JSONParserFunc dapps::JSON::getParserFunc(std::string& input, uint64_t& counter)
{
	if(input[counter] == '{')
	{
		return parseObject;
	}
	else if(input[counter] == '[')
	{
		return parseArray;
	}
	else if(input[counter] == '"')
	{
		return parseString;
	}
	else if((input[counter] >= '0' && input[counter] <= '9') || input[counter] == '-')
	{
		return parseNumber;
	}
	return NULL;
}

dapps::JSONStringifierFunc dapps::JSON::getStringifierFunc(dapps::JSON_t* json)
{
	if(json == NULL)
	{
		return stringifyInvalid;
	}
	else if(json->m_type == JSON_t::VALUE_TYPE_ARRAY)
	{
		return stringifyArray;
	}
	else if(json->m_type == JSON_t::VALUE_TYPE_OBJECT)
	{
		return stringifyObject;
	}
	else if(json->m_type == JSON_t::VALUE_TYPE_STRING)
	{
		return stringifyString;
	}
	else if(json->m_type == JSON_t::VALUE_TYPE_FLOAT)
	{
		return stringifyFloat;
	}
	else if(json->m_type == JSON_t::VALUE_TYPE_INTEGER)
	{
		return stringifyInteger;
	} 
	else if(json->m_type == JSON_t::VALUE_TYPE_BOOLEAN)
	{
		return stringifyBoolean;
	}
	return stringifyInvalid;
}

std::string dapps::JSON::stringify(dapps::JSON_t* json)
{
	std::string _json;
	_json = getStringifierFunc(json)(json);
	return _json;
}

std::string dapps::JSON::stringifyObject(dapps::JSON_t* json)
{
	std::string retStr = "null";
	if(json->m_type != JSON_t::VALUE_TYPE_OBJECT)
	{
		return retStr;
	}
	JSONObject* object = json->m_val.m_object;
	if(object == NULL) 
	{
		return retStr;
	}
	JSONObject::iterator it = object->begin();
	retStr = "{}";
	if(it == object->end())
	{
		return retStr;
	}
	
	retStr = "{";
	do
	{
		retStr += "\"" + it->first +"\":";
		retStr += getStringifierFunc(it->second)(it->second);
		retStr += ",";
		it++;
	} while(it != object->end());
	// to remove last comma
	retStr = retStr.substr(0, retStr.length() - 1);
	retStr += "}";
	return retStr;
}

std::string dapps::JSON::stringifyArray(dapps::JSON_t* json)
{
	if(json->m_type != JSON_t::VALUE_TYPE_ARRAY)
	{
		return "null";
	}
	return "null";
}

std::string dapps::JSON::stringifyString(dapps::JSON_t* json)
{
	if(json->m_type != JSON_t::VALUE_TYPE_STRING) 
	{
		return "null";
	}
	std::string retStr = "\"";
	retStr += std::string(json->m_val.m_str);
	retStr += "\"";
	return retStr;
}

std::string dapps::JSON::stringifyFloat(dapps::JSON_t* json)
{
	if(json->m_type != JSON_t::VALUE_TYPE_FLOAT)
	{
		return "null";
	}
	return StringUtils::toString(json->m_val.m_floatVal);
}

std::string dapps::JSON::stringifyInteger(dapps::JSON_t* json)
{
	if(json->m_type != JSON_t::VALUE_TYPE_INTEGER)
	{
		return "null";
	}
	return StringUtils::toString(json->m_val.m_intVal);
}

std::string dapps::JSON::stringifyBoolean(dapps::JSON_t* json)
{
	if(json->m_type != JSON_t::VALUE_TYPE_BOOLEAN)
	{
		return "null";
	}
	return (json->m_val.m_bool?"true":"false");
}

std::string dapps::JSON::stringifyInvalid(dapps::JSON_t* json)
{
	return "null";
}
