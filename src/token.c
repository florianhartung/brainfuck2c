#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "include/token.h"

token_t* init_token(int type) {
    token_t* token = calloc(1, sizeof(token_t));
    token->type = type;

    return token;
}

char* token_type_to_string(int type) {
    switch (type) {
        case TOKEN_INCREMENT:
            return "TOKEN_INCREMENT";
        case TOKEN_DECREMENT:
            return "TOKEN_DECREMENT";
        case TOKEN_RIGHT:
            return "TOKEN_RIGHT";
        case TOKEN_LEFT:
            return "TOKEN_LEFT";
        case TOKEN_OUTPUT:
            return "TOKEN_OUTPUT";
        case TOKEN_INPUT:
            return "TOKEN_INPUT";
        case TOKEN_LOOP_START:
            return "TOKEN_LOOP_START";
        case TOKEN_LOOP_END:
            return "TOKEN_LOOP_END";
        case TOKEN_EOF:
            return "TOKEN_EOF";
        default:
            return "undef-token-type";
    }
}

char* token_to_string(token_t* token) {
    char* template = "<TOKEN type='%s', int_type=%d>";
    char* type_str = token_type_to_string(token->type);

    char* str = calloc(strlen(template) + strlen(type_str) + 8, sizeof(char));
    sprintf(str, template, type_str, token->type);

    return str;
}