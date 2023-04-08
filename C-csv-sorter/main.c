#include <stdio.h>
#include <stdlib.h>
#include "resource.h"
#include "../bubble_sort/resource.h"

int main(){
    FILE *r_file, *w_file;
    int i, ret, *buffer;
    long file_size, buffer_size;
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
        printf("\nUnable to memory allocation\n");
        exit(1);
    }
    read_csv(r_file, buffer, file_size);
    fclose(r_file);
    printf("\n********** BEFORE SORT **************\n");
    show_array(buffer, buffer_size);

    bubble_sort(buffer, buffer_size);
    printf("\n********** AFTER SORT **************\n");
    show_array(buffer, buffer_size);
    write_csv(w_file, buffer, buffer_size);
    fclose(w_file);
    free(buffer);
    return 0;
}