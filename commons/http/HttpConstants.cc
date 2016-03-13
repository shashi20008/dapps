#include "HttpConstants.h"

std::map<const int, const char*>* dapps::HttpConstants::m_statusMap = NULL;

void dapps::HttpConstants::initialize()
{
	if(m_statusMap == NULL)
	{
		m_statusMap = new std::map<const int, const char*>();
		m_statusMap->insert(std::pair<const int, const char*>(HTTP_STATUS_CODE_CONTINUE, HTTP_STATUS_MESSAGE_CONTINUE));
		m_statusMap->insert(std::pair<const int, const char*>(HTTP_STATUS_CODE_SWITCHING_PROTOCOLS, HTTP_STATUS_MESSAGE_SWITCHING_PROTOCOLS));
		m_statusMap->insert(std::pair<const int, const char*>(HTTP_STATUS_CODE_OK, HTTP_STATUS_MESSAGE_OK));
		m_statusMap->insert(std::pair<const int, const char*>(HTTP_STATUS_CODE_CREATED, HTTP_STATUS_MESSAGE_CREATED));
		m_statusMap->insert(std::pair<const int, const char*>(HTTP_STATUS_CODE_NON_AUTHORITATIVE_INFORMATION, HTTP_STATUS_MESSAGE_NON_AUTHORITATIVE_INFORMATION));
		m_statusMap->insert(std::pair<const int, const char*>(HTTP_STATUS_CODE_NO_CONTENT, HTTP_STATUS_MESSAGE_NO_CONTENT));
		m_statusMap->insert(std::pair<const int, const char*>(HTTP_STATUS_CODE_RESET_CONTENT, HTTP_STATUS_MESSAGE_RESET_CONTENT));
		m_statusMap->insert(std::pair<const int, const char*>(HTTP_STATUS_CODE_PARTIAL_CONTENT, HTTP_STATUS_MESSAGE_PARTIAL_CONTENT));
		m_statusMap->insert(std::pair<const int, const char*>(HTTP_STATUS_CODE_MULTIPLE_CHOICES, HTTP_STATUS_MESSAGE_MULTIPLE_CHOICES));
		m_statusMap->insert(std::pair<const int, const char*>(HTTP_STATUS_CODE_MOVED_PERMANENTLY, HTTP_STATUS_MESSAGE_MOVED_PERMANENTLY));
		m_statusMap->insert(std::pair<const int, const char*>(HTTP_STATUS_CODE_FOUND, HTTP_STATUS_MESSAGE_FOUND));
		m_statusMap->insert(std::pair<const int, const char*>(HTTP_STATUS_CODE_SEE_OTHER, HTTP_STATUS_MESSAGE_SEE_OTHER));
		m_statusMap->insert(std::pair<const int, const char*>(HTTP_STATUS_CODE_NOT_MODIFIED, HTTP_STATUS_MESSAGE_NOT_MODIFIED));
		m_statusMap->insert(std::pair<const int, const char*>(HTTP_STATUS_CODE_USE_PROXY, HTTP_STATUS_MESSAGE_USE_PROXY));
		m_statusMap->insert(std::pair<const int, const char*>(HTTP_STATUS_CODE_SWITCH_PROXY, HTTP_STATUS_MESSAGE_SWITCH_PROXY));
		m_statusMap->insert(std::pair<const int, const char*>(HTTP_STATUS_CODE_TEMPORARY_REDIRECT, HTTP_STATUS_MESSAGE_TEMPORARY_REDIRECT));
		m_statusMap->insert(std::pair<const int, const char*>(HTTP_STATUS_CODE_PERMANENT_REDIRECT, HTTP_STATUS_MESSAGE_PERMANENT_REDIRECT));
		
		m_statusMap->insert(std::pair<const int, const char*>(HTTP_STATUS_CODE_BAD_REQUEST, HTTP_STATUS_MESSAGE_BAD_REQUEST));
		m_statusMap->insert(std::pair<const int, const char*>(HTTP_STATUS_CODE_UNAUTHORIZED, HTTP_STATUS_MESSAGE_UNAUTHORIZED));
		m_statusMap->insert(std::pair<const int, const char*>(HTTP_STATUS_CODE_PAYMENT_REQUIRED, HTTP_STATUS_MESSAGE_PAYMENT_REQUIRED));
		m_statusMap->insert(std::pair<const int, const char*>(HTTP_STATUS_CODE_FORBIDDEN, HTTP_STATUS_MESSAGE_FORBIDDEN));
		m_statusMap->insert(std::pair<const int, const char*>(HTTP_STATUS_CODE_NOT_FOUND, HTTP_STATUS_MESSAGE_NOT_FOUND));
		m_statusMap->insert(std::pair<const int, const char*>(HTTP_STATUS_CODE_METHOD_NOT_ALLOWED, HTTP_STATUS_MESSAGE_METHOD_NOT_ALLOWED));
		m_statusMap->insert(std::pair<const int, const char*>(HTTP_STATUS_CODE_NOT_ACCEPTABLE, HTTP_STATUS_MESSAGE_NOT_ACCEPTABLE));
		m_statusMap->insert(std::pair<const int, const char*>(HTTP_STATUS_CODE_PROXY_AUTHENTICATION_REQUIRED, HTTP_STATUS_MESSAGE_PROXY_AUTHENTICATION_REQUIRED));
		m_statusMap->insert(std::pair<const int, const char*>(HTTP_STATUS_CODE_REQUEST_TIMEOUT, HTTP_STATUS_MESSAGE_REQUEST_TIMEOUT));
		m_statusMap->insert(std::pair<const int, const char*>(HTTP_STATUS_CODE_CONFLICT, HTTP_STATUS_MESSAGE_CONFLICT));
		m_statusMap->insert(std::pair<const int, const char*>(HTTP_STATUS_CODE_GONE, HTTP_STATUS_MESSAGE_GONE));
		m_statusMap->insert(std::pair<const int, const char*>(HTTP_STATUS_CODE_LENGTH_REQUIRED, HTTP_STATUS_MESSAGE_LENGTH_REQUIRED));
		m_statusMap->insert(std::pair<const int, const char*>(HTTP_STATUS_CODE_PRECONDITION_FAILED, HTTP_STATUS_MESSAGE_PRECONDITION_FAILED));
		m_statusMap->insert(std::pair<const int, const char*>(HTTP_STATUS_CODE_PAYLOAD_TOO_LARGE, HTTP_STATUS_MESSAGE_PAYLOAD_TOO_LARGE));
		m_statusMap->insert(std::pair<const int, const char*>(HTTP_STATUS_CODE_URI_TOO_LONG, HTTP_STATUS_MESSAGE_URI_TOO_LONG));
		m_statusMap->insert(std::pair<const int, const char*>(HTTP_STATUS_CODE_UNSUPPORTED_MEDIA_TYPE, HTTP_STATUS_MESSAGE_UNSUPPORTED_MEDIA_TYPE));
		m_statusMap->insert(std::pair<const int, const char*>(HTTP_STATUS_CODE_RANGE_NOT_SATISFIABLE, HTTP_STATUS_MESSAGE_RANGE_NOT_SATISFIABLE));
		m_statusMap->insert(std::pair<const int, const char*>(HTTP_STATUS_CODE_EXPECTATION_FAILED, HTTP_STATUS_MESSAGE_EXPECTATION_FAILED));
		m_statusMap->insert(std::pair<const int, const char*>(HTTP_STATUS_CODE_I_M_A_TEAPOT, HTTP_STATUS_MESSAGE_I_M_A_TEAPOT));
		m_statusMap->insert(std::pair<const int, const char*>(HTTP_STATUS_CODE_MISDIRECTED_REQUEST, HTTP_STATUS_MESSAGE_MISDIRECTED_REQUEST));
		m_statusMap->insert(std::pair<const int, const char*>(HTTP_STATUS_CODE_UPGRADE_REQUIRED, HTTP_STATUS_MESSAGE_UPGRADE_REQUIRED));
		m_statusMap->insert(std::pair<const int, const char*>(HTTP_STATUS_CODE_PRECONDITION_REQUIRED, HTTP_STATUS_MESSAGE_PRECONDITION_REQUIRED));
		m_statusMap->insert(std::pair<const int, const char*>(HTTP_STATUS_CODE_TOO_MANY_REQUESTS, HTTP_STATUS_MESSAGE_TOO_MANY_REQUESTS));
		m_statusMap->insert(std::pair<const int, const char*>(HTTP_STATUS_CODE_REQUEST_HEADER_FIELDS_TOO_LARGE, HTTP_STATUS_MESSAGE_REQUEST_HEADER_FIELDS_TOO_LARGE));
		m_statusMap->insert(std::pair<const int, const char*>(HTTP_STATUS_CODE_INTERNAL_SERVER_ERROR, HTTP_STATUS_MESSAGE_INTERNAL_SERVER_ERROR));
		m_statusMap->insert(std::pair<const int, const char*>(HTTP_STATUS_CODE_NOT_IMPLEMENTED, HTTP_STATUS_MESSAGE_NOT_IMPLEMENTED));
		m_statusMap->insert(std::pair<const int, const char*>(HTTP_STATUS_CODE_BAD_GATEWAY, HTTP_STATUS_MESSAGE_BAD_GATEWAY));
		m_statusMap->insert(std::pair<const int, const char*>(HTTP_STATUS_CODE_SERVICE_UNAVILABLE, HTTP_STATUS_MESSAGE_SERVICE_UNAVILABLE));
		m_statusMap->insert(std::pair<const int, const char*>(HTTP_STATUS_CODE_GATEWAY_TIMEOUT, HTTP_STATUS_MESSAGE_GATEWAY_TIMEOUT));
		m_statusMap->insert(std::pair<const int, const char*>(HTTP_STATUS_CODE_HTTP_VERSION_NOT_SUPPORTED, HTTP_STATUS_MESSAGE_HTTP_VERSION_NOT_SUPPORTED));
		m_statusMap->insert(std::pair<const int, const char*>(HTTP_STATUS_CODE_NOT_EXTENDED, HTTP_STATUS_MESSAGE_NOT_EXTENDED));
		m_statusMap->insert(std::pair<const int, const char*>(HTTP_STATUS_CODE_NETWORK_AUTHENTICATION_REQUIRED, HTTP_STATUS_MESSAGE_NETWORK_AUTHENTICATION_REQUIRED));
		
	}
}

