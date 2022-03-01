#ifndef BF2C_TOKEN_H
#define BF2C_TOKEN_H

typedef struct TOKEN_STRUCT {
    enum {
        TOKEN_INCREMENT,
        TOKEN_DECREMENT,
        TOKEN_RIGHT,
        TOKEN_LEFT,
        TOKEN_OUTPUT,
        TOKEN_INPUT,
        TOKEN_LOOP_START,
        TOKEN_LOOP_END,
        TOKEN_EOF
    } type;
} token_t;

token_t* init_token(int type);

char* token_type_to_string(int type);

char* token_to_string(token_t* token);

#endif //BF2C_TOKEN_H