#ifndef BF2C_LIST_H
#define BF2C_LIST_H

#include <stddef.h>

typedef struct {
    void** items;
    size_t size;
    size_t item_size;
} list_t;

list_t* init_list(size_t item_size);

void list_push(list_t* list, void* item);

void* list_get(list_t* list, size_t index);

#endif //BF2C_LIST_H
