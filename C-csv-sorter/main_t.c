#include <stdio.h>
#include <stdlib.h>
#include "resource.h"
#include <pthread.h>
#include "../bubble_sort/resource.h"
#define THREADS 18000

int main(){
    pthread_t t[THREADS];
    FILE *r_file, *w_file;
    int i, ret, *buffer;
    long file_size, buffer_size;
    struct buffer_conf buffer_s;
    r_file = fopen("./files/numbers.csv", "r");
    w_file = fopen("./files/new_file.csv", "w");
    if (r_file == NULL || w_file == NULL){
        perror("Unable to open the file");
        exit(1);
    }
    file_size = get_file_size(r_file);
    buffer_size = get_items_csv(r_file, file_size);
    printf("\n\n[FILE SIZE] - %d\n\n", file_size);
    printf("\n\n[BUFFER SIZE] - %d\n\n", buffer_size);
    buffer = (int*) malloc(buffer_size * sizeof(int));
    if (buffer == NULL){
        perror("\nUnable to memory allocation\n");
        exit(1);
    }
    buffer_s.size = buffer_size;
    buffer_s.buffer_ptr = buffer;
    read_csv(r_file, buffer, file_size);
    fclose(r_file);
    printf("\n********** BEFORE SORT **************\n");
    show_array(buffer, buffer_size);

    for(int i = 0; i < THREADS; i++){
        pthread_create(&t[i], NULL, bubble_sort_shared, (void *) &buffer_s);
    }
    for(int i = 0; i < THREADS; i++){
        pthread_join(t[i], NULL);
    }
    printf("\n********** AFTER SORT **************\n");
    show_array(buffer, buffer_size);
    write_csv(w_file, buffer, BUFFER_SIZE);
    fclose(w_file);
    free(buffer);
    pthread_mutex_destroy(&mutex);
    return 0;
}