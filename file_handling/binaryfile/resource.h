#ifndef BINARY_H
#define BINARY_H
#define BUFFER_SIZE 50

void write_bytes(char *buffer, int bytes, int buffer_size, FILE *file);
void read_bytes(char *buffer, int bytes, int buffer_size, FILE *file);

#endif