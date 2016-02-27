#ifndef __dapps_ABSTRACT_CLIENT_SOCKET__
#define __dapps_ABSTRACT_CLIENT_SOCKET__

namespace dapps
{
	class AbstractClientSocket
	{
		virtual void write(char*) = 0;
	};
}

#endif //__dapps_ABSTRACT_CLIENT_SOCKET__