const char* dapps::HttpConstants::getStatusMessage(const int statusCode)
{
	if(HttpConstants::m_statusMap == NULL)
	{
		HttpConstants::initialize();
	}
	// @TODO: return empty here
	const char* message = NULL;
	std::map<const int, const char*>::iterator it = m_statusMap->find(statusCode);
	if(it != m_statusMap->end())
	{
		message = it->second;
	}
	return message; 
}

const int dapps::HttpConstants::HTTP_STATUS_CODE_CONTINUE = 100;
const int dapps::HttpConstants::HTTP_STATUS_CODE_SWITCHING_PROTOCOLS = 101;

//2XX
const int dapps::HttpConstants::HTTP_STATUS_CODE_OK = 200;
const int dapps::HttpConstants::HTTP_STATUS_CODE_CREATED = 201;
const int dapps::HttpConstants::HTTP_STATUS_CODE_ACCEPTED = 202;
const int dapps::HttpConstants::HTTP_STATUS_CODE_NON_AUTHORITATIVE_INFORMATION = 203;
const int dapps::HttpConstants::HTTP_STATUS_CODE_NO_CONTENT = 204;
const int dapps::HttpConstants::HTTP_STATUS_CODE_RESET_CONTENT = 205;
const int dapps::HttpConstants::HTTP_STATUS_CODE_PARTIAL_CONTENT = 206;

