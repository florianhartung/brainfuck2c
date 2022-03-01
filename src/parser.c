#include <stdlib.h>
#include <stdio.h>
#include "include/parser.h"
#include "include/lexer.h"

parser_t* init_parser(lexer_t* lexer) {
    parser_t* parser = calloc(1, sizeof(parser_t));
    parser->lexer = lexer;
    parser->token = lexer_next_token(parser->lexer);

    return parser;
}

void parser_advance(parser_t* parser) {
    parser->token = lexer_next_token(parser->lexer);
}

void parser_expect(parser_t* parser, int type) {
    if (parser->token->type != type) {
        fprintf(stderr, "[PARSER] Expected token of type %s, found %s", token_type_to_string(type),
                token_to_string(parser->token));
        exit(1);
    }
    parser_advance(parser);
}

AST_t* parser_parse(parser_t* parser) {
    return parser_parse_compound(parser);
}

AST_t* parser_parse_loop(parser_t* parser) {
    parser_expect(parser, TOKEN_LOOP_START);

    AST_t* loop_compound = init_AST(AST_LOOP);

    while (parser->token->type != TOKEN_LOOP_END) {
        if (parser->token->type == TOKEN_EOF) {
            fprintf(stderr, "[PARSER] Expected closing loop at token %s", token_to_string(parser->token));
            exit(1);
        }

        list_push(loop_compound->children, parser_parse_token(parser));
    }

    parser_expect(parser, TOKEN_LOOP_END);
    return loop_compound;
}

AST_t* parser_parse_token(parser_t* parser) {
    switch (parser->token->type) {
        case TOKEN_INCREMENT:
            parser_expect(parser, TOKEN_INCREMENT);
            return init_AST(AST_INCREMENT);
        case TOKEN_DECREMENT:
            parser_expect(parser, TOKEN_DECREMENT);
            return init_AST(AST_DECREMENT);
        case TOKEN_RIGHT:
            parser_expect(parser, TOKEN_RIGHT);
            return init_AST(AST_RIGHT);
        case TOKEN_LEFT:
            parser_expect(parser, TOKEN_LEFT);
            return init_AST(AST_LEFT);
        case TOKEN_OUTPUT:
            parser_expect(parser, TOKEN_OUTPUT);
            return init_AST(AST_OUTPUT);
        case TOKEN_INPUT:
            parser_expect(parser, TOKEN_INPUT);
            return init_AST(AST_INPUT);
        case TOKEN_LOOP_START:
            return parser_parse_loop(parser);
        case TOKEN_LOOP_END:
            fprintf(stderr, "[PARSER] Found closing loop without a loop being opened.");
            exit(1);
        default:
            fprintf(stderr, "[PARSER] Could not parse token %s", token_to_string(parser->token));
            exit(1);
    }
}

AST_t* parser_parse_compound(parser_t* parser) {
    AST_t* compound = init_AST(AST_COMPOUND);

    while (parser->token->type != TOKEN_EOF) {
        list_push(compound->children, parser_parse_token(parser));
    }
    return compound;
}