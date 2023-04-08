#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#include "resource.h"

int main(){

    sem_init(&sem, 0, 1);
    pthread_t t[THREADS];
    int s;

    for(int i = 0; i < THREADS; i++){
        s = pthread_create(&t[i], NULL, mutex_example, (void*) &i);
    }
    for(int i = 0; i < THREADS; i++){
        s = pthread_join(t[i], NULL);
    }
    printf("Value with mutex: %d\n", global);
    for(int i = 0; i < THREADS; i++){
        s = pthread_create(&t[i], NULL, semaphore_example, (void*) &i);
    }
    for(int i = 0; i < THREADS; i++){
        s = pthread_join(t[i], NULL);
    }
    printf("Value with semaphore: %d\n", global);
    return 0;
}
