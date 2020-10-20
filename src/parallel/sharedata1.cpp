
#include <vector>
#include "stdio.h"
#include"pthread.h"

static volatile int counter = 0;
pthread_mutex_t glock;
int ret = pthread_mutex_init(&glock, NULL);

void* mythread(void* arg)
{
    printf("%s:begin \n", (char*)arg);
    int i;
    pthread_mutex_lock(&glock);
    for (int i = 0; i < 1e7; ++i)
        
        counter = counter + 1;
    pthread_mutex_unlock(&glock);
    printf("%s:done \n", (char*)arg);
    return NULL;
}


void Pthread_create(pthread_t* tidp, pthread_attr_t* attrp,
    void* (*routine)(void*), void* argp)
{
    int rc;
    if ((rc = pthread_create(tidp, attrp, routine, argp)) != 0)
        printf("Pthread_create error");
}


int main(int argc, char** argv)
{
    pthread_t p1, p2;
    void* status;
    printf("main:begin counter= %d", counter);
   
    Pthread_create(&p1, NULL, mythread, "A");
    Pthread_create(&p2, NULL, mythread, "B");
    pthread_join(p1, &status);
    pthread_join(p2, &status);
    printf("done with %d \n", counter);
    
}