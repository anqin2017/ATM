#include "mutex.h"

Mutex::Mutex()
{

}

void Mutex::CreateKey()
{
    //QMutexLocker lock(&mutex_);
    mutex_.lock();
    ++key_;
    mutex_.unlock();
}

int Mutex::Value() const
{
    //QMutexLocker lock(&mutex_);
    //mutex_.lock();
    return key_;
    //mutex_.unlock();
}
