#include <stdio.h>
#include "resource.h"

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

void show_array(int *array, int array_size){
    int i;
    for (i = 0; i <= array_size -1; i++) {
        printf("%d\n", array[i]);
    }
}
