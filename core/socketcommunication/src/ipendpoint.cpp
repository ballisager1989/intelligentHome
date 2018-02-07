#include "ipendpoint.h"

IpEndPoint::IpEndPoint()
{

}

QString IpEndPoint::getIp() const
{
    return m_ip;
}

void IpEndPoint::setIp(const QString &ip)
{
    m_ip = ip;
}

quint16 IpEndPoint::getPort() const
{
    return m_port;
}

void IpEndPoint::setPort(const quint16 &port)
{
    m_port = port;
}

quint32 IpEndPoint::getSocketDescriptor() const
{
    return m_socketDescriptor;
}

void IpEndPoint::setSocketDescriptor(const quint32 &socketDescriptor)
{
    m_socketDescriptor = socketDescriptor;
}
