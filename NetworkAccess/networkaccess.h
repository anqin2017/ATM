#ifndef NETWORKACCESS_H
#define NETWORKACCESS_H

#include <QObject>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include <iostream>
#include <QMap>
#include <QUuid>
#include <QFile>

using namespace std;

class NetWorkAccess : public QObject
{
    Q_OBJECT
public:
    explicit NetWorkAccess(QObject *parent = 0);

    ~NetWorkAccess();

    void InitNetWorkAccess(const QString urlpath,const QString username,
                           const QString password);


    int  Get();

    int  Post();


signals:

public slots:
    void SlotReadyRead();

    void OnAuthenticationRequest(QNetworkReply*, QAuthenticator*);

    void SlotPostReplyFinish();

    int InitPostDataFrame(QMap<QString,QString> params,QString uploadfilename,QString newfilename,QString filepath);

public:
    QString string_;
    QString username_; //for authentication
    QString password_; //for authentication

private:
    QNetworkAccessManager* NetManager_;
    QNetworkRequest* request_;
    QNetworkReply* reply_;
    QUrl * url_;
    QByteArray   postData_;

};

#endif // NETWORKACCESS_H
