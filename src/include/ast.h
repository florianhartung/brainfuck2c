#ifndef BF2C_ast_H
#define BF2C_ast_H

#include "token.h"
#include "list.h"

typedef struct ast_STRUCT {
    enum {
        AST_COMPOUND,
        AST_INCREMENT,
        AST_DECREMENT,
        AST_LEFT,
        AST_RIGHT,
        AST_OUTPUT,
        AST_INPUT,
        AST_LOOP,
        AST_NOOP
    } type;
    list_t* children;
} ast_t;

ast_t* init_ast(int type);

char* ast_to_string(ast_t* ast);

#endif //BF2C_ast_H
