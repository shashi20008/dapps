#ifndef __dapps_JSONTypes__
#define __dapps_JSONTypes__

#include <map>
#include <vector>
#include <stdint.h>
#include <string>
namespace dapps
{
	class JSON_t; // Forward declaration
	
	typedef std::map<std::string, JSON_t*> JSONObject;
	typedef std::pair<std::string, JSON_t*> JSONPair;
	typedef std::vector<JSON_t*> JSONArray;
	typedef int JSONValueType;
	
	typedef union 
	{
		JSONObject* m_object;
		JSONArray* m_array;
		char* m_str;
		double m_floatVal;
		int64_t m_intVal; 
		bool m_bool;
	} JSONContainer;
	
	class JSON_t 
	{
		public:
			~JSON_t();
			
			JSONValueType m_type;
			JSONContainer m_val;
			
			// Cur reference
			JSONObject* getObject();
			JSONArray* getArray();
			std::string getString();
			double getDouble();
			int64_t getInt();
			bool getBool();
			
			// JSON Obj accessors
			JSON_t* get(std::string);
			JSONObject* getObject(std::string);
			JSONArray* getArray(std::string);
			std::string getString(std::string);
			double getDouble(std::string);
			int64_t getInt(std::string);
			bool getBool(std::string);
			
			// JSON Array accessors
			JSON_t* get(std::size_t);
			JSONObject* getObject(std::size_t);
			JSONArray* getArray(std::size_t);
			std::string getString(std::size_t);
			double getDouble(std::size_t);
			int64_t getInt(std::size_t);
			bool getBool(std::size_t);

			static const JSONValueType VALUE_TYPE_INVALID;
			static const JSONValueType VALUE_TYPE_OBJECT;
			static const JSONValueType VALUE_TYPE_ARRAY;
			static const JSONValueType VALUE_TYPE_STRING;
			static const JSONValueType VALUE_TYPE_FLOAT;
			static const JSONValueType VALUE_TYPE_INTEGER;
			static const JSONValueType VALUE_TYPE_BOOLEAN;
			static const JSONValueType VALUE_TYPE_NULL;
	};
	
}

#endif //__dapps_JSONTypes__
