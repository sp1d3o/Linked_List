#ifndef MAIN_C_LIST_LIBRARY_H
#define MAIN_C_LIST_LIBRARY_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} node_t;

typedef struct List {
    node_t *b_node;
} list_t;

void print_list(list_t *list);
void add_start(list_t *list, int new_data);
void add_end(list_t *list, int new_data);
void del_after(list_t *list, int mark);
void del_before(list_t *list, int mark);
list_t *init_empty();
void del_all(list_t *list);
node_t *search_list(list_t *list, int mark);

#endif //MAIN_C_LIST_LIBRARY_H
