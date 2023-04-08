#ifndef BUBBLE_H
#define BUBBLE_H
#define ARRAY_SIZE 10

struct buffer_conf{
    int *buffer_ptr;
    int size;
};

extern pthread_mutex_t mutex;

void bubble_sort(int array[], int array_size);
void *bubble_sort_shared(void *array);
void show_array(int *array, int array_size);

#endif
