#include "PathUtils.h"
#include "../containers/Buffer.h"
#include <cstdlib>
#include <cstring>

char* dapps::PathUtils::join(const char* partOne, const char* partTwo)
{
	std::size_t partOneLen = strlen(partOne);
	std::size_t partTwoLen = strlen(partTwo);
	
	Buffer fullPath(partOneLen + partTwoLen + 2);
	fullPath.append(partOne, partOneLen);
	
	char separator = '\0';
	#ifdef _WIN32
		separator = '\\';
	#else
		separator = '/';
	#endif
	
	if(fullPath[partOneLen - 1] != separator)
	{
		fullPath.append(separator);
	}
	fullPath.append(partTwo, partTwoLen);
	
	return fullPath.c_strCopy();
}
