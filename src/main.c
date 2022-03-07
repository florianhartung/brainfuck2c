#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/bf2c.h"
#include "include/file_util.h"

int main(int argc, char** argv) {
    if (argc <= 1) {
        fprintf(stderr, "[IO] Please specify a brainfuck program file\n");
        exit(1);
    }

    char* bf_program = file_util_read_file(argv[1]);
    printf("[IO] Read %d characters\n", strlen(bf_program));

    char* c_code = bf2c(bf_program);

    char* new_filename = file_util_filename_replace_type(argv[1], "c");
    file_util_write_file(new_filename, c_code);
}