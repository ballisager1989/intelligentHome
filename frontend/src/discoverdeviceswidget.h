#ifndef DISCOVERDEVICESWIDGET_H
#define DISCOVERDEVICESWIDGET_H

#include <QWidget>

namespace Ui {
class DiscoverDevicesWidget;
}

class DiscoverDevicesWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DiscoverDevicesWidget(QWidget *parent = 0);
    ~DiscoverDevicesWidget();

private:
    Ui::DiscoverDevicesWidget *ui;
};

#endif // DISCOVERDEVICESWIDGET_H
