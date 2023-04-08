#ifndef TEXT_FILE_H
#define TEXT_FILE_H
#define BUFFER_SIZE 100

void write_by_char(FILE *file, char *content);
void write_by_string(FILE *file, char *content);
void read_by_char(FILE *file);
void read_by_string(FILE *file, char *buffer);

#endif