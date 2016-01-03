#ifndef __dapps_JSONTypes__
#define __dapps_JSONTypes__

#include <map>
#include <list>
#include <stdint.h>
#include <string>
namespace dapps
{
	class JSONValue; // Forward declaration
	
	typedef std::map<std::string, JSONValue*> JSONObject;
	typedef std::list<JSONValue*> JSONArray;
	typedef int JSONValueType;
	
	typedef union 
	{
		JSONObject* object;
		JSONArray* array;
		char* str;
		double floatVal;
		int64_t intVal; 
	} JSONContainer;
	
	class JSONValue 
	{
		JSONValueType type;
		JSONContainer* val;
		
		public:
			static JSONValueType VALUE_TYPE_OBJECT;
			static JSONValueType VALUE_TYPE_ARRAY;
			static JSONValueType VALUE_TYPE_STRING;
			static JSONValueType VALUE_TYPE_FLOAT;
			static JSONValueType VALUE_TYPE_INTEGER;
	};
	
}

#endif //__dapps_JSONTypes__
