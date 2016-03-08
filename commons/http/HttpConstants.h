#ifndef __dapps_HTTP_CONSTANTS__
#define __dapps_HTTP_CONSTANTS__

#include <string>

namespace dapps
{
	class HttpConstants
	{
		public:
			// HTTP Status codes
			// 1XX
			static const int HTTP_STATUS_CODE_CONTINUE; //100
			static const int HTTP_STATUS_CODE_SWITCHING_PROTOCOLS; //101
			
			//2XX
			static const int HTTP_STATUS_CODE_OK; //200
			static const int HTTP_STATUS_CODE_CREATED; //201
			static const int HTTP_STATUS_CODE_ACCEPTED; //202
			static const int HTTP_STATUS_CODE_NON_AUTHORITATIVE_INFORMATION; //203
			static const int HTTP_STATUS_CODE_NO_CONTENT; //204
			static const int HTTP_STATUS_CODE_RESET_CONTENT; //205
			static const int HTTP_STATUS_CODE_PARTIAL_CONTENT; //206
			
			//3XX
			static const int HTTP_STATUS_CODE_MULTIPLE_CHOICES; //300
			static const int HTTP_STATUS_CODE_MOVED_PERMANENTLY; //301
			static const int HTTP_STATUS_CODE_FOUND; //302
			static const int HTTP_STATUS_CODE_SEE_OTHER; //303
			static const int HTTP_STATUS_CODE_NOT_MODIFIED; //304
			static const int HTTP_STATUS_CODE_USE_PROXY; //305
			static const int HTTP_STATUS_CODE_SWITCH_PROXY; //306
			static const int HTTP_STATUS_CODE_TEMPORARY_REDIRECT; //307
			static const int HTTP_STATUS_CODE_PERMANENT_REDIRECT; //308
			
			//4XX
			static const int HTTP_STATUS_CODE_BAD_REQUEST; //400
			static const int HTTP_STATUS_CODE_UNAUTHORIZED; //401
			static const int HTTP_STATUS_CODE_PAYMENT_REQUIRED; //402
			static const int HTTP_STATUS_CODE_FORBIDDEN; //403
			static const int HTTP_STATUS_CODE_NOT_FOUND; //404
			static const int HTTP_STATUS_CODE_METHOD_NOT_ALLOWED; //405
			static const int HTTP_STATUS_CODE_NOT_ACCEPTABLE; //406
			static const int HTTP_STATUS_CODE_PROXY_AUTHENTICATION_REQUIRED; //407
			static const int HTTP_STATUS_CODE_REQUEST_TIMEOUT; // 408
			static const int HTTP_STATUS_CODE_CONFLICT; //409
			static const int HTTP_STATUS_CODE_GONE; //410
			static const int HTTP_STATUS_CODE_LENGTH_REQUIRED; // 411
			static const int HTTP_STATUS_CODE_PRECONDITION_FAILED; // 412
			static const int HTTP_STATUS_CODE_PAYLOAD_TOO_LARGE; //413
			static const int HTTP_STATUS_CODE_URI_TOO_LONG; //414
			static const int HTTP_STATUS_CODE_UNSUPPORTED_MEDIA_TYPE; // 415
			static const int HTTP_STATUS_CODE_RANGE_NOT_SATISFIABLE; // 416
			static const int HTTP_STATUS_CODE_EXPECTATION_FAILED; //417
			static const int HTTP_STATUS_CODE_I_M_A_TEAPOT; // 418 //?????
			static const int HTTP_STATUS_CODE_MISDIRECTED_REQUEST; // 421
			static const int HTTP_STATUS_CODE_UPGRADE_REQUIRED; //426
			static const int HTTP_STATUS_CODE_PRECONDITION_REQUIRED; // 428
			static const int HTTP_STATUS_CODE_TOO_MANY_REQUESTS; // 429
			static const int HTTP_STATUS_CODE_REQUEST_HEADER_FIELDS_TOO_LARGE; // 431
			
			//5XX
			static const int HTTP_STATUS_CODE_INTERNAL_SERVER_ERROR; // 500
			static const int HTTP_STATUS_CODE_NOT_IMPLEMENTED; // 501
			static const int HTTP_STATUS_CODE_BAD_GATEWAY; // 502
			static const int HTTP_STATUS_CODE_SERVICE_UNAVILABLE; // 503
			static const int HTTP_STATUS_CODE_GATEWAY_TIMEOUT; // 504
			static const int HTTP_STATUS_CODE_HTTP_VERSION_NOT_SUPPORTED; // 505
			static const int HTTP_STATUS_CODE_NOT_EXTENDED; // 510
			static const int HTTP_STATUS_CODE_NETWORK_AUTHENTICATION_REQUIRED; // 511
			
			// Messages
			// 1XX
			static const char* HTTP_STATUS_MESSAGE_CONTINUE; // "Continue";
			static const char* HTTP_STATUS_MESSAGE_SWITCHING_PROTOCOLS; // "Switching Protocols";

