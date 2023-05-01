#include "resource.h"

void insertion_sort(int *v, int len){
    int i, j, aux;
    for (i = 1; i < len; i++)
    {
        aux = v[i];
        for (j = i; (j > 0) && (aux < v[j - 1]); j--)
            v[j] = v[j -1];
        v[j] = aux;
    }
}