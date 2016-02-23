#include "StringUtils.h"
#include <iostream>

std::string dapps::StringUtils::trim(std::string strToTrim)
{
	std::string::iterator sPos = strToTrim.begin();
	while((*sPos == ' ' || *sPos == '\r' || *sPos == '\t' || *sPos == '\n') && sPos != strToTrim.end())
	{
		sPos++;
	}
	strToTrim.erase(strToTrim.begin(), sPos);

	std::string::iterator ePos = strToTrim.end();
	ePos--;
	while((*ePos == ' ' || *ePos == '\r' || *ePos == '\t' || *ePos == '\n') && ePos != strToTrim.begin())
	{
		ePos--;
	};
	if(ePos != strToTrim.end())
	{
		strToTrim.erase(ePos + 1, strToTrim.end());
	}
	return strToTrim;
}