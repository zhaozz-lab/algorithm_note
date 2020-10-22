#include <stdio.h>
#include "pthread.h"
void* thread(void* vargp);
void posix_error(int code, char* msg);
void Pthread_create(pthread_t* tidp, pthread_attr_t* attrp,
    void* (*routine)(void*), void* argp);


char** ptr;
#define N 2
int main()
{
    int i;
    void *status;
    pthread_t tid;
    char* msgs[N] = {
        "Hello from foo",
        "Hello from bar" };
    ptr = msgs;

    for (int i = 0; i < N; i++)
        Pthread_create(&tid, NULL, thread, (void*)i);
        pthread_join(tid,&status);
}



void* thread(void* vargp) {
    int myid = (int)vargp; 
    static int cnt = 0;
    printf("[%d]: %s (cnt=%d)\n", myid, ptr[myid], ++cnt); 
    return NULL;
}


void posix_error(int code, char* msg) /* posix-style error */
{
    printf("posx error");
}


void Pthread_create(pthread_t* tidp, pthread_attr_t* attrp,
    void* (*routine)(void*), void* argp)
{
    int rc;

    if ((rc = pthread_create(tidp, attrp, routine, argp)) != 0)
        posix_error(rc, "Pthread_create error");
}


