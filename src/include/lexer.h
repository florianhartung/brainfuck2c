#ifndef BF2C_LEXER_H
#define BF2C_LEXER_H

#include "token.h"

typedef struct LEXER_STRUCT {
    char* src;
    char c;
    unsigned int i;
} lexer_t;

lexer_t* init_lexer(char* src);

void lexer_advance(lexer_t* lexer);

token_t* lexer_advance_current(lexer_t* lexer, int token_type);

token_t* lexer_next_token(lexer_t* lexer);

#endif //BF2C_LEXER_H
