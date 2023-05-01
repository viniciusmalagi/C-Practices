#include <stdio.h>
#include "resource.h"
#include "../resource.h"

#define LEN_V 7

int main(){
    int v[LEN_V] = {23, 4, 67, -8, 90, 54, 21};
    printf("\n** BEFORE **\n");
    do_show_array(v, LEN_V);
    insertion_sort(v, LEN_V);
    printf("\n** AFTER **\n");
    do_show_array(v, LEN_V);
    return 0;
}