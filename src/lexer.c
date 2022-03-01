#include <stdlib.h>
#include "include/lexer.h"

lexer_t* init_lexer(char* src) {
    lexer_t* lexer = calloc(1, sizeof(lexer_t));
    lexer->src = src;
    lexer->i = 0;
    lexer->c = src[lexer->i];

    return lexer;
}

void lexer_advance(lexer_t* lexer) {
    lexer->i += 1;
    lexer->c = lexer->src[lexer->i];
}

token_t* lexer_advance_current(lexer_t* lexer, int token_type) {
    lexer_advance(lexer);

    return init_token(token_type);
}


token_t* lexer_next_token(lexer_t* lexer) {
    while (lexer->c != '\0') {
        switch (lexer->c) {
            case '+':
                return lexer_advance_current(lexer, TOKEN_INCREMENT);
            case '-':
                return lexer_advance_current(lexer, TOKEN_DECREMENT);
            case '<':
                return lexer_advance_current(lexer, TOKEN_LEFT);
            case '>':
                return lexer_advance_current(lexer, TOKEN_RIGHT);
            case '.':
                return lexer_advance_current(lexer, TOKEN_OUTPUT);
            case ',':
                return lexer_advance_current(lexer, TOKEN_INPUT);
            case '[':
                return lexer_advance_current(lexer, TOKEN_LOOP_START);
            case ']':
                return lexer_advance_current(lexer, TOKEN_LOOP_END);
        }
        lexer_advance(lexer);
    }

    return init_token(TOKEN_EOF);
}