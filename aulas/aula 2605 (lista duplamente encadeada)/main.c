#include <stdio.h>
#include "linkedlist.h"
// LISTA DUPLAMENTE ENCADEADA

int main(){
    LinkedList *l = ll_create();

    if (ll_is_empty(l))
        printf("Está vazia\n");
    else
        printf("Não está vazia\n");

    return 0;
}