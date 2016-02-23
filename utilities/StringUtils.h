#ifndef __dapps_STRING_UTILS__
#define __dapps_STRING_UTILS__
#include <string>

namespace dapps
{
	class StringUtils
	{
		public:
			static std::string trim(std::string);
			template <typename T> static std::string toString(T& value);
	};
}

#include "StringUtils.tcc"

#endif // __dapps_STRING_UTILS__