//3XX
const int dapps::HttpConstants::HTTP_STATUS_CODE_MULTIPLE_CHOICES = 300;
const int dapps::HttpConstants::HTTP_STATUS_CODE_MOVED_PERMANENTLY = 301;
const int dapps::HttpConstants::HTTP_STATUS_CODE_FOUND = 302;
const int dapps::HttpConstants::HTTP_STATUS_CODE_SEE_OTHER = 303;
const int dapps::HttpConstants::HTTP_STATUS_CODE_NOT_MODIFIED = 304;
const int dapps::HttpConstants::HTTP_STATUS_CODE_USE_PROXY = 305;
const int dapps::HttpConstants::HTTP_STATUS_CODE_SWITCH_PROXY = 306;
const int dapps::HttpConstants::HTTP_STATUS_CODE_TEMPORARY_REDIRECT = 307;
const int dapps::HttpConstants::HTTP_STATUS_CODE_PERMANENT_REDIRECT = 308;

//4XX
const int dapps::HttpConstants::HTTP_STATUS_CODE_BAD_REQUEST = 400;
const int dapps::HttpConstants::HTTP_STATUS_CODE_UNAUTHORIZED = 401;
const int dapps::HttpConstants::HTTP_STATUS_CODE_PAYMENT_REQUIRED = 402;
const int dapps::HttpConstants::HTTP_STATUS_CODE_FORBIDDEN = 403;
const int dapps::HttpConstants::HTTP_STATUS_CODE_NOT_FOUND = 404;
const int dapps::HttpConstants::HTTP_STATUS_CODE_METHOD_NOT_ALLOWED = 405;
const int dapps::HttpConstants::HTTP_STATUS_CODE_NOT_ACCEPTABLE = 406;
const int dapps::HttpConstants::HTTP_STATUS_CODE_PROXY_AUTHENTICATION_REQUIRED = 407;
const int dapps::HttpConstants::HTTP_STATUS_CODE_REQUEST_TIMEOUT = 408;
const int dapps::HttpConstants::HTTP_STATUS_CODE_CONFLICT = 409;
const int dapps::HttpConstants::HTTP_STATUS_CODE_GONE = 410;
const int dapps::HttpConstants::HTTP_STATUS_CODE_LENGTH_REQUIRED = 411;
const int dapps::HttpConstants::HTTP_STATUS_CODE_PRECONDITION_FAILED = 412;
const int dapps::HttpConstants::HTTP_STATUS_CODE_PAYLOAD_TOO_LARGE = 413;
const int dapps::HttpConstants::HTTP_STATUS_CODE_URI_TOO_LONG = 414;
const int dapps::HttpConstants::HTTP_STATUS_CODE_UNSUPPORTED_MEDIA_TYPE = 415;
const int dapps::HttpConstants::HTTP_STATUS_CODE_RANGE_NOT_SATISFIABLE = 416;
const int dapps::HttpConstants::HTTP_STATUS_CODE_EXPECTATION_FAILED = 417;
const int dapps::HttpConstants::HTTP_STATUS_CODE_I_M_A_TEAPOT = 418; //?????
const int dapps::HttpConstants::HTTP_STATUS_CODE_MISDIRECTED_REQUEST = 421;
const int dapps::HttpConstants::HTTP_STATUS_CODE_UPGRADE_REQUIRED = 426;
const int dapps::HttpConstants::HTTP_STATUS_CODE_PRECONDITION_REQUIRED = 428;
const int dapps::HttpConstants::HTTP_STATUS_CODE_TOO_MANY_REQUESTS = 429;
const int dapps::HttpConstants::HTTP_STATUS_CODE_REQUEST_HEADER_FIELDS_TOO_LARGE = 431;

