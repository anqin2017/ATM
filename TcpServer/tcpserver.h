#ifndef TCPSERVER_H
#define TCPSERVER_H
#include <QIODevice>
#include <QTcpSocket>
#include <QTcpServer>
#include "ui_tcpserver.h"

class TcpServer : public QWidget, private Ui::TcpServer
{
    Q_OBJECT

public:
    explicit TcpServer(QWidget *parent = 0);

    ~TcpServer();

public slots:

    void SlotNewConnection();

    void SlotReadyRead();

private:
    QTcpServer* tcp_Server_;
    QTcpSocket* tcp_Socket_;

};

#endif // TCPSERVER_H
