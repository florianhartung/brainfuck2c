#include <stdio.h>

#ifndef BF2C_FILE_UTIL_H
#define BF2C_FILE_UTIL_H

char* file_util_read_file(char* filename);

void file_util_write_file(char* filename, char* data);

char* file_util_filename_replace_type(char* initial_filename, char* new_type);

#endif //BF2C_FILE_UTIL_H
