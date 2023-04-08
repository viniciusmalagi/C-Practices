#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#include "resource.h"

pthread_mutex_t mutex;
sem_t sem;
long global = 0;

void *mutex_example(void *arg){
    printf("THREAD MUTEX %d\n", *(int*) arg);
    for (long i = 0; i < 100000; i++){
        pthread_mutex_lock(&mutex);
        global++;
        pthread_mutex_unlock(&mutex);
    }
}

void *semaphore_example(void *arg){
    printf("THREAD SEMAPHORE %d\n", *(int*) arg);
    for (long i = 0; i < 100000; i++){
        sem_wait(&sem);
        global++;
        sem_post(&sem);
    }
}
