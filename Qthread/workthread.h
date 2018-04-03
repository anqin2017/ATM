#ifndef WORKTHREAD_H
#define WORKTHREAD_H

#include <QObject>
#include <QThread>
#include <QDebug>

class WorkThread : public QThread
{
    Q_OBJECT
public:
    explicit WorkThread();

signals:

public slots:

    // QThread interface
protected:
    void run();
};

#endif // WORKTHREAD_H
