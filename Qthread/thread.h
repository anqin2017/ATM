#ifndef THREAD_H
#define THREAD_H

#include "ui_thread.h"
#include "workthread.h"
#include "consumer.h"

#define MAX_SIZE 2

class Thread : public QWidget, private Ui::Thread
{
    Q_OBJECT

public:
    explicit Thread(QWidget *parent = 0);

public slots:
    void SlotStart();

    void SlotStop();

    void SlotQuit();

private:
    WorkThread* workThread[MAX_SIZE];
};

#endif // THREAD_H
