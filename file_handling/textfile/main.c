#include <stdio.h>
#include <stdlib.h>
#include "resource.h"

int main(){
    char *file = "./files/test.txt";
    char *content = "Writing here...";
    char buffer[BUFFER_SIZE] = {0};
    char *blah = "BLah Blah";

    FILE *w_file, *r_file;
    w_file = fopen(file, "w");
    r_file = fopen(file, "r");

    if (w_file == NULL || r_file == NULL){
        printf("Error to open file...\n");
        exit(1);
    }
    // fscanf(w_file, "%i", &x);
    write_by_char(w_file, content);
    write_by_string(w_file, " Something here...");
    fprintf(w_file, " Writing fprintf %s", blah);
    fclose(w_file);
    read_by_char(r_file);
    rewind(r_file);
    read_by_string(r_file, buffer);
    fclose(r_file);
    return 0;
}