#include "thread.h"

Thread::Thread(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    connect(pushButtonStart,&QPushButton::clicked,this,&Thread::SlotStart);
    connect(pushButtonStop,&QPushButton::clicked,this,&Thread::SlotStop);
    connect(pushButtonQuit,&QPushButton::clicked,this,&Thread::SlotQuit);
}

void Thread::SlotStart()
{
   for(int i = 0 ; i < MAX_SIZE ; ++i)
   {
       workThread[i] = new WorkThread;
   }
   for(int i = 0 ; i < MAX_SIZE ; ++i)
   {
       workThread[i] ->start();
   }
  pushButtonStart ->setEnabled(false);
  pushButtonStop ->setEnabled(true);

}

void Thread::SlotStop()
{
    for(int i = 0 ; i < MAX_SIZE ; ++i)
    {
        workThread[i] ->terminate();
        workThread[i] ->wait();
    }
    pushButtonStart ->setEnabled(true);
    pushButtonStop ->setEnabled(false);
}

void Thread::SlotQuit()
{

}
