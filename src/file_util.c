#include <stdlib.h>
#include <string.h>
#include "include/file_util.h"

long file_size(FILE* file) {
    fseek(file, 0L, SEEK_END);
    long size = ftell(file);
    rewind(file);
    return size;
}

char* file_util_read_file(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "[IO] Could not open file %s\n", filename);
        exit(1);
    }

    long size = file_size(file);
    char* data = calloc(size + 1, sizeof(char));
    if (data == NULL) {
        fprintf(stderr, "[IO] Could not allocate memory to read file\n");
        fclose(file);
        exit(1);
    }
    
    fread(data, sizeof(char), size, file);

    fclose(file);
    return data;
}

void file_util_write_file(char* filename, char* data) {
    FILE* out = fopen(filename, "w");
    fputs(data, out);
    fclose(out);
}

char* filename_strip_type(char* filename) {
    char* dot = strrchr(filename, '.');
    if (dot) {
        size_t index = dot - filename;

        char* new_filename = calloc(index + 1, sizeof(char));
        memcpy(new_filename, filename, index);
        return new_filename;
    }

    return filename;
}

char* file_util_filename_replace_type(char* initial_filename, char* new_type) {
    char* stripped_filename = filename_strip_type(initial_filename);
    char* new_filename = calloc(strlen(stripped_filename) + strlen(new_type) + 2, sizeof(char));
    sprintf(new_filename, "%s.%s", stripped_filename, new_type);
    return new_filename;
}