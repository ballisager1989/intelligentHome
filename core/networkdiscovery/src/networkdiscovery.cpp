#include "networkdiscovery.h"
#include <QString>

namespace networkdiscovery {


NetworkDiscovery::NetworkDiscovery(QObject *parent) : QObject(parent)
{

}

void networkdiscovery::NetworkDiscovery::init(bool discover, bool discoverable, int applicationId, int port)
{
    m_discoveryParamters.set_can_discover(discover);
    m_discoveryParamters.set_can_be_discovered(discoverable);
    m_discoveryParamters.set_application_id(applicationId);
    m_discoveryParamters.set_port(port);

}

void networkdiscovery::NetworkDiscovery::start(QString data)
{
    m_data = data;
    m_discoveryEndpoint.Start(m_discoveryParamters, data.toStdString());
}

///
/// \brief May block while waiting for discover thread to terminate
///
void networkdiscovery::NetworkDiscovery::stop()
{
    m_discoveryEndpoint.Stop(true);
}

QString NetworkDiscovery::getData() const
{
    return m_data;
}


void NetworkDiscovery::setData(const QString &data)
{
    m_data = data;
}

} //networkdiscovery namespace
