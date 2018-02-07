#ifndef SOCKET_H
#define SOCKET_H

#include "ipendpoint.h"


#include <QMutex>
#include <QTcpSocket>

class SocketBase
{
public:
    SocketBase();


    virtual void setup(IpEndPoint ipEndPoint);


    void start();
    void stop();

protected:


   // QThread m_socketThread;
    QMutex  m_socketMutex;
};

#endif // SOCKET_H
