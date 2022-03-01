#ifndef BF2C_AST_H
#define BF2C_AST_H

#include "token.h"
#include "list.h"

typedef struct AST_STRUCT{
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
} AST_t;

AST_t* init_AST(int type);

char* AST_to_string(AST_t* ast);

#endif //BF2C_AST_H
