#ifndef __dapps_ABSTRACT_CLIENT_SOCKET__
#define __dapps_ABSTRACT_CLIENT_SOCKET__

#include <cstddef>

namespace dapps
{
	class AbstractClientSocket
	{
		public:
			virtual void write(char*, std::size_t) = 0;
	};
}

#endif //__dapps_ABSTRACT_CLIENT_SOCKET__
