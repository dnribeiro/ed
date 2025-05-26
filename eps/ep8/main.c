#include <stdio.h>
#include "linkedlist.h"

int main(){
    LinkedList *l1 = ll_create();
    LinkedList *l2 = ll_create();
    LinkedList *l_concatenated = ll_create();

    for (int i = 0; i < 10; i++) ll_insert(l1, i);
    for (int i = 5; i < 20; i++) ll_insert(l2, i);

    l_concatenated = ll_concatenate(l1, l2);
    ll_print(l_concatenated);
    return 0;
}