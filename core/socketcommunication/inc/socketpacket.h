#ifndef SOCKETPACKET_H
#define SOCKETPACKET_H

#include <QByteArray>
class SocketPacket
{
public:
    SocketPacket();


private:
    quint64 m_packetId = 0;
    quint64 m_typeId = 0;
    QByteArray m_data;

};

#endif // SOCKETPACKET_H
