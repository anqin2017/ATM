#include "producer.h"

Producer::Producer()
{

}

void Producer::run()
{
    for(int i = 0 ; i < g_DataSize; ++i)
    {
          g_freeBytes.acquire();
          buffer[i % g_BufferSize] = i % g_BufferSize;
          g_usedBytes.release();
          qDebug() << buffer[i % g_BufferSize];
    }
}

