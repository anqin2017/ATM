#include "networkaccess.h"
#include <QAuthenticator>
NetWorkAccess::NetWorkAccess(QObject *parent) : QObject(parent)
{
    NetManager_ = new QNetworkAccessManager(this);
    request_ = new QNetworkRequest();
    connect(NetManager_, SIGNAL(authenticationRequired(QNetworkReply*, QAuthenticator*)),
            this, SLOT(OnAuthenticationRequest(QNetworkReply*, QAuthenticator*)));
    //QUuid
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
    //url_ ->setUserName(username);
    //url_ ->setPassword(password);
    request_ ->setUrl(*url_);
    //postData_ .append(username);
    //postData_ .append(password);
    //request_ ->setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
    //request_ ->setHeader(QNetworkRequest::ContentLengthHeader, postData_.length());
    //username_ = username;
    //password_ = password;
}

void NetWorkAccess::OnAuthenticationRequest(QNetworkReply* reply, QAuthenticator* Authenticator)
{
    qDebug() << "OnAuthentication start!";
    QByteArray tpassword;
    tpassword.append(password_);
    tpassword = QByteArray::fromBase64(tpassword); // need to comfirm
    QString strPassword = QString(tpassword);
    Authenticator ->setUser(username_);
    Authenticator ->setPassword(strPassword);
}

void NetWorkAccess::SlotPostReplyFinish()
{
    QVariant status_code = reply_ ->attribute(QNetworkRequest::HttpStatusCodeAttribute);
    qDebug() << "status code: " << status_code;
    qDebug() << reply_ ->error();
    if(reply_ ->error() == QNetworkReply::NoError)
    {
        QByteArray array = reply_ ->readAll();
        QString result (array);
        qDebug() << result;
    }
}

int NetWorkAccess::InitPostDataFrame(QMap<QString, QString> params, QString uploadfilename, QString newfilename, QString filepath)
{
    QString boundary = QUuid::createUuid().toString();
    // init the excel data
    for(QMap<QString,QString>::iterator it = params.begin(); it!= params.end();it++)
    {
        postData_.append("--" + boundary + "\r\n");
        postData_.append(QString("Content-Disposition: form-data;name=\"") + it.key() + QString("\"") +QString("\r\n"));
        postData_.append("\r\n");
        postData_.append(it.value() + "\r\n");
    }
    qDebug () << "post data 1: " << postData_;
    // init the head
    postData_.append(("--" + boundary + "\r\n"));
    postData_.append(QString("Content-Disposition: form-data;name=\"") + uploadfilename +
                 QString("\";filename = \"") + newfilename + QString("\"") + QString("\r\n"));
    postData_.append("\r\n");
    qDebug () << "post data2 : " << postData_;
    // init the file content
    QFile file(filepath);
    if(!file.open(QIODevice::ReadOnly))
    {
        cerr << "open file failed!" << endl;
        return -1;
    }
    QByteArray array = file.readAll();
    qDebug() << "image data size : " << array;
    //QString imagecontent(array);
    qDebug() << "image data size : " << array.size();
    //postData_.append(file.readAll());
    //postData_ += array;
    postData_.append("\r\n");
    postData_.append("--" + boundary + "\r\n");
    qDebug () << "post data 3 : " << postData_;
    // init the http head
    request_ ->setRawHeader(QString("Content-Type").toLatin1(),QString("multipart/form-data;boundary="+boundary).toLatin1());
    request_ ->setRawHeader(QString("Content-Length").toLatin1(),QString::number(postData_.length()).toLatin1());
}

int NetWorkAccess::Get()
{
    reply_ = NetManager_ ->get(*request_);
    connect(reply_,SIGNAL(readyRead()),this,SLOT(SlotReadyRead()));
    return 0;
}

int NetWorkAccess::Post()
{
    if(!postData_.isEmpty())
    {
        reply_ = NetManager_ ->post(*request_,postData_);
        connect(NetManager_,&QNetworkAccessManager::finished,this,&NetWorkAccess::SlotPostReplyFinish);
    }
    return 0;

}

void NetWorkAccess::SlotReadyRead()
{
    if(reply_ ->error() == QNetworkReply::NoError)
    {
        QByteArray bytes = reply_ ->readAll();
        string_ = QString::fromUtf8(bytes);
    }
    qDebug() << reply_ ->error();
}



