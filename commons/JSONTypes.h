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
	typedef std::pair<std::string, JSON_t*> JSONPair;
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
		public:
			JSONValueType m_type;
			JSONContainer m_val;
		
			static const JSONValueType VALUE_TYPE_OBJECT;
			static const JSONValueType VALUE_TYPE_ARRAY;
			static const JSONValueType VALUE_TYPE_STRING;
			static const JSONValueType VALUE_TYPE_FLOAT;
			static const JSONValueType VALUE_TYPE_INTEGER;
	};
	
}

#endif //__dapps_JSONTypes__
