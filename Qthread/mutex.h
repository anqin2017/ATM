#ifndef MUTEX_H
#define MUTEX_H
#include <QMutex>


class Mutex
{
public:
    Mutex();

    void CreateKey();

    int Value() const;
private:
    int key_;
    QMutex mutex_;
};

#endif // MUTEX_H
