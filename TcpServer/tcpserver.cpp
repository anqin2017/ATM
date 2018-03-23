#include "tcpserver.h"
#include <QMessageBox>

TcpServer::TcpServer(QWidget *parent) :
    QWidget(parent),
    tcp_Server_(NULL),
    tcp_Socket_(NULL)
{
    setupUi(this);
    tcp_Server_ = new QTcpServer(this);
    tcp_Server_ ->listen(QHostAddress::Any,9999);
    connect(tcp_Server_,&QTcpServer::newConnection,this,&TcpServer::SlotNewConnection);
}

TcpServer::~TcpServer()
{

}

void TcpServer::SlotNewConnection()
{
    if(tcp_Socket_ == NULL)
    {
        tcp_Socket_ = tcp_Server_ ->nextPendingConnection(); // deal with the connection from the client
        tcp_Socket_ ->write("connect to the server success!");
        connect(tcp_Socket_,&QTcpSocket::readyRead,this,&TcpServer::SlotReadyRead); //deal with the imformation from the client
    }

}

void TcpServer::SlotReadyRead()
{
    QByteArray array = tcp_Socket_ ->readAll();
    QMessageBox::information(this,"Client message",array);
}
