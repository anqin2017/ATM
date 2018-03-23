#ifndef NETWORKACCESS_H
#define NETWORKACCESS_H

#include <QObject>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
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


signals:

public slots:
    void slotReadyRead();

    void OnAuthenticationRequest(QNetworkReply*, QAuthenticator*);

public:
    QString string_;
    QString username_; //for authentication
    QString password_; //for authentication

private:
    QNetworkAccessManager* NetManager_;
    QNetworkRequest* request_;
    QNetworkReply* reply_;
    QUrl * url_;

};

#endif // NETWORKACCESS_H
