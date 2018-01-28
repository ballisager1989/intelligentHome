#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


class DevicesWidget;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void slotShowDevicesWidget();
    void slotShowSurveillanceWidget();
    void slotShowSettingsWidget();

private:
    void initMenuWidgets();

    Ui::MainWindow *ui;
    DevicesWidget* m_devicesWidget;


};

#endif // MAINWINDOW_H
