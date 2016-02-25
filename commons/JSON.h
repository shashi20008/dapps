#ifndef __dapps_JSON__
#define __dapps_JSON__

#include <string>
#include <stdint.h>

#include "JSONTypes.h"

namespace dapps
{
	typedef JSON_t* (*JSONParserFunc)(std::string&, uint64_t&);
	typedef std::string (*JSONStringifierFunc)(JSON_t*);
	
	class JSON
	{
		public:
			static JSON_t* parse(std::string);
			static std::string stringify(JSON_t*);
		private:
			static void skipWhiteSpace(std::string&, uint64_t&);
			static JSON_t* parseObject(std::string&, uint64_t&);
			static JSON_t* parseArray(std::string&, uint64_t&);
			static std::string parseKey(std::string&, uint64_t&);
			static JSON_t* parseString(std::string&, uint64_t&);
			static JSON_t* parseNumber(std::string&, uint64_t&);
			static int64_t strtoll(const char*);
			
			static std::string stringifyObject(dapps::JSON_t*);
			static std::string stringifyArray(dapps::JSON_t*);
			static std::string stringifyString(dapps::JSON_t*);
			static std::string stringifyFloat(dapps::JSON_t*);
			static std::string stringifyInteger(dapps::JSON_t*);
			static std::string stringifyBoolean(dapps::JSON_t*);
			static std::string stringifyInvalid(dapps::JSON_t*);
			
			static JSONValueType getJSONValueType(std::string&, uint64_t&);
			static JSONParserFunc getParserFunc(std::string&, uint64_t&);
			static JSONStringifierFunc getStringifierFunc(dapps::JSON_t*);
	};
}

#endif //__dapps_JSON__
