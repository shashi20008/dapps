#ifndef __dapps_JSON__
#define __dapps_JSON__

#include <string>

namespace dapps
{
	class JSON
	{
		public:
			static void parse(std::string);
			static std::string stringify(void);
	};
}

#endif //__dapps_JSON__
