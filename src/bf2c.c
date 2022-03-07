#include "include/bf2c.h"
#include "include/parser.h"
#include "include/as_ir.h"
#include "include/ir_optimizer.h"
#include "include/as_c.h"

char* bf2c(char* src) {
    // Lexer
    lexer_t* lexer = init_lexer(src);

    // Parse to AST
    parser_t* parser = init_parser(lexer);
    ast_t* root = parser_parse(parser);

    // Parse to intermediate representation
    as_ir_t* ir_parser = init_as_ir(root);
    list_t* irs = as_ir(ir_parser, root);

    // Optimize
    ir_optimize(&irs);

    return as_c(irs);
}