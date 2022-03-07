cmake_minimum_required(VERSION 3.21)
project(bf2c C)

set(CMAKE_C_STANDARD 99)

add_executable(bf2c src/main.c src/include/bf2c.h src/lexer.c src/include/lexer.h src/include/token.h src/token.c src/bf2c.c src/include/list.h src/list.c src/include/parser.h src/parser.c src/include/ast.h src/ast.c src/include/string_builder.h src/string_builder.c src/include/ir_optimizer.h src/include/ir.h src/ir.c src/ir_optimizer.c src/include/as_ir.h src/as_ir.c src/include/out.h src/as_c.c src/include/as_c.h src/include/file_util.h src/file_util.c)