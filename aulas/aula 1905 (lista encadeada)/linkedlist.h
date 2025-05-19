#ifndef _LINKEDLIST
#define _LINKEDLIST
// Type Definition
typedef struct list LinkedList;
typedef struct list_node ListNode;

// Functions

// Creates an empty list
LinkedList* create_list(); // basicamente, alocar memoria para a estrutura

// Checks whether the list is empty
int is_empty(LinkedList* l);

// Insert element into the list
void insert(LinkedList *l, int val);

// Print the list values
void print_values(LinkedList *l);

#endif

