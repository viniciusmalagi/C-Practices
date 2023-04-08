#include <stdio.h>
#include <stdlib.h>
#include "resource.h"

int main(){
    int my_array[ARRAY_SIZE] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    show_array(my_array, ARRAY_SIZE);
    printf("ARRAY\n");
    bubble_sort(my_array, ARRAY_SIZE);
    show_array(my_array, ARRAY_SIZE);
    return 0;
}
