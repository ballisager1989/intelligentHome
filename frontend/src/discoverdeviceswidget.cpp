#include "discoverdeviceswidget.h"
#include "ui_discoverdeviceswidget.h"

DiscoverDevicesWidget::DiscoverDevicesWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DiscoverDevicesWidget)
{
    ui->setupUi(this);
}

DiscoverDevicesWidget::~DiscoverDevicesWidget()
{
    delete ui;
}
