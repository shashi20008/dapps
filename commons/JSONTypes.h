#ifndef __dapps_JSONTypes__
#define __dapps_JSONTypes__

#include <map>
#include <list>
#include <stdint.h>
#include <string>
namespace dapps
{
	class JSON_t; // Forward declaration
	
	typedef std::map<std::string, JSON_t*> JSONObject;
	typedef std::list<JSON_t*> JSONArray;
	typedef int JSONValueType;
	
	typedef union 
	{
		JSONObject* m_object;
		JSONArray* m_array;
		char* m_str;
		double m_floatVal;
		int64_t m_intVal; 
	} JSONContainer;
	
	class JSON_t 
	{
		JSONValueType m_type;
		JSONContainer m_val;
		
		public:
			static JSONValueType VALUE_TYPE_OBJECT;
			static JSONValueType VALUE_TYPE_ARRAY;
			static JSONValueType VALUE_TYPE_STRING;
			static JSONValueType VALUE_TYPE_FLOAT;
			static JSONValueType VALUE_TYPE_INTEGER;
	};
	
}

#endif //__dapps_JSONTypes__
