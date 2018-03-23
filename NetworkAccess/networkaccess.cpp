#include "networkaccess.h"
#include <QAuthenticator>
NetWorkAccess::NetWorkAccess(QObject *parent) : QObject(parent)
{
    NetManager_ = new QNetworkAccessManager(this);
    request_ = new QNetworkRequest();
    connect(NetManager_, SIGNAL(authenticationRequired(QNetworkReply*, QAuthenticator*)),
            this, SLOT(OnAuthenticationRequest(QNetworkReply*, QAuthenticator*)));
}

NetWorkAccess::~NetWorkAccess()
{
    if(reply_ != NULL)
    {
        reply_ ->abort();
        reply_ ->deleteLater();
    }
}

void NetWorkAccess::InitNetWorkAccess(const QString urlpath,const QString username,
                                      const QString password)
{
    url_ = new QUrl(urlpath);
    url_ ->setUserName(username);
    url_ ->setPassword(password);
    request_ ->setUrl(*url_);
    //request_ ->setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
    username_ = username;
    password_ = password;
}

void NetWorkAccess::OnAuthenticationRequest(QNetworkReply*reply, QAuthenticator *Authenticator)
{
    qDebug() << "OnAuthentication start!";
    QByteArray tpassword;
    tpassword.append(password_);
    tpassword = QByteArray::fromBase64(tpassword); // need to comfirm
    QString strPassword = QString(tpassword);
    Authenticator ->setUser(username_);
    Authenticator ->setPassword(strPassword);
}

int NetWorkAccess::Get()
{
    reply_ = NetManager_ ->get(*request_);
    connect(reply_,SIGNAL(readyRead()),this,SLOT(slotReadyRead()));
    return 0;
}

void NetWorkAccess::slotReadyRead()
{
    if(reply_ ->error() == QNetworkReply::NoError)
    {
        QByteArray bytes = reply_ ->readAll();
        string_ = QString::fromUtf8(bytes);
    }
    qDebug() << reply_ ->error();
}



