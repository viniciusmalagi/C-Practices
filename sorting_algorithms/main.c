#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>
#include "./bubble_sort/resource.h"
#include "resource.h"

#define V_SIZE 1024

int main(){
    srand(time(NULL));
    int *v = (int *) malloc(V_SIZE * sizeof(int));
    if (v == NULL)
    {
        perror("Unable to alloc memory");
    }
    random_vector(v, V_SIZE, 1, 100000);
    do_show_array(v, V_SIZE);
    bubble_sort(v, V_SIZE);
    printf("\n-------------------------------\n");
    do_show_array(v, V_SIZE);
    free(v);

    return 0;
}
