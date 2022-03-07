#include <malloc.h>
#include <string.h>
#include <stdio.h>
#include "include/as_c.h"
#include "include/ir.h"

char* as_c(list_t* irs) {
    string_builder_t* string_builder = init_string_builder();
    string_builder_append_string(string_builder, "#include <stdio.h>\n"
                                                 "char memory[1000] = {0};\n"
                                                 "char* ptr = memory + 500 * sizeof(char);\n"
                                                 "\n"
                                                 "void main() {\n");
    for (int i = 0; i < irs->size; i++) {
        ir_t* ir = ((ir_t**) irs->items)[i];
        switch (ir->type) {
            case IR_ADDITION:;
                char* addition_template = "*ptr += %d;\n";
                char* addition_str = calloc(strlen(addition_template) + 8, sizeof(char));
                sprintf(addition_str, addition_template, ir->value);
                string_builder_append_string(string_builder, addition_str);
                break;
            case IR_SET_VALUE:;
                char* set_template = "*ptr = %d;\n";
                char* set_str = calloc(strlen(addition_template) + 8, sizeof(char));
                sprintf(set_str, set_template, ir->value);
                string_builder_append_string(string_builder, set_str);
                break;
            case IR_MOVE_POINTER:;
                char* pointer_template = "ptr += %d;\n";
                char* pointer_str = calloc(strlen(addition_template) + 8, sizeof(char));
                sprintf(pointer_str, pointer_template, ir->value);
                string_builder_append_string(string_builder, pointer_str);
                break;
            case IR_OUTPUT:
                string_builder_append_string(string_builder, "putchar(*ptr);\n");
                break;
            case IR_INPUT:
                string_builder_append_string(string_builder, "scanf(\"%c\", ptr);\n");
                break;
            case IR_LOOP_START:
                string_builder_append_string(string_builder, "while(*ptr) {\n");
                break;
            case IR_LOOP_END:
                string_builder_append_string(string_builder, "}\n");
                break;
        }
    }
    string_builder_append_string(string_builder, "}\n");

    return string_builder->char_list;
}
