
#include <vector>
#include "stdio.h"
#include"pthread.h"

#include <assert.h>
#include <pthread.h>
#include <stdlib.h>
#include "mythread.h"

#define NUMCPUS 2
typedef struct counter_t {
    int global;                       //global count
    pthread_mutex_t glock;            //global lock
    int local[NUMCPUS];               //local count(per cpu)
    pthread_mutex_t llock[NUMCPUS];   // ... locks
    int threshold;
}counter_t;


typedef struct argsthread {
    counter_t* counter_1;
    int threadnum;
};


void init(counter_t* c, int threshold) {
    c->threshold = threshold;
    c->global = 0;
    pthread_mutex_init(&c->glock, NULL);
    int i;
    for (i = 0; i < NUMCPUS; i++) {
        c->local[i] = 0;
        pthread_mutex_init(&c->llock[i], NULL);
    }
}


//update:usually,just grab local lock and update local amount once local count has risen by 'threshold'
// grab global local and transfer local value to it


void update(counter_t* c, int threadID, int amt) {
    pthread_mutex_lock(&c->llock[threadID]);
    c->local[threadID] += amt;  //assume amt >0;
    if (c->local[threadID] >= c->threshold) {
        pthread_mutex_lock(&c->glock);
        c->global += c->local[threadID];
        pthread_mutex_unlock(&c->glock);
        c->local[threadID] = 0;
    }
    pthread_mutex_unlock(&c->llock[threadID]);
}


int get(counter_t* c) {
    pthread_mutex_lock(&c->glock);
    int val = c->global;
    pthread_mutex_unlock(&c->glock);
    return val;
}


void* mythread(void *argp)
{
    argsthread* arg = (argsthread*)argp;
    counter_t* c = (counter_t*)arg->counter_1;
    int thread = (int)arg->threadnum;
    printf("begin \n");

    for (int i = 0; i < 1e9; ++i)
        update(c, thread, 1);
    printf("done \n");
    return NULL;
}


int main(int argc, char** argv)
{
    pthread_t p1, p2;
    void* status;
 
 

    
    counter_t* counter1 = new counter_t();

    argsthread* argsthread_0 = new argsthread();
    argsthread_0->counter_1 = counter1;
    argsthread_0->threadnum = 0;

    argsthread* argsthread_1 = new argsthread();
    argsthread_1->counter_1 = counter1;
    argsthread_1->threadnum = 1;

    
    init(counter1,100);
   
    Pthread_create(&p1, NULL, mythread, argsthread_0);
    Pthread_create(&p2, NULL, mythread, argsthread_1);
    Pthread_join(p1, &status);
    Pthread_join(p2, &status);
   
    printf("done with %d \n", get(counter1));
    delete counter1;
    delete argsthread_0;
    delete argsthread_1;
    
}