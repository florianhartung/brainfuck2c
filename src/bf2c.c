#include <stdio.h>
#include "include/bf2c.h"
#include "include/lexer.h"
#include "include/parser.h"

char* bf2c(char* src) {
    lexer_t* lexer = init_lexer(src);
    parser_t* parser = init_parser(lexer);
    AST_t* ast = parser_parse(parser);

    printf("%s", AST_to_string(ast));
    return 0;
}