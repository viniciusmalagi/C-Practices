#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "resource.h"

void do_show_array(int *array, int array_size){
    int i;
    printf("[ ");
    for (i = 0; i <= array_size -1; i++) {
        if (i != array_size -1)
        {
            printf("%d, ", array[i]);
            continue;
        }
        printf("%d ]\n", array[i]);
    }
}

void random_vector(int *v, int v_length, int r_min, int r_max){
    int i;
    for (i = 0; i < v_length; i++)
    {
        v[i] = (rand() % (r_max - r_min +1) + r_min);
    }
}
