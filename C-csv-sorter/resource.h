#ifndef CSV_SORTER_H
#define CSV_SORTER_H

// #define LINE_SIZE 106014
// #define BUFFER_SIZE 18001

#define LINE_SIZE 8888529
#define BUFFER_SIZE 999999

void read_csv(FILE *file, int *buffer, long file_size);
void write_csv(FILE *file, int *buffer, int buffer_size);
long get_file_size(FILE *file);
long get_items_csv(FILE *file, long file_size);

#endif