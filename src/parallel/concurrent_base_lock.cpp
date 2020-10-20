
#include <vector>
#include "stdio.h"
#include"pthread.h"


#include <assert.h>
#include <pthread.h>
#include <stdlib.h>
#include "mythread.h"
//#include <sys/time.h>

//double Time_GetSeconds() {
//    struct timeval t;
//    int rc = gettimeofday(&t, NULL);
//    assert(rc == 0);
//    return (double)((double)t.tv_sec + (double)t.tv_usec / 1e6);
//}



typedef struct counter_t {
    int value;
    pthread_mutex_t lock;
}counter_t;


void init(counter_t* c) {
    c->value = 0;
   int ret = pthread_mutex_init(&c->lock,NULL);
   printf("the pthread is %d", ret);

}


void increment(counter_t* c) {
    pthread_mutex_lock(&c->lock);
    c->value++;
    pthread_mutex_unlock(&c->lock);
}


void decrement(counter_t* c) {
    pthread_mutex_lock(&c->lock);
    c->value--;
    pthread_mutex_unlock(&c->lock);
}


int get(counter_t* c) {
    pthread_mutex_lock(&c->lock);
    int rc = c->value;
    pthread_mutex_unlock(&c->lock);
    return rc;
}


void* mythread(void *argp)
{
    counter_t* c = (counter_t*)argp;
    printf("begin \n");

    for (int i = 0; i < 1e7; ++i)
        increment(c);
    printf("done \n");
    return NULL;
}


int main(int argc, char** argv)
{
    pthread_t p1, p2;
    void* status;
 
   
    counter_t* counter1 = new counter_t();
    init(counter1);
   
    Pthread_create(&p1, NULL, mythread, counter1);
    Pthread_create(&p2, NULL, mythread, counter1);
    Pthread_join(p1, &status);
    Pthread_join(p2, &status);
   
    printf("done with %d \n", counter1->value);
    delete counter1;
    
}