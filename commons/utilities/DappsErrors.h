#ifndef __dapps_DAPPS_ERRORS__
#define __dapps_DAPPS_ERRORS__

#include <string>

namespace dapps
{
	class DappsErrors
	{
		int m_errorCode;
		std::string m_desc;
		std::string m_jsonStr;
		
		public:
			DappsErrors(int _errorCode, std::string _desc);
			int getErrorCode();
			std::string getDescription();
			std::string getJSONString();
			
		// The predefined errors.
		static DappsErrors* INVALID_REQUEST_URI;
	};
}

#endif //__dapps_DAPPS_ERRORS__