			//2XX Messages
			static const char* HTTP_STATUS_MESSAGE_OK; // "OK";
			static const char* HTTP_STATUS_MESSAGE_CREATED; // "Created";
			static const char* HTTP_STATUS_MESSAGE_ACCEPTED; // "Accepted";
			static const char* HTTP_STATUS_MESSAGE_NON_AUTHORITATIVE_INFORMATION; // "Non-Authoritative Information";
			static const char* HTTP_STATUS_MESSAGE_NO_CONTENT; // "No Content";
			static const char* HTTP_STATUS_MESSAGE_RESET_CONTENT; // "Reset Content";
			static const char* HTTP_STATUS_MESSAGE_PARTIAL_CONTENT; // "Partial Content";

			//3XX
			static const char* HTTP_STATUS_MESSAGE_MULTIPLE_CHOICES; // "Multiple Choices";
			static const char* HTTP_STATUS_MESSAGE_MOVED_PERMANENTLY; // "Moved Permanently";
			static const char* HTTP_STATUS_MESSAGE_FOUND; // "Found";
			static const char* HTTP_STATUS_MESSAGE_SEE_OTHER; // "See Other";
			static const char* HTTP_STATUS_MESSAGE_NOT_MODIFIED; // "Not Modified";
			static const char* HTTP_STATUS_MESSAGE_USE_PROXY; // "Use Proxy";
			static const char* HTTP_STATUS_MESSAGE_SWITCH_PROXY; // "Switch Proxy";
			static const char* HTTP_STATUS_MESSAGE_TEMPORARY_REDIRECT; // "Temporary Redirect";
			static const char* HTTP_STATUS_MESSAGE_PERMANENT_REDIRECT; // "Permanent Redirect";

			//4XX
			static const char* HTTP_STATUS_MESSAGE_BAD_REQUEST; // "Bad Request";
			static const char* HTTP_STATUS_MESSAGE_UNAUTHORIZED; // "Unauthorized";
			static const char* HTTP_STATUS_MESSAGE_PAYMENT_REQUIRED; // "Payment Required";
			static const char* HTTP_STATUS_MESSAGE_FORBIDDEN; // "Forbidden";
			static const char* HTTP_STATUS_MESSAGE_NOT_FOUND; // "Not Found";
			static const char* HTTP_STATUS_MESSAGE_METHOD_NOT_ALLOWED; // "Method Not Allowed";
			static const char* HTTP_STATUS_MESSAGE_NOT_ACCEPTABLE; // "Not Acceptable";
			static const char* HTTP_STATUS_MESSAGE_PROXY_AUTHENTICATION_REQUIRED; // "Proxy Authentication Required";
			static const char* HTTP_STATUS_MESSAGE_REQUEST_TIMEOUT; // "Request Timeout";
			static const char* HTTP_STATUS_MESSAGE_CONFLICT; // "Conflict";
			static const char* HTTP_STATUS_MESSAGE_GONE; // "Gone";
			static const char* HTTP_STATUS_MESSAGE_LENGTH_REQUIRED; // "Length Required";
			static const char* HTTP_STATUS_MESSAGE_PRECONDITION_FAILED; // "Precondition Required"
			static const char* HTTP_STATUS_MESSAGE_PAYLOAD_TOO_LARGE; // "Payload Too Large";
			static const char* HTTP_STATUS_MESSAGE_URI_TOO_LONG; // "URI Too Long";
			static const char* HTTP_STATUS_MESSAGE_UNSUPPORTED_MEDIA_TYPE; // "Unsupported Media Type";
			static const char* HTTP_STATUS_MESSAGE_RANGE_NOT_SATISFIABLE; // "Range Not Satisfiable";
			static const char* HTTP_STATUS_MESSAGE_EXPECTATION_FAILED; // "Expextation Failed";
			static const char* HTTP_STATUS_MESSAGE_I_M_A_TEAPOT; // "I'm A Teapot"; //?????
			static const char* HTTP_STATUS_MESSAGE_MISDIRECTED_REQUEST; // "Misdirected Request";
			static const char* HTTP_STATUS_MESSAGE_UPGRADE_REQUIRED; // "Upgrade Required";
			static const char* HTTP_STATUS_MESSAGE_PRECONDITION_REQUIRED; // "Precondition Required";
			static const char* HTTP_STATUS_MESSAGE_TOO_MANY_REQUESTS; // "Too Many Requests";
			static const char* HTTP_STATUS_MESSAGE_REQUEST_HEADER_FIELDS_TOO_LARGE; // "Request Header Fields Too Large";

			//5XX
			static const char* HTTP_STATUS_MESSAGE_INTERNAL_SERVER_ERROR; // "Internal Server Error";
			static const char* HTTP_STATUS_MESSAGE_NOT_IMPLEMENTED; // "Not Implemented";
			static const char* HTTP_STATUS_MESSAGE_BAD_GATEWAY; // "Bad Gateway";
			static const char* HTTP_STATUS_MESSAGE_SERVICE_UNAVILABLE; // "Service Unavailable";
			static const char* HTTP_STATUS_MESSAGE_GATEWAY_TIMEOUT; // "Gateway Timeout";
			static const char* HTTP_STATUS_MESSAGE_HTTP_VERSION_NOT_SUPPORTED; // "HTTP Version Not Supported";
			static const char* HTTP_STATUS_MESSAGE_NOT_EXTENDED; // "Not Extended";
			static const char* HTTP_STATUS_MESSAGE_NETWORK_AUTHENTICATION_REQUIRED; // "Network Authentication Required";
	};
}

#endif //__dapps_HTTP_CONSTANTS__
