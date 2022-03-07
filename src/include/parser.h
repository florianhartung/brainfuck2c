#ifndef BF2C_PARSER_H
#define BF2C_PARSER_H

#include "lexer.h"
#include "ast.h"

typedef struct {
    lexer_t* lexer;
    token_t* token;
} parser_t;

parser_t* init_parser(lexer_t* lexer);

void parser_expect(parser_t* parser, int type);

ast_t* parser_parse_token(parser_t* parser);

ast_t* parser_parse(parser_t* parser);

ast_t* parser_parse_compound(parser_t* parser);

#endif //BF2C_PARSER_H