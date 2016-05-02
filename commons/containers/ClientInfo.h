#ifndef __dapps_CLIENT_INFO__
#define __dapps_CLIENT_INFO__

#include <ctime>
#include "../sockets/AbstractClientSocket.h"
#include <map>

namespace dapps 
{
    class ClientInfo
    {
        public:
            ClientInfo(AbstractClientSocket*, unsigned long);
            ~ClientInfo();
            AbstractClientSocket* client;
            time_t startTime;
            time_t killAt;
    };

    typedef std::map <AbstractClientSocket*, ClientInfo*> ClientInfoMap;
    typedef std::pair <AbstractClientSocket*, ClientInfo*> ClientInfoPair;
}

#endif //__dapps_CLIENT_INFO__