//5XX
const int dapps::HttpConstants::HTTP_STATUS_CODE_INTERNAL_SERVER_ERROR = 500;
const int dapps::HttpConstants::HTTP_STATUS_CODE_NOT_IMPLEMENTED = 501;
const int dapps::HttpConstants::HTTP_STATUS_CODE_BAD_GATEWAY = 502;
const int dapps::HttpConstants::HTTP_STATUS_CODE_SERVICE_UNAVILABLE = 503;
const int dapps::HttpConstants::HTTP_STATUS_CODE_GATEWAY_TIMEOUT = 504;
const int dapps::HttpConstants::HTTP_STATUS_CODE_HTTP_VERSION_NOT_SUPPORTED = 505;
const int dapps::HttpConstants::HTTP_STATUS_CODE_NOT_EXTENDED = 510;
const int dapps::HttpConstants::HTTP_STATUS_CODE_NETWORK_AUTHENTICATION_REQUIRED = 511;

// Messages
// 1XX
const char* dapps::HttpConstants::HTTP_STATUS_MESSAGE_CONTINUE = "Continue";
const char* dapps::HttpConstants::HTTP_STATUS_MESSAGE_SWITCHING_PROTOCOLS = "Switching Protocols";

//2XX Messages
const char* dapps::HttpConstants::HTTP_STATUS_MESSAGE_OK = "OK";
const char* dapps::HttpConstants::HTTP_STATUS_MESSAGE_CREATED = "Created";
const char* dapps::HttpConstants::HTTP_STATUS_MESSAGE_ACCEPTED = "Accepted";
const char* dapps::HttpConstants::HTTP_STATUS_MESSAGE_NON_AUTHORITATIVE_INFORMATION = "Non-Authoritative Information";
const char* dapps::HttpConstants::HTTP_STATUS_MESSAGE_NO_CONTENT = "No Content";
const char* dapps::HttpConstants::HTTP_STATUS_MESSAGE_RESET_CONTENT = "Reset Content";
const char* dapps::HttpConstants::HTTP_STATUS_MESSAGE_PARTIAL_CONTENT = "Partial Content";

