#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setupUi(this);
    access_ = new NetWorkAccess;
    access_ ->InitNetWorkAccess("http://mycode.winsightech.com/aqyao/PVT_Utility","aqyao","anqin2018anqin2018");
    access_ ->Get();
}

void MainWindow::on_pushButton_clicked()
{
    textEdit ->setText(access_ ->string_);
}
