#include "consumer.h"

Consumer::Consumer()
{

}

void Consumer::run()
{
    for(int i = 0 ; i < g_DataSize ; ++i)
    {
        g_usedBytes.acquire();
        fprintf(stdout,"%d",buffer[i % g_BufferSize]);
        qDebug() << buffer[i];
        if(i % 16 == 0 && i!= 0)
        {
            fprintf(stdout,"\n");
        }
        g_freeBytes.release();
    }
    fprintf(stdout,"\n");
}
