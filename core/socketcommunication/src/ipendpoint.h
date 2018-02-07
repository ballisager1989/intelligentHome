#ifndef IPENDPOINT_H
#define IPENDPOINT_H

#include <QString>

class IpEndPoint
{
public:
    explicit IpEndPoint();

    QString getIp() const;
    void setIp(const QString &ip);

    quint16 getPort() const;
    void setPort(const quint16 &getPort);

    quint32 getSocketDescriptor() const;
    void setSocketDescriptor(const quint32 &getSocketDescriptor);

private:
    QString m_ip;
    quint16 m_port;
    quint32 m_socketDescriptor;
};

#endif // IPENDPOINT_H
