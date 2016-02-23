#ifndef __dapps_STRING_UTILS__
#error "This file is not to be included directly. Include StringUtils.h instead"
#endif //__dapps_STRING_UTILS__

#include <sstream>

template <typename T> std::string dapps::StringUtils::toString(T& value)
{
    std::stringstream sstr;
    sstr << value;
    return sstr.str();
}
