#include <math.h>
#include <stdlib.h>
#include "resource.h"

void merge(int *v, int start, int middle, int end)
{
    int i, j, k;
    int n1 = middle - start + 1;
    int n2 = end - middle;
 
    /* create temp arrays */
    int *temp_n1 = (int *) malloc(n1 * sizeof(int));
    int *temp_n2 = (int *) malloc(n2 * sizeof(int));
    if (temp_n1 != NULL && temp_n2 != NULL)
    {
        /* Copy data to temp arrays*/
        for (i = 0; i < n1; i++)
            temp_n1[i] = v[start + i];
        for (j = 0; j < n2; j++)
            temp_n2[j] = v[middle + 1 + j];
    
        /* Merge the temp arrays back into "v"*/
        i = 0;
        j = 0;
        k = start;
        while (i < n1 && j < n2) {
            if (temp_n1[i] <= temp_n2[j]) {
                v[k] = temp_n1[i];
                i++;
            }
            else {
                v[k] = temp_n2[j];
                j++;
            }
            k++;
        }
        /* Copy the remaining elements*/
        while (i < n1) {
            v[k] = temp_n1[i];
            i++;
            k++;
        }
        while (j < n2) {
            v[k] = temp_n2[j];
            j++;
            k++;
        }
    }
    free(temp_n1);
    free(temp_n2);
}

void merge_sort(int *v, int begin, int end){
    int  middle;
    if (begin < end)
    {
        middle = floor((begin + end) /2);
        merge_sort(v, begin, middle);
        merge_sort(v, middle + 1,end);
        merge(v, begin, middle, end);
    }
}