//3XX
const char* dapps::HttpConstants::HTTP_STATUS_MESSAGE_MULTIPLE_CHOICES = "Multiple Choices";
const char* dapps::HttpConstants::HTTP_STATUS_MESSAGE_MOVED_PERMANENTLY = "Moved Permanently";
const char* dapps::HttpConstants::HTTP_STATUS_MESSAGE_FOUND = "Found";
const char* dapps::HttpConstants::HTTP_STATUS_MESSAGE_SEE_OTHER = "See Other";
const char* dapps::HttpConstants::HTTP_STATUS_MESSAGE_NOT_MODIFIED = "Not Modified";
const char* dapps::HttpConstants::HTTP_STATUS_MESSAGE_USE_PROXY = "Use Proxy";
const char* dapps::HttpConstants::HTTP_STATUS_MESSAGE_SWITCH_PROXY = "Switch Proxy";
const char* dapps::HttpConstants::HTTP_STATUS_MESSAGE_TEMPORARY_REDIRECT = "Temporary Redirect";
const char* dapps::HttpConstants::HTTP_STATUS_MESSAGE_PERMANENT_REDIRECT = "Permanent Redirect";

//4XX
const char* dapps::HttpConstants::HTTP_STATUS_MESSAGE_BAD_REQUEST = "Bad Request";
const char* dapps::HttpConstants::HTTP_STATUS_MESSAGE_UNAUTHORIZED = "Unauthorized";
const char* dapps::HttpConstants::HTTP_STATUS_MESSAGE_PAYMENT_REQUIRED = "Payment Required";
const char* dapps::HttpConstants::HTTP_STATUS_MESSAGE_FORBIDDEN = "Forbidden";
const char* dapps::HttpConstants::HTTP_STATUS_MESSAGE_NOT_FOUND = "Not Found";
const char* dapps::HttpConstants::HTTP_STATUS_MESSAGE_METHOD_NOT_ALLOWED = "Method Not Allowed";
const char* dapps::HttpConstants::HTTP_STATUS_MESSAGE_NOT_ACCEPTABLE = "Not Acceptable";
const char* dapps::HttpConstants::HTTP_STATUS_MESSAGE_PROXY_AUTHENTICATION_REQUIRED = "Proxy Authentication Required";
const char* dapps::HttpConstants::HTTP_STATUS_MESSAGE_REQUEST_TIMEOUT = "Request Timeout";
const char* dapps::HttpConstants::HTTP_STATUS_MESSAGE_CONFLICT = "Conflict";
const char* dapps::HttpConstants::HTTP_STATUS_MESSAGE_GONE = "Gone";
const char* dapps::HttpConstants::HTTP_STATUS_MESSAGE_LENGTH_REQUIRED = "Length Required";
const char* dapps::HttpConstants::HTTP_STATUS_MESSAGE_PRECONDITION_FAILED = "Precondition Required";
const char* dapps::HttpConstants::HTTP_STATUS_MESSAGE_PAYLOAD_TOO_LARGE = "Payload Too Large";
const char* dapps::HttpConstants::HTTP_STATUS_MESSAGE_URI_TOO_LONG = "URI Too Long";
const char* dapps::HttpConstants::HTTP_STATUS_MESSAGE_UNSUPPORTED_MEDIA_TYPE = "Unsupported Media Type";
const char* dapps::HttpConstants::HTTP_STATUS_MESSAGE_RANGE_NOT_SATISFIABLE = "Range Not Satisfiable";
const char* dapps::HttpConstants::HTTP_STATUS_MESSAGE_EXPECTATION_FAILED = "Expextation Failed";
const char* dapps::HttpConstants::HTTP_STATUS_MESSAGE_I_M_A_TEAPOT = "I'm A Teapot"; //?????
const char* dapps::HttpConstants::HTTP_STATUS_MESSAGE_MISDIRECTED_REQUEST = "Misdirected Request";
const char* dapps::HttpConstants::HTTP_STATUS_MESSAGE_UPGRADE_REQUIRED = "Upgrade Required";
const char* dapps::HttpConstants::HTTP_STATUS_MESSAGE_PRECONDITION_REQUIRED = "Precondition Required";
const char* dapps::HttpConstants::HTTP_STATUS_MESSAGE_TOO_MANY_REQUESTS = "Too Many Requests";
const char* dapps::HttpConstants::HTTP_STATUS_MESSAGE_REQUEST_HEADER_FIELDS_TOO_LARGE = "Request Header Fields Too Large";

