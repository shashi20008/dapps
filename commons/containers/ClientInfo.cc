#include "ClientInfo.h"
#include <iostream>

dapps::ClientInfo::ClientInfo(AbstractClientSocket* _client, unsigned long timeout)
{
    client = _client;
    startTime = time(NULL);
    killAt = startTime + timeout;
}

dapps::ClientInfo::~ClientInfo()
{
    std::cout << "destructing ClientInfo" <<std::endl;
}