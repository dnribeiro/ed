#ifndef STACK_H
#define STACK_H

typedef struct stack Stack;
typedef struct stacknode StackNode;

Stack *s_create();

float s_pop(Stack *s);

float s_top(Stack *s);

void s_push(Stack *s, float v);

int s_is_empty(Stack *s);

void s_free(Stack *s);

void s_print(Stack *s);

#endif