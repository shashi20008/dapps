#include "HttpConstants.h"

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

