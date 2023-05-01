#include "resource.h"

int partition(int *v, int start, int end){
    int aux, left, right, pivot, i;
    left = start;
    right = end;
    pivot = v[start];

    while (left < right)
    {
        while (v[right] > pivot)
        {
            right--;
        }
        while (v[left] <= pivot)
        {
            left++;
        }
        if (left < right)
        {
            aux = v[left];
            v[left] = v[right];
            v[right] = aux;
        }

    }
    v[start] = v[right];
    v[right] = pivot;
    return right;
}
void quick_sort(int *v, int start, int end){
    int pivot;
    if (end > start)
    {
        pivot = partition(v, start, end);
        quick_sort(v, start, pivot-1);
        quick_sort(v, pivot+1, end);
    }
}