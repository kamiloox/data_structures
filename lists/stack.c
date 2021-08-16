#include "stack.h"

#include <stdbool.h>
#include <stdlib.h>

#include "linked_list.h"

Stack *stack_constructor() {
  Stack *stack = llist_constructor();

  return stack;
}

void stack_push(Stack *stack, void *data, unsigned long size) {
  llist_insert(stack, stack->length, data, size);
}

void stack_pop(Stack *stack) {
  return llist_remove_node(stack, stack->length - 1);
}

void *stack_top(Stack *stack) {
  return llist_retrieve(stack, stack->length - 1)->data;
}

bool stack_is_empty(Stack *stack) {
  if (stack->length == 0) return true;
  return false;
}