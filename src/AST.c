#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "include/AST.h"
#include "include/string_builder.h"

AST_t* init_AST(int type) {
    AST_t* ast = calloc(1, sizeof(AST_t));
    ast->type = type;

    if (type == AST_COMPOUND || type == AST_LOOP) {
        ast->children = init_list(sizeof(AST_t*));
    }

    return ast;
}

char* AST_type_to_string(AST_t* ast) {
    switch (ast->type) {
        case AST_COMPOUND:
            return "AST_COMPOUND";
        case AST_INCREMENT:
            return "AST_INCREMENT";
        case AST_DECREMENT:
            return "AST_DECREMENT";
        case AST_LEFT:
            return "AST_LEFT";
        case AST_RIGHT:
            return "AST_RIGHT";
        case AST_OUTPUT:
            return "AST_OUTPUT";
        case AST_INPUT:
            return "AST_INPUT";
        case AST_LOOP:
            return "AST_LOOP";
        case AST_NOOP:
            return "AST_NOOP";
    }
}

char* AST_to_string(AST_t* ast) {
    char* template = "<AST type='%s', type_int=%d, children=[%s]'>";
    char* type_str = AST_type_to_string(ast);

    char* children;
    if (ast->children) {
        string_builder_t* children_string_builder = init_string_builder();
        for (int i = 0; i < ast->children->size; ++i) {
            AST_t* child = list_get(ast->children, i);
            char* child_str = AST_to_string(child);
            size_t child_str_length = strlen(child_str);
            if (i) {
                string_builder_append(children_string_builder, ',');
            }
            for (int j = 0; j < child_str_length; j++) {
                string_builder_append(children_string_builder, child_str[j]);
            }
        }
        children = children_string_builder->char_list;
    } else {
        children = calloc(1, sizeof(char));
    }

    char* str = calloc(strlen(template) + strlen(type_str) + strlen(children) + 8, sizeof(char));
    sprintf(str, template, type_str, ast->type, children);
    return str;
}