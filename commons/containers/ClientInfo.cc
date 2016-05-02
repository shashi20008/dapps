#include "ClientInfo.h"

dapps::ClientInfo::ClientInfo(AbstractClientSocket* _client, unsigned long timeout)
{
    client = _client;
    startTime = time(NULL);
    killAt = startTime + timeout;
}