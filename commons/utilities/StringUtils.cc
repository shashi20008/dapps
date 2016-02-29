#include "StringUtils.h"

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

std::vector<std::string> dapps::StringUtils::split(std::string strToSplit, char separator)
{
	std::vector<std::string> stringVector;
	int ePos;
    strToSplit = strToSplit + separator;

	while(!strToSplit.empty())
	{
		ePos = strToSplit.find(separator);
		stringVector.push_back(strToSplit.substr(0, ePos));
		strToSplit = strToSplit.substr(ePos+1, strToSplit.length());
	}
	return stringVector;
}

std::string dapps::StringUtils::toUpperCase(std::string strToUpper)
{
	for( int i = 0; i < strToUpper.length(); i++)
	{
		strToUpper[i] = toupper(strToUpper[i]);
	}
	return strToUpper;
}

std::string dapps::StringUtils::toLowerCase(std::string strToLower)
{
	for( int i = 0; i < strToLower.length(); i++)
	{
		strToLower[i] = toupper(strToLower[i]);
	}
	return strToLower;
}
