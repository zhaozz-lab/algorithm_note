
#include <vector>
#include "stdio.h"
#include"pthread.h"

#include <assert.h>
#include <pthread.h>
#include <stdlib.h>
#include "mythread.h"


//volatile int done = 0;
//void* child(void* arg) {
//    printf("child \n");
//    done = 1;
//    return NULL;
//}
//
//
//int main(int argc, char** argv)
//{
//    printf("parent begin \n");
//
//    pthread_t c;
//    Pthread_create(&c, NULL, child, NULL);
//    while (done == 0)
//        ;
//    printf("parent end \n");
//    return 0;
// 
//}


/* condition  varible  */
//int done = 0;
//pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
//pthread_cond_t c = PTHREAD_COND_INITIALIZER;
//
//void thr_exit() {
//	Pthread_mutex_lock(&m);
//	done = 1;
//	Pthread_cond_signal(&c);
//	Pthread_mutex_unlock(&m);
//}
//
//void* child(void* arg) {
//	printf("child \n");
//	thr_exit();
//	return NULL;
//}
//
//void thr_join(){
//	Pthread_mutex_lock(&m);
//	while (done ==0)
//	{
//		Pthread_cond_wait(&c, &m);
//	}
//	Pthread_mutex_unlock(&m);
//}
//
//int main(int argc, char* argv[]) {
//	printf("parent: begin \n");
//	pthread_t p;
//	Pthread_create(&p, NULL, child, NULL);
//	thr_join();
//	printf("parent end \n");
//	return 0;
//}

//#define MAX 16
//int buffer[MAX];
//int fills = 0;
//int use = 0;
//int count = 0;
//
//void put(int value) {
//	buffer[fills] = value;
//	fills = (fills + 1) % MAX;
//	count++;
//}
//
//int get() {
//	int tmp = buffer[use];
//	use = (use + 1) % MAX;
//	count--;
//	return tmp;
//
//}
//
//pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
//pthread_cond_t empty = PTHREAD_COND_INITIALIZER;
//pthread_cond_t fill = PTHREAD_COND_INITIALIZER;
//int loops = 1e8;
//
//void *producer(void* arg) {
//	int i;
//	for (i = 0; i < loops; i++) {
//		Pthread_mutex_lock(&mutex);
//		while (count == MAX)
//		{
//			Pthread_cond_wait(&empty, &mutex);
//		}
//		put(i);
//		Pthread_cond_signal(&fill);
//		Pthread_mutex_unlock(&mutex);
//	}
//	return NULL;
//}
//
//void *consumer(void* args) {
//	int i;
//	for (i = 0; i < loops; i++) {
//		Pthread_mutex_lock(&mutex);
//		while (count == 0)
//		{
//			Pthread_cond_wait(&fill, &mutex);
//		}
//		int temp = get();
//		Pthread_cond_signal(&empty);
//		Pthread_mutex_unlock(&mutex);
//		printf("consume %d \n", temp);
//	}
//	return NULL;
//}
//
//int main(int argc, char* argv[]) {
//	printf("parent: begin \n");
//	pthread_t produce[1], consume[1];
//	
//
//	for (int i = 0; i < 1; i++) {
//		Pthread_create(&produce[i], NULL, producer, NULL);
//		Pthread_create(&consume[i], NULL, consumer, NULL);
//	}
//	for (int i = 0; i < 1; i++) {
//		pthread_join(produce[i], NULL);
//		pthread_join(consume[i], NULL);
//		
//	}
//	
//	printf("parent end \n");
//	return 0;
//}


# include "semaphore.h"
#define MAX 16
int buffer[MAX];
int fills = 0;
int use = 0;
int count = 0;

void put(int value) {
	buffer[fills] = value;
	fills = (fills + 1) % MAX;
	count++;
}

int get() {
	int tmp = buffer[use];
	use = (use + 1) % MAX;
	count--;
	return tmp;

}

//pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
//pthread_cond_t empty = PTHREAD_COND_INITIALIZER；
sem_t empty;
sem_t full;
sem_t mutex;



int loops = 1e8;

void* producer(void* arg) {
	int i;
	for (i = 0; i < loops; i++) {
		sem_wait(&empty);
		sem_wait(&mutex);
		
		put(i);
		sem_post(&mutex);
		while (count == MAX)
		{
			sem_post(&full);
		}
		
		
		
	}
	return NULL;
}

void* consumer(void* args) {
	int i;
	for (i = 0; i < loops; i++) {

		sem_wait(&full);
		sem_wait(&mutex);
		
		int temp = get();
		sem_post(&mutex);
		while (count==0)
		{
			sem_post(&empty);
		}
		printf("consume %d \n", temp);
	}
	return NULL;
}

int main(int argc, char* argv[]) {
	printf("parent: begin \n");
	pthread_t produce[1], consume[1];
	sem_init(&empty, 0, 1);
	sem_init(&full, 0, 1);
	sem_init(&mutex, 0, 1);

	for (int i = 0; i < 1; i++) {
		Pthread_create(&produce[i], NULL, producer, NULL);
		Pthread_create(&consume[i], NULL, consumer, NULL);
	}
	for (int i = 0; i < 1; i++) {
		pthread_join(produce[i], NULL);
		pthread_join(consume[i], NULL);

	}

	printf("parent end \n");
	return 0;
}