//5XX
const char* dapps::HttpConstants::HTTP_STATUS_MESSAGE_INTERNAL_SERVER_ERROR = "Internal Server Error";
const char* dapps::HttpConstants::HTTP_STATUS_MESSAGE_NOT_IMPLEMENTED = "Not Implemented";
const char* dapps::HttpConstants::HTTP_STATUS_MESSAGE_BAD_GATEWAY = "Bad Gateway";
const char* dapps::HttpConstants::HTTP_STATUS_MESSAGE_SERVICE_UNAVILABLE = "Service Unavailable";
const char* dapps::HttpConstants::HTTP_STATUS_MESSAGE_GATEWAY_TIMEOUT = "Gateway Timeout";
const char* dapps::HttpConstants::HTTP_STATUS_MESSAGE_HTTP_VERSION_NOT_SUPPORTED = "HTTP Version Not Supported";
const char* dapps::HttpConstants::HTTP_STATUS_MESSAGE_NOT_EXTENDED = "Not Extended";
const char* dapps::HttpConstants::HTTP_STATUS_MESSAGE_NETWORK_AUTHENTICATION_REQUIRED = "Network Authentication Required";

const char* dapps::HttpConstants::HTTP_HEADER_ACCEPT = "Accept";
const char* dapps::HttpConstants::HTTP_HEADER_ACCEPT_CHARSET = "Accept-Charset";
const char* dapps::HttpConstants::HTTP_HEADER_ACCEPT_ENCODING = "Accept-Encoding";
const char* dapps::HttpConstants::HTTP_HEADER_ACCEPT_LANGAUGE = "Accept-Language";
const char* dapps::HttpConstants::HTTP_HEADER_AUTHORIZATION = "Authorization";
const char* dapps::HttpConstants::HTTP_HEADER_CACHE_CONTROL = "Cache-Control";
const char* dapps::HttpConstants::HTTP_HEADER_CONNECTION = "Connection";
const char* dapps::HttpConstants::HTTP_HEADER_COOKIE = "Cookie";
const char* dapps::HttpConstants::HTTP_HEADER_CONTENT_LENGTH = "Content-Length";
const char* dapps::HttpConstants::HTTP_HEADER_CONTENT_MD5 = "Content-MD5";
const char* dapps::HttpConstants::HTTP_HEADER_CONTENT_TYPE = "Content-Type";
const char* dapps::HttpConstants::HTTP_HEADER_DATE = "Date";
const char* dapps::HttpConstants::HTTP_HEADER_EXPECT = "Expect";
const char* dapps::HttpConstants::HTTP_HEADER_FORWARDED = "Forwarded";
const char* dapps::HttpConstants::HTTP_HEADER_FROM = "From";
const char* dapps::HttpConstants::HTTP_HEADER_HOST = "Host";
const char* dapps::HttpConstants::HTTP_HEADER_IF_MATCH = "If-Match";
const char* dapps::HttpConstants::HTTP_HEADER_IF_MODIFIED_SINCE = "If-Modified-Since";
const char* dapps::HttpConstants::HTTP_HEADER_IF_NONE_MATCH = "If-None-Match";
const char* dapps::HttpConstants::HTTP_HEADER_IF_RANGE = "If-Range";
const char* dapps::HttpConstants::HTTP_HEADER_IF_UNMODIFIED_SINCE = "If-Unmodified-Since";
const char* dapps::HttpConstants::HTTP_HEADER_MAX_FORWARDS = "Max-Forwards";
const char* dapps::HttpConstants::HTTP_HEADER_ORIGIN = "Origin";
const char* dapps::HttpConstants::HTTP_HEADER_PRAGMA = "Pragma";
const char* dapps::HttpConstants::HTTP_HEADER_PROXY_AUTHORIZATION = "Proxy-Authorization";
const char* dapps::HttpConstants::HTTP_HEADER_RANGE = "Range";
const char* dapps::HttpConstants::HTTP_HEADER_REFERER = "Referer";
const char* dapps::HttpConstants::HTTP_HEADER_TE = "TE";
const char* dapps::HttpConstants::HTTP_HEADER_USER_AGENT = "User-Agent";
const char* dapps::HttpConstants::HTTP_HEADER_UPGRADE = "Upgrade";
const char* dapps::HttpConstants::HTTP_HEADER_VIA = "Via";
const char* dapps::HttpConstants::HTTP_HEADER_WARNING = "Warning";
const char* dapps::HttpConstants::HTTP_HEADER_X_REQUESTED_WITH = "X-Requested-With";
const char* dapps::HttpConstants::HTTP_HEADER_X_FORWARDED_FOR = "X-Forwarded-For";
const char* dapps::HttpConstants::HTTP_HEADER_X_FORWARDED_HOST = "X-Forwarded-Host";
const char* dapps::HttpConstants::HTTP_HEADER_X_FORWARDED_PROTO = "X-Forwarded-Proto";
const char* dapps::HttpConstants::HTTP_HEADER_X_HTTP_METHOD_OVERRIDE = "X-Http-Method-Override";

