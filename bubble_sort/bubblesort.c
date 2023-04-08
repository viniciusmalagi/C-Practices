#include <stdio.h>
#include <pthread.h>
#include "resource.h"

int index_global = 0;
int count_global = 1;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void bubble_sort(int array[], int array_size){
    int i, aux, count;

    for (count = 1; count < array_size; count++){
        for (i = 0; i < array_size -1; i++) {
            if (array[i] > array[i + 1]){
                aux = array[i];
                array[i] = array[i + 1];
                array[i +1] = aux;
            }

        }
    }
}

void *bubble_sort_shared(void *array){
    struct buffer_conf buff = *(struct buffer_conf*) array;
    int aux;
    pthread_mutex_lock(&mutex);
    for (count_global = 1; count_global < buff.size -1; count_global++){
        for (index_global = 0; index_global < buff.size -1; index_global++) {
            if (buff.buffer_ptr[index_global] > buff.buffer_ptr[index_global + 1]){
                aux = buff.buffer_ptr[index_global];
                buff.buffer_ptr[index_global] = buff.buffer_ptr[index_global + 1];
                buff.buffer_ptr[index_global +1] = aux;
            }
        }
    }
    pthread_mutex_unlock(&mutex);
}


void show_array(int *array, int array_size){
    int i;
    for (i = 0; i <= array_size -1; i++) {
        printf("%d\n", array[i]);
    }
}
