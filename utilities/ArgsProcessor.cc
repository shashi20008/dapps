
#include "ArgsProcessor.h"

dapps::ArgsProcessor::ArgsProcessor(int argc, char** argv)
{
	args = new ArgsMap();
	emptyList = new ArgsValList();
	
	int i = 1;
	ArgsValList* valueList;
	while (i < argc)
	{
		if(argv[i][0] == '-' && argv[i][1] == '-')
		{
			valueList = new ArgsValList();
			std::string key(argv[i] + 2);
			args->insert(ArgsPair(key, valueList));
		}
		else if(valueList != NULL)
		{
			valueList->push_back(std::string(argv[i]));
		}
		i++;
	}
}

dapps::ArgsProcessor::~ArgsProcessor()
{
	delete emptyList;
	// TODO: delete each of value list here.
	delete args;
}

bool dapps::ArgsProcessor::has(std::string key)
{
	return args->count(key);
}

dapps::ArgsValList* dapps::ArgsProcessor::get(std::string key)
{
	ArgsMap::iterator it = args->find(key);
	if(it != args->end())
	{
		return it->second;
	}
	return emptyList;
}

void dapps::ArgsProcessor::printAll()
{
	for(ArgsMap::iterator it = args->begin(); it != args->end(); ++it)
	{
		std::string key = it->first;
		ArgsValList* valList = it->second;
		std::cout << key << ": " << "[ ";
		for(ArgsValList::iterator vecIt = valList->begin(); vecIt != valList->end(); ++vecIt)
		{
			std::cout << *vecIt << ", ";
		}
		std::cout<< ']' <<std::endl;
	}
}
