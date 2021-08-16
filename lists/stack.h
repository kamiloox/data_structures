#ifndef stack_h
#define stack_h

#include <stdbool.h>

#include "linked_list.h"

typedef LinkedList Stack;

Stack *stack_constructor();
void stack_destructor(Stack *stack);

void stack_push(Stack *stack, void *data, unsigned long size);
void stack_pop(Stack *stack);
void *stack_top(Stack *stack);
bool stack_is_empty(Stack *stack);

#endif