#ifndef CONSUMER_H
#define CONSUMER_H

#include <QObject>
#include <QDebug>
#include "producer.h"

//extern const int g_DataSize;
//extern const int g_BufferSize;
//extern int buffer[g_BufferSize];
//extern QSemaphore g_freeBytes;
//extern QSemaphore g_usedBytes;


class Consumer : public QThread
{
    Q_OBJECT
public:
    explicit Consumer();

signals:

public slots:

    // QThread interface
protected:
    void run();
};

#endif // CONSUMER_H
