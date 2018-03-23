#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QtNetwork/QTcpSocket>
#include "ui_tcpclient.h"

class TcpClient : public QWidget, private Ui::TcpClient
{
    Q_OBJECT


public:
    explicit TcpClient(QWidget *parent = 0);   


public slots:
    void SlotReadyRead();

    void SlotSendInfo();//send the info to server

private:
    QTcpSocket* tcpClientSocket_;


};

#endif // TCPCLIENT_H
