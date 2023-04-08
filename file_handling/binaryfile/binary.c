#include <stdio.h>
#include <stdlib.h>
#include "resource.h"

void write_bytes(char *buffer, int bytes, int buffer_size, FILE *file){
    int total;
    total = fwrite(buffer, bytes, buffer_size, file);
    if (total != BUFFER_SIZE){
        printf("Error writing file...");
        exit(1);
    }
    printf("\nSuccessfully write\n");
}

void read_bytes(char *buffer, int bytes, int buffer_size, FILE *file){
    int read;
    read = fread(buffer, bytes, buffer_size, file);
    if (read != BUFFER_SIZE){
        printf("Error reading file...");
        exit(1);
    }
    printf("\nSuccessfully read\n");
}
