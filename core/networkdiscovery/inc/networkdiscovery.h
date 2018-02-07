#ifndef NETWORKDISCOVERY_H
#define NETWORKDISCOVERY_H


//core
#include "networkdiscovery/src/endpoint_parameters.hpp"
#include "networkdiscovery/src/endpoint.hpp"


//Qt
#include <QObject>

namespace networkdiscovery {


class NetworkDiscovery : public QObject
{
    Q_OBJECT

public:
    explicit NetworkDiscovery(QObject *parent = nullptr);

    void init(bool discover, bool discoverable, int applicationId, int port);
    void start(QString getData);
    void stop();


    QString getData() const;
    void setData(const QString &getData);

signals:

public slots:

private:
    EndpointParameters m_discoveryParamters;
    Endpoint m_discoveryEndpoint;

    QString m_data;

};

}
#endif // NETWORKDISCOVERY_H
