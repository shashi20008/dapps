#ifndef __dapps_STRING_UTILS__
#define __dapps_STRING_UTILS__
#include <string>
#include <iostream>
#include <vector>

namespace dapps
{
	class StringUtils
	{
		public:
			static std::string trim(std::string);
			static std::vector<std::string> split(std::string, char);
			template <typename T> static std::string toString(T& value);
	};
}

#include "StringUtils.tcc"

#endif // __dapps_STRING_UTILS__
