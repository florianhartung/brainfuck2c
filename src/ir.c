#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "include/ir.h"
#include "include/string_builder.h"

ir_t* init_ir(int type) {
    ir_t* ir = calloc(1, sizeof(ir_t));
    ir->type = type;

    return ir;
}

char* ir_type_to_string(int type) {
    switch (type) {
        case IR_ADDITION:
            return "IR_ADDITION";
        case IR_SET_VALUE:
            return "IR_SET_VALUE";
        case IR_MOVE_POINTER:
            return "IR_MOVE_POINTER";
        case IR_OUTPUT:
            return "IR_OUTPUT";
        case IR_INPUT:
            return "IR_INPUT";
        case IR_LOOP_START:
            return "IR_LOOP_START";
        case IR_LOOP_END:
            return "IR_LOOP_END";
        default:
            return "UNKNOWN_TYPE";
    }
}

char* ir_to_string(ir_t* ir) {
    char* template = "<IR type='%s', type_int=%d, value=%d>";
    char* type_str = ir_type_to_string(ir->type);

    char* str = calloc(strlen(template) + strlen(type_str) + 8, sizeof(char));
    sprintf(str, template, type_str, ir->type, ir->value);
    return str;
}

char* irs_to_string(list_t* irs) {
    string_builder_t* string_builder = init_string_builder();
    for (int i = 0; i < irs->size; i++) {
        if (i) {
            string_builder_append(string_builder, ',');
        }
        ir_t* ir = ((ir_t**) irs->items)[i];
        char* ir_str = ir_to_string(ir);
        for (int j = 0; j < strlen(ir_str); j++) {
            string_builder_append(string_builder, ir_str[j]);
        }
    }

    return string_builder->char_list;
}