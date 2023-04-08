#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "resource.h"
#include "../bubble_sort/resource.h"


void read_csv(FILE *file, int *buffer, long file_size){
    char *line = (char*) malloc(file_size * sizeof(char));
    if(line == NULL){
        perror("\nread_csv Unable to memory allocation\n");
        exit(1);
    }
    long count=0;
    while (fgets(line, file_size, file))
    {
        char *token;
        token = strtok(line, ";");
        while (token != NULL)
        {
            buffer[count] = atoi(token);
            count++;
            token = strtok(NULL, ";");
        }
    }
    free(line);
    printf("\nSuccessfully read\n");
}

void write_csv(FILE *file, int *buffer, int buffer_size){
    char num[6] = {0};
    int i, ret;
    for (i = 0; i <= buffer_size -1; i++){
        sprintf(num, "%d", buffer[i]); //formatting int to char
        int ret = fputs(num, file);
        if (ret == EOF){
            perror("\nUnable to write file...\n");
            exit(1);
        }
        fputc(';', file);
        printf("[%d]\n", i);
    }
    printf("\nSuccessfully write\n");
}

long get_file_size(FILE *file){
    int fk;;
    long len;
    fk = fseek(file, 0, SEEK_END);
    if (fk !=0){
        perror("\nUnable to fseek\n");
        exit(1);
    }
    len = ftell(file);
    rewind(file);
    return len -1;
}

long get_items_csv(FILE *file, long file_size){
    char *line = (char*) malloc(file_size * sizeof(char));
    if(line == NULL){
        perror("\nUnable to memory allocation\n");
        exit(1);
    }
    long count = 0;
    while (fgets(line, file_size, file))
    {
        char *token;
        token = strtok(line, ";");
        while (token != NULL)
        {
            count++;
            token = strtok(NULL, ";");
        }
    }
    free(line);
    rewind(file);
    return count - 1;
}
