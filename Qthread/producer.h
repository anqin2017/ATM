#ifndef PRODUCER_H
#define PRODUCER_H

#include <QObject>
#include <QCoreApplication>
#include <QThread>
#include <QSemaphore>
#include <stdio.h>
#include <QDebug>

static const int g_DataSize = 100;
static const int g_BufferSize = 80;
static int buffer[g_BufferSize];
static QSemaphore g_freeBytes(g_BufferSize);
static QSemaphore g_usedBytes(0);

class Producer : public QThread
{
    Q_OBJECT

public:
    explicit Producer();

signals:

public slots:

    // QThread interface
protected:
    void run();
};

#endif // PRODUCER_H
