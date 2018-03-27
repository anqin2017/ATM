#include "mainwindow.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setupUi(this);
    access_ = new NetWorkAccess;
    QMap <QString,QString> params_send;
    params_send.insert("username","2018");
    QString  upload_file("1.png");
    QString  new_file("2018.png");
    access_ ->InitNetWorkAccess("http://192.168.1.113:8000/main/api/add/image/","aqyao","anqin2018anqin2018");
    access_ ->InitPostDataFrame(params_send,upload_file,new_file,":/new/prefix1/icon/1.png");
    //access_ ->Post();
//    QFile imagefile(":/new/prefix1/icon/1.png");
//    if(!imagefile.open(QIODevice::ReadOnly))
//    {
//        cerr << "open imagefile failed" << endl;
//    }
//    qDebug() <<"imagefile size : "  << imagefile.size();

}

void MainWindow::on_pushButton_clicked()
{
    textEdit ->setText(access_ ->string_);
}
