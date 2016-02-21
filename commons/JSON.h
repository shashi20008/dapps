#ifndef __dapps_JSON__
#define __dapps_JSON__

#include <string>
#include <stdint.h>

#include "JSONTypes.h"

namespace dapps
{
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
	};
}

#endif //__dapps_JSON__
