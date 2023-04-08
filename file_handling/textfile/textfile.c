#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "resource.h"

void write_by_string(FILE *file, char *content){
    int ret = fputs(content, file);
    if (ret == EOF){
        printf("Error to write file...\n");
        exit(1);
    }
}

void write_by_char(FILE *file, char *content){
    int i;
    for (i = 0; i < strlen(content); i++){
        fputc(content[i], file);
    }
    printf("\nSuccessfully write\n");
}

void read_by_char(FILE *file){
    int i;
    char c;
    printf("\nReading by char\n");
    while (!feof(file))
    {
        printf("%c", c);
        c = fgetc(file); 
    }
    printf("\nSuccessfully read\n");
}

void read_by_string(FILE *file, char *buffer){
    printf("\nReading by string\n");
    char *ret = fgets(buffer, BUFFER_SIZE, file);
    if (ret == NULL){
        printf("Error to read file...\n");
        exit(1);
    }
    printf("%s\n", buffer);
}
