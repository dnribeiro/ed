#include "linkedlist.h"
#include <stdlib.h>
#include <stdio.h>

struct list {
    ListNode* first;
};

struct list_node {
    int valor; // valor que esta armazenando 
    ListNode* next; //ponteiro para o proximo elemento
};

LinkedList* create_list() {
    LinkedList *l = (LinkedList*) malloc(sizeof(LinkedList));
    l->first = NULL;

    return l;
}

int is_empty(LinkedList* l){
    return (l->first == NULL);
}

void insert(LinkedList *l, int val){
    ListNode* node = (ListNode*) malloc(sizeof(ListNode));
    node->valor = val;

    if (is_empty(l)) node->next = NULL; // Cenário 1: lista vazia 

    else node->next = l->first; //Cenário 2: lista não vazia
    l->first = node;
}

void print_values(LinkedList *l){
    for (ListNode* p = l->first; p != NULL; p = p->next) printf("%d\n", p->valor);
}