#include <iostream>
#include <cstring>
#include <cstdlib>
#include "JSON.h"
#include "JSONTypes.h"

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
		//throw
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
	char cur = input[counter];
	if(cur != '{')
	{
		return NULL;
	}
	JSONObject* _object = new JSONObject();
	counter++;
	skipWhiteSpace(input, counter);
	do
	{
		std::string _key = parseKey(input, counter);
		
		JSON_t* _val;
		if(input[counter] == '{')
		{
			_val = parseObject(input, counter);
		}
		else if(input[counter] == '[')
		{
			_val = parseArray(input, counter);
		}
		else if(input[counter] == '"')
		{
			_val = parseString(input, counter);
		}
		else if((input[counter] >= '0' && input[counter] <= '9') || input[counter] == '-')
		{
			_val = parseNumber(input, counter);
		}
		
		// Put it on the _object
		_object->insert(JSONPair(_key, _val));
		skipWhiteSpace(input, counter);
		if(input[counter] == ',')
		{
			counter++;
		}
		else
		{
			// Mark end of object here.
			// Otherwise faulty JSONs might 'cause crash.
		}
		
		skipWhiteSpace(input, counter);
	} while(input[counter] != '}'); // Repeat until end of object.
	
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
		return NULL;
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
	
	if((cur <= '0' || cur >= '9') && cur != '-')
	{
		// not a number.
		// throw
		return NULL;
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
		return NULL;
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
		return NULL;
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
		return NULL;
	}
	
	JSONArray* _array = new JSONArray();
	skipWhiteSpace(input, counter);
	
	JSON_t* _container = new JSON_t();
	_container->m_type = JSON_t::VALUE_TYPE_ARRAY;
	_container->m_val.m_array = _array;
	return _container;
}

std::string dapps::JSON::stringify(dapps::JSON_t* json)
{
	return "";
}
