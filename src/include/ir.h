#ifndef BF2C_ir_H
#define BF2C_ir_H

#include "list.h"
#include "ast.h"

typedef struct IR_STRUCT {
    enum {
        IR_ADDITION,
        IR_SET_VALUE,
        IR_MOVE_POINTER,
        IR_OUTPUT,
        IR_INPUT,
        IR_LOOP_START,
        IR_LOOP_END
    } type;
    int value;
} ir_t;

ir_t* init_ir(int type);

char* ir_to_string(ir_t* ir);

char* irs_to_string(list_t* irs);

#endif //BF2C_ir_H
