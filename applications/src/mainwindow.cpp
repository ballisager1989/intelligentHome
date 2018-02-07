#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "deviceswidget.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->ui_menubar->hide();


    initMenuWidgets();
}

void MainWindow::initMenuWidgets()
{
    m_devicesWidget = new DevicesWidget(this);
    m_devicesWidget->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotShowDevicesWidget()
{
    qDebug()<< "Showing devices";

    centralWidget()->hide();
    setCentralWidget(m_devicesWidget);
    centralWidget()->show();
}

void MainWindow::slotShowSurveillanceWidget()
{
    qDebug()<< "slotShowSurveillanceWidget not implmented yet!";

}

void MainWindow::slotShowSettingsWidget()
{
    qDebug()<< "slotShowSettingsWidget not implmented yet!";
}
