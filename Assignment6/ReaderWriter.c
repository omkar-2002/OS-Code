#include<stdio.h>
#include<pthread.h>

pthread_mutex_t wr,mutex;
int a =10;
int read_count = 0;

void *reader(void *arg)
{
    long int num;
    num = (long int) arg;
   
    pthread_mutex_lock(&mutex);
    read_count++;
    pthread_mutex_unlock(&mutex);
   
    if(read_count == 1)
    {
        pthread_mutex_lock(&wr);
    }
   
    printf("\n Reader %ld is in critical section" , num);
    printf("\n Reader %ld is reading data %d", num, a);
    sleep(1);
   
    pthread_mutex_lock(&mutex);
    read_count--;
    pthread_mutex_unlock(&mutex);
   
        printf("\n Reader %ld left the critical section" , num);
   
   
   
    if(read_count == 0)
    {
        pthread_mutex_unlock(&wr);
    }
   
   
   
}

void *writer(void *arg)
{
   
     long int num;
     num = (long int) arg;
     
    //  lock the wr varibale tu enter in the critcical secion
   
    pthread_mutex_lock(&wr);
        printf("\n Writer %ld is in critical section" , num);
   
    printf("\n Writer %ld have written data as %d", num, ++a);
    sleep(1);
    // writer relaese the lock
    // printf("\n Writer %d have written data as %d", rnum, ++a);
   
    pthread_mutex_unlock(&wr);
   
        printf("\n Writer %ld left critical section" , num);
}

int main()
{
   
    pthread_t r[10], w[10];
   
    long int i,j;
     int nor,now;
   
    // initialised mutex variabel
   
    pthread_mutex_init(&wr,NULL);
    pthread_mutex_init(&mutex,NULL);
   
    printf("ENter the number of reader and writer");
    scanf("%d %d", &nor,&now);
   
    // create the reader and writer thread
   
    for(i =0; i<nor; i++)
   
    {
        pthread_create(&r[i], NULL, reader,(void *)i);
    }
   
    for(j =0; j<now; j++)
   
    {
        pthread_create(&w[j], NULL, writer,(void *)j);
    }
   
    // Join the threads
   
 for(i =0; i<nor; i++)
   
    {
        pthread_join(r[i], NULL);
    }
   
     for(j =0; j<now; j++)
   
    {
        pthread_join(w[j], NULL);
    }
   
    return 0;

}