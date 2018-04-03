#include "thread.h"
#include <QApplication>
//#include "producer.h"
#include "consumer.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Thread w;
    w.show();
    Producer pro;
    Consumer con;
    pro.start();
    con.start();
    pro.wait();
    con.wait();
    return a.exec();
}
