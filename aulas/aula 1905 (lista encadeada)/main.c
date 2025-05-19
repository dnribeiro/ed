#include <stdio.h>
#include "linkedlist.h"
// LISTA SIMPLESMENTE ENCADEADA

int main(){
    LinkedList *l;

    l = create_list();

    insert(l, 10);
    insert(l, 9);
    insert(l, 8);
    insert(l, 7);
    insert(l, 6);
    insert(l, 5);
    insert(l, 4);
    insert(l, 3);
    insert(l, 2);
    insert(l, 1);
    
    if (is_empty(l)){
        printf("Está vazia!");
    } else print_values(l);

    return 0;
}