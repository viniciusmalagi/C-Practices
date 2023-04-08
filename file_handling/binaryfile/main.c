#include <stdio.h>
#include <stdlib.h>
#include "resource.h"

int main(){
    FILE *w_file, *r_file;
    char *p_filename = "./files/binary.txt";
    w_file = fopen(p_filename, "wb");
    r_file = fopen(p_filename, "rb");
    char buffer[BUFFER_SIZE] = "Joao Maria JOse 12345";
    if (w_file == NULL || r_file == NULL){
        printf("Unable to open file...");
        exit(1);
    }
    //Writing file
    write_bytes(buffer, sizeof(char), BUFFER_SIZE, w_file);
    fclose(w_file);
    //Reading file
    read_bytes(buffer, sizeof(char), BUFFER_SIZE, r_file);
    fclose(r_file);
    return 0;
}