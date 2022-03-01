#ifndef BF2C_STRING_BUILDER_H
#define BF2C_STRING_BUILDER_H

#include <stddef.h>

typedef struct STRING_BUILDER_STRUCT {
    char* char_list;
    size_t size;
} string_builder_t;

string_builder_t* init_string_builder();

void string_builder_append(string_builder_t* string_builder, char c);

void string_builder_append_string(string_builder_t* string_builder, char* string);

#endif //BF2C_STRING_BUILDER_H
