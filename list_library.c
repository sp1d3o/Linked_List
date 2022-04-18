#include "list_library.h"

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

node_t *search_list(list_t *list, int mark)
{
    if(list == NULL || list->b_node == NULL) {
        fprintf(stderr, "You fucked up!\n");
        fflush(stderr);
        return NULL;
    }

    node_t  *current = list->b_node;

    while(current != NULL && current->data != mark) {
        current = current->next;
    }

    return current;
}

void del_after(list_t *list, int mark)
{
    if(list == NULL) {
        fprintf(stderr, "You fucked up!\n");
        fflush(stderr);
        return;
    }

    node_t *it = search_list(list, mark);       //it is node before node that will be deleted

    if(it != NULL) {
        node_t *tmp = it->next;
        if (tmp != NULL) {
            it->next = tmp->next;
            free(tmp);
        }
    }
}

void del_before(list_t *list, int mark) {

    if (list == NULL) {
        fprintf(stderr, "You fucked up!\n");
        fflush(stderr);
        return;
    }

    node_t *it = search_list(list, mark);

    if(it != list->b_node && it != NULL) {
        node_t *tmp = list->b_node;
        while (tmp->next != it) {
            tmp = tmp->next;
        }

        if(tmp == list->b_node) {
            list->b_node = it;
            free(tmp);
        }
        else {
            node_t *ref = list->b_node;
            while (ref->next != tmp) {
                ref = ref->next;
            }

            ref->next = it;
            free(tmp);
        }
    }
}

list_t *init_empty()
{
    list_t *empty_list = (list_t *)malloc(sizeof(list_t));

    empty_list->b_node = NULL;

    return empty_list;
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
