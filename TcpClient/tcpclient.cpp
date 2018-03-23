#include "tcpclient.h"
#include <QMessageBox>
#include <QHostAddress>

TcpClient::TcpClient(QWidget *parent) :
    QWidget(parent),
    tcpClientSocket_(NULL)
{
    setupUi(this);
    tcpClientSocket_ = new QTcpSocket(this);
    tcpClientSocket_ ->connectToHost(QHostAddress("192.168.1.152"),9999);
    connect(tcpClientSocket_,&QTcpSocket::readyRead,this,&TcpClient::SlotReadyRead);
    connect(pushButtonSend,&QPushButton::clicked,this,&TcpClient::SlotSendInfo);
}

void TcpClient::SlotReadyRead()
{
    QByteArray array = tcpClientSocket_ ->readAll();
    QMessageBox::information(this,"Server message",array);
}

void TcpClient::SlotSendInfo()
{
    QString text = textEditInfo ->toPlainText();
    tcpClientSocket_ ->write(text.toUtf8());
    textEditInfo ->clear();
}


