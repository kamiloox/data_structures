#include <stdio.h>

#include "lists/linked_list.h"
#include "lists/stack.h"

#define ARR_LENGTH 4

int main() {
  struct LinkedList *llist = llist_constructor();
  int arr[ARR_LENGTH] = {5, 10, 15, 20};

  printf("\n------ LinkedList -------\n");

  for (int i = 0; i < ARR_LENGTH; i++) {
    llist_insert(llist, i, &arr[i], sizeof(arr[i]));
  }

  printf("\nbefore remove:\n");
  for (int i = 0; i < ARR_LENGTH; i++) {
    printf("inserted %d -> %d\n", i, *(int *)llist_retrieve(llist, i)->data);
  }

  llist_remove_node(llist, 2);

  printf("\nafter remove 2 index:\n");
  for (int i = 0; i < ARR_LENGTH - 1; i++) {
    printf("inserted %d -> %d\n", i, *(int *)llist_retrieve(llist, i)->data);
  }

  printf("\n\nllist length -> %d\n", llist->length);

  printf("\n------ Stack -------\n");
  Stack *stack = stack_constructor();
  stack_push(stack, &arr[1], sizeof(arr[0]));
  stack_push(stack, &arr[2], sizeof(arr[0]));
  stack_push(stack, &arr[3], sizeof(arr[0]));

  printf("%d\n", *(int *)stack_top(stack));

  stack_pop(stack);
  printf("length %d\n", stack->length);
  printf("%d\n", *(int *)stack_top(stack));
}