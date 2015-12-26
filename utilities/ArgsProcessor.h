#ifndef __ArgsProcessor__
#define __ArgsProcessor__

#include <string.h>
#include <iostream>
#include <string>
#include <map>
#include <vector>

namespace dapps
{
	typedef std::vector<std::string> ArgsValList;
	typedef std::map< std::string, ArgsValList*> ArgsMap;
	typedef std::pair< std::string, ArgsValList*> ArgsPair;
	
	class ArgsProcessor
	{
		private:
			ArgsMap* args;
			ArgsValList* emptyList;
		public:
			ArgsProcessor(int, char**);
			~ArgsProcessor();
			bool has(std::string);
			ArgsValList* get(std::string);
			void printAll();
	};
}
#endif //__ArgsProcessor__
