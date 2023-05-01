#include "resource.h"

void selection_sort(int *v, int len){
    int i, j, smaller, aux;
    for (i = 0; i < len -1; i++)
    {
        smaller = i;
        for (j = i + 1; j < len; j++)
        {
            if (v[j] < v[smaller])
            {
                smaller = j;
            }
        }
        if (i != smaller)
        {
            aux = v[i];
            v[i] = v[smaller];
            v[smaller] = aux;
        }
    }
}