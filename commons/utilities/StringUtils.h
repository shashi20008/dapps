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
			static std::vector<std::string> split(std::string, char, std::size_t limit = 0, bool ignoreEmpty = false);
			static std::string toUpperCase(std::string);
			static std::string toLowerCase(std::string);
			template <typename T> static std::string toString(T& value);
			template <typename T> static void fromString(std::string, T*);
	};
}

#include "StringUtils.tcc"

#endif // __dapps_STRING_UTILS__
