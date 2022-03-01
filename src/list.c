#include "include/list.h"

list_t* init_list(size_t item_size) {
    list_t* list = calloc(1, sizeof(list_t));

    list->size = 0;
    list->item_size = item_size;
    list->items = 0;

    return list;
}

void list_push(list_t* list, void* item) {
    list->size += 1;
    if (!list->items) {
        list->items = calloc(1, list->item_size);
    } else {
        void** new_items = realloc(list->items, (list->size * list->item_size));
        list->items = new_items;
    }
    list->items[list->size - 1ULL] = item;
}

void* list_get(list_t* list, size_t index) {
    return list->items[index];
}