const char* dapps::HttpConstants::HTTP_HEADER_ACCESS_CONTROL_ALLOW_ORIGIN = "Access-Control-Allow-Origin";
const char* dapps::HttpConstants::HTTP_HEADER_ACCEPT_PATCH = "Accept-Patch";
const char* dapps::HttpConstants::HTTP_HEADER_ACCEPT_RANGES = "Accept-Ranges";
const char* dapps::HttpConstants::HTTP_HEADER_AGE = "Age";
const char* dapps::HttpConstants::HTTP_HEADER_ALLOW = "Allow";
const char* dapps::HttpConstants::HTTP_HEADER_CONTENT_DISPOSITION = "Content-Disposition";
const char* dapps::HttpConstants::HTTP_HEADER_CONTENT_ENCODING = "Content-Encoding";
const char* dapps::HttpConstants::HTTP_HEADER_CONTENT_LANGUAGE = "Content-Language";
const char* dapps::HttpConstants::HTTP_HEADER_CONTENT_LOCATION = "Content-Location";
const char* dapps::HttpConstants::HTTP_HEADER_CONTENT_RANGE = "Content-Range";
const char* dapps::HttpConstants::HTTP_HEADER_ETAG = "ETag";
const char* dapps::HttpConstants::HTTP_HEADER_EXPIRES = "Expires";
const char* dapps::HttpConstants::HTTP_HEADER_LAST_MODIFIED = "Last-Modified";
const char* dapps::HttpConstants::HTTP_HEADER_LINK = "Link";
const char* dapps::HttpConstants::HTTP_HEADER_LOCATION = "Location";
const char* dapps::HttpConstants::HTTP_HEADER_P3P = "P3P";
const char* dapps::HttpConstants::HTTP_HEADER_PROXY_AUTHENTICATE = "Proxy-Authenticate";
const char* dapps::HttpConstants::HTTP_HEADER_PUBLIC_KEY_PINS = "Public-Key-Pins";
const char* dapps::HttpConstants::HTTP_HEADER_RETRY_AFTER = "Retry-After";
const char* dapps::HttpConstants::HTTP_HEADER_SERVER = "Server";
const char* dapps::HttpConstants::HTTP_HEADER_SET_COOKIE = "Set-Cookie";
const char* dapps::HttpConstants::HTTP_HEADER_STRICT_TRANSPORT_SECURITY = "Strict-Transport-Security";
const char* dapps::HttpConstants::HTTP_HEADER_TRAILER = "Trailer";
const char* dapps::HttpConstants::HTTP_HEADER_TRANSFER_ENCODING = "Transfer-Encoding";
const char* dapps::HttpConstants::HTTP_HEADER_TSV = "TSV";
const char* dapps::HttpConstants::HTTP_HEADER_VARY = "Vary";
const char* dapps::HttpConstants::HTTP_HEADER_WWW_AUTHENTICATE = "WWW-Authenticate";
const char* dapps::HttpConstants::HTTP_HEADER_X_POWERED_BY = "X-Powered-By";
