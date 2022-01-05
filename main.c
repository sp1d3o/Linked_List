#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *next;
} node_t;

typedef struct List {
    node_t *b_node;
    node_t *c_node;
} list_t;

void print_list(list_t *list);
void add_start(list_t *list, int new_data);
void add_end(list_t *list, int new_data);
void del_after(list_t *list, int mark);
void del_before(list_t *list, int mark);
void init_empty();
void del_all(list_t *list);

int main(int argc, char *argv[])
{
    list_t *List = (list_t *)malloc(sizeof(list_t));
    //list_t *List2 = (list_t *)malloc(sizeof(list_t));


    node_t *head = (node_t *)malloc(sizeof(node_t));
    node_t *second = (node_t *)malloc(sizeof(node_t));
    node_t *third = (node_t *)malloc(sizeof(node_t));
    node_t *fourth = (node_t *)malloc(sizeof(node_t));
    node_t *fifth = (node_t *)malloc(sizeof(node_t));

    List->b_node = head;
    List->c_node = NULL;

    /*List2->b_node = NULL;
    List2->c_node = NULL;*/

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = fifth;

    fifth->data = 5;
    fifth->next = NULL;

    print_list(List);
    add_start(List, 9);
    print_list(List);
    add_end(List, 7);
    print_list(List);
    del_after(List, 7);
    print_list(List);
    del_before(List, 1);
    print_list(List);

    return 0;
}

void add_start(list_t *list, int new_data)
{
    if(NULL == list) {
        fprintf(stderr, "You fucked up!\n");
        fflush(stderr);
        return;
    }

    node_t *new = (node_t *)malloc(sizeof(node_t));

    new->data = new_data;

    new->next = list->b_node;
    list->b_node = new;
}

void print_list(list_t *list)
{
    if(NULL == list ) {
        fprintf(stderr, "You fucked up!\n");
        fflush(stderr);
        return;
    }
    node_t  *current = list->b_node;

    while(current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
    printf("\n");
}

void add_end(list_t *list, int new_data)
{
    if(list == NULL) {
        fprintf(stderr, "You fucked up!\n");
        fflush(stderr);
        return;
    }

    node_t *new = (node_t *)malloc(sizeof(node_t));
    node_t *it;

    new->data = new_data;
    new->next = NULL;

    it = list->b_node;
    while(it != NULL) {
        if(it->next == NULL) {
            break;
        }
        it = it->next;
    }

    if(list->b_node == NULL) {
       list->b_node = new;
    }
    else {
        it->next = new;
    }
}

void search_list(list_t *list, int mark)
{
    if(list == NULL) {
        fprintf(stderr, "You fucked up!\n");
        fflush(stderr);
        return;
    }

    node_t *it = list->b_node;

    while(it != NULL) {
        if(it->data == mark) {
            break;
        }
        it = it->next;
    }

    list->c_node = it;
}
void del_after(list_t *list, int mark)                                      //3 ukazuje na 4, 4 ukazuje na 5, 4 mažeme
{
    search_list(list, mark);

    if(list == NULL || list->c_node == NULL) {
        fprintf(stderr, "You fucked up!\n");
        fflush(stderr);
        return;
    }

    node_t *tmp = list->c_node->next;

    if(tmp != NULL) {
        list->c_node->next = tmp->next;
        free(tmp);
    }
}

void del_before(list_t *list, int mark) {
    search_list(list, mark);

    if (list == NULL || list->c_node == NULL) {
        fprintf(stderr, "You fucked up!\n");
        fflush(stderr);
        return;
    }

    if (list->c_node != list->b_node) {

        node_t *it = list->b_node;

        while (it->next != list->c_node) {
            it = it->next;
        }

        if (it == list->b_node) {
            list->b_node = list->c_node;
            free(it);
        }
        else {
            node_t *tmp = it;

            it = list->b_node;

            while (it->next != tmp) {
                it = it->next;
            }

            it->next = tmp->next;
            free(tmp);

        }
    }
}

void init_empty()
{
    list_t *empty_list = (list_t *)malloc(sizeof(list_t));

    empty_list->b_node = NULL;
    empty_list->c_node = NULL;
}

void del_all(list_t *list)
{
    node_t *current = list->b_node;
    node_t *ptr;

    while(current != NULL) {
        ptr = current->next;
        free(current);
        current = ptr;
    }

    list->b_node = NULL;
}