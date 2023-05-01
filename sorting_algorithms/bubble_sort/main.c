#include <stdio.h>
#include <stdlib.h>
#include "resource.h"
#include "../resource.h"

#define ARRAY_SIZE 10

int main(){
    int my_array[ARRAY_SIZE] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    printf("\n** BEFORE **\n");
    do_show_array(my_array, ARRAY_SIZE);
    bubble_sort(my_array, ARRAY_SIZE);
    printf("\n** AFTER **\n");
    do_show_array(my_array, ARRAY_SIZE);
    return 0;
}
