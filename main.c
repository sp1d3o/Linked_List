#include "list_library.h"

int main(int argc, char *argv[])
{
    /*list_t *List = (list_t *)malloc(sizeof(list_t));
    //list_t *List2 = (list_t *)malloc(sizeof(list_t));


    node_t *head = (node_t *)malloc(sizeof(node_t));
    node_t *second = (node_t *)malloc(sizeof(node_t));
    node_t *third = (node_t *)malloc(sizeof(node_t));
    node_t *fourth = (node_t *)malloc(sizeof(node_t));
    node_t *fifth = (node_t *)malloc(sizeof(node_t));

    List->b_node = head;

    *//*List2->b_node = NULL;
    List2->c_node = NULL;*//**//*

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = fifth;

    fifth->data = 5;
    fifth->next = NULL;*/


    list_t *List = init_empty();

    add_end(List, 1);
    add_end(List, 2);
    add_end(List, 3);
    add_end(List, 4);
    add_end(List, 5);

    print_list(List);

    del_all(List);
    print_list(List);
    printf("p\n");

    return 0;
}

