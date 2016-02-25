#ifndef __dapps_DAPPS_EXCEPTION__
#define __dapps_DAPPS_EXCEPTION__

#include <exception>
#include <string>

namespace dapps
{
	class DappsException : public std::exception
	{
		std::string message;
		public:
			DappsException(std::string msg = "UNKOWN ERROR");
			~DappsException() throw();
			const char* what() const throw();
	};
}
#endif //__dapps_DAPPS_EXCEPTION__
