cmake_minimum_required(VERSION 3.21)
project(bf2c C)

set(CMAKE_C_STANDARD 99)

add_executable(bf2c src/main.c src/include/bf2c.h src/lexer.c src/include/lexer.h src/include/token.h src/token.c src/bf2c.c src/include/list.h src/list.c src/include/parser.h src/parser.c src/include/AST.h src/AST.c src/include/string_builder.h src/string_builder.c)
