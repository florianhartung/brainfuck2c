#include <stdlib.h>
#include "include/as_ir.h"

as_ir_t* init_as_ir(ast_t* ast) {
    as_ir_t* parser = calloc(1, sizeof(as_ir_t));

    parser->irs = init_list(sizeof(ir_t));
    parser->ast = ast;

    return parser;
}

void as_ir_ast(as_ir_t* parser, ast_t* ast);

void as_ir_compound(as_ir_t* parser, ast_t* compound) {
    for (int i = 0; i < compound->children->size; i++) {
        as_ir_ast(parser, ((ast_t**) compound->children->items)[i]);
    }
}

ir_t* init_addition_ir(int value) {
    ir_t* ir = init_ir(IR_ADDITION);
    ir->value = value;

    return ir;
}

ir_t* init_move_pointer_ir(int value) {
    ir_t* ir = init_ir(IR_MOVE_POINTER);
    ir->value = value;

    return ir;
}

void as_ir_ast(as_ir_t* parser, ast_t* ast) {
    switch (ast->type) {
        case AST_COMPOUND:
            as_ir_compound(parser, ast);
            break;
        case AST_INCREMENT:
            list_push(parser->irs, init_addition_ir(1));
            break;
        case AST_DECREMENT:
            list_push(parser->irs, init_addition_ir(-1));
            break;
        case AST_LEFT:
            list_push(parser->irs, init_move_pointer_ir(-1));
            break;
        case AST_RIGHT:
            list_push(parser->irs, init_move_pointer_ir(1));
            break;
        case AST_OUTPUT:
            list_push(parser->irs, init_ir(IR_OUTPUT));
            break;
        case AST_INPUT:
            list_push(parser->irs, init_ir(IR_INPUT));
            break;
        case AST_LOOP:
            list_push(parser->irs, init_ir(IR_LOOP_START));
            as_ir_compound(parser, ast);
            list_push(parser->irs, init_ir(IR_LOOP_END));
            break;
        case AST_NOOP:
            break;
    }
}

list_t* as_ir(as_ir_t* parser, ast_t* ast) {
    as_ir_ast(parser, ast);

    return parser->irs;
}