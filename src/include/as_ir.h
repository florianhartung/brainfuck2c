#ifndef BF2C_AS_IR_H
#define BF2C_AS_IR_H

#include "ir.h"

typedef struct AS_IR_STRUCT {
    list_t* irs;
    ast_t* ast;
} as_ir_t;

as_ir_t* init_as_ir(ast_t* ast);

list_t* as_ir(as_ir_t* parser, ast_t* ast);

#endif //BF2C_AS_IR_H
