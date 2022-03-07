#include <stdlib.h>
#include <string.h>
#include "include/string_builder.h"

string_builder_t* init_string_builder() {
    string_builder_t* string_builder = calloc(1, sizeof(string_builder_t));

    return string_builder;
}

void string_builder_append(string_builder_t* string_builder, char c) {
    string_builder->size += 1;

    if (string_builder->char_list) {
        string_builder->char_list = realloc(string_builder->char_list, string_builder->size * sizeof(char) + 1);
        string_builder->char_list[string_builder->size] = 0;
    } else {
        string_builder->char_list = calloc(2, sizeof(char));
    }

    string_builder->char_list[string_builder->size - 1] = c;
}

void string_builder_append_string(string_builder_t* string_builder, char* string) {
    size_t len = strlen(string);
    for (int i = 0; i < len; i++) {
        string_builder_append(string_builder, string[i]);
    }
}