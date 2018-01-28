#include "deviceswidget.h"
#include "ui_deviceswidget.h"

DevicesWidget::DevicesWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DevicesWidget)
{
    ui->setupUi(this);
}

DevicesWidget::~DevicesWidget()
{
    delete ui;
}
