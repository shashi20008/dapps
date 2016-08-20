#include "DappsErrors.h"
#include "StringUtils.h"

dapps::DappsErrors::DappsErrors(int _errorCode, std::string _desc)
{
	m_errorCode = _errorCode;
	m_desc = _desc;
}

int dapps::DappsErrors::getErrorCode()
{
	return m_errorCode;
}

std::string dapps::DappsErrors::getDescription()
{
	return m_desc;
}

std::string dapps::DappsErrors::getJSONString()
{
	if(m_jsonStr.empty())
	{
		m_jsonStr = "{\"error_code\": " + StringUtils::toString(m_errorCode) + ", \"description\": \"" + m_desc + "\"}";
	}
	return m_jsonStr;
}

dapps::DappsErrors* dapps::DappsErrors::INVALID_REQUEST_URI = new DappsErrors(1, "Invalid request URI. No such application was found.");
dapps::DappsErrors* dapps::DappsErrors::INVALID_EXECUTABLE_FOR_APP = new DappsErrors(2, "Invalid executable. Executable not found or permission denied.");
