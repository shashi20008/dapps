#include "StringUtils.h"

std::string dapps::StringUtils::trim(std::string strToTrim)
{
	std::string::iterator sPos = strToTrim.begin();
	while((*sPos == ' ' || *sPos == '\r' || *sPos == '\t' || *sPos == '\n') && sPos != strToTrim.end())
	{
		sPos++;
	}
	strToTrim.erase(strToTrim.begin(), sPos);

	if(!strToTrim.empty()) 
	{
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
	}

	return strToTrim;
}

std::vector<std::string> dapps::StringUtils::split(std::string strToSplit, char separator, std::size_t limit, bool ignoreEmpty)
{
	std::vector<std::string> stringVector;
	int ePos;
    strToSplit = strToSplit + separator;

	while(!strToSplit.empty())
	{
		ePos = strToSplit.find(separator);
		std::string part = strToSplit.substr(0, ePos);
		strToSplit = strToSplit.substr(ePos+1, strToSplit.length());
		
		if(ignoreEmpty && part.empty())
		{
			continue;
		}
		
		stringVector.push_back(part);
		
		if(limit && stringVector.size() >= limit && !strToSplit.empty()) 
		{
			stringVector.pop_back();
			strToSplit.erase(strToSplit.end() - 1);
			stringVector.push_back(part + separator + strToSplit);
			break;
		}
	}
	return stringVector;
}

std::string dapps::StringUtils::toUpperCase(std::string strToUpper)
{
	for( std::size_t i = 0; i < strToUpper.length(); i++)
	{
		strToUpper[i] = toupper(strToUpper[i]);
	}
	return strToUpper;
}

std::string dapps::StringUtils::toLowerCase(std::string strToLower)
{
	for( std::size_t i = 0; i < strToLower.length(); i++)
	{
		strToLower[i] = toupper(strToLower[i]);
	}
	return strToLower;
}

/*
int main ()
{
	std::string str = "shashi is a good    boy";
	std::vector<std::string> strs = dapps::StringUtils::split(str, ' ', 4, true);
	for(int i = 0; i < strs.size(); i++)
	{
		std::cout << i << ": |-->>" << strs[i] << "<<--|" << std::endl;
	}
	return 0;
}
*/
