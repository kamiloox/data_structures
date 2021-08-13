#include "linked_list.h"

#include <stdlib.h>

struct LinkedList *llist_constructor() {
  struct LinkedList *linked_list = malloc(sizeof(struct LinkedList));

  linked_list->head = NULL;
  linked_list->length = 0;

  return linked_list;
}

struct Node *llist_retrieve(struct LinkedList *llist, int index) {
  if (index < 0 || index > llist->length - 1) {
    return NULL;
  }

  struct Node *cursor = llist->head;

  if (cursor == NULL) return NULL;

  for (int i = 0; i < index; i++) {
    cursor = cursor->next;
  }

  return cursor;
}

void llist_insert(struct LinkedList *llist, int index, void *data, unsigned long size) {
  struct Node *node_to_insert = node_constructor(data, size);

  if (index == 0) {
    node_to_insert->next = llist->head;
    llist->head = node_to_insert;
  } else {
    struct Node *cursor = llist_retrieve(llist, index - 1);

    if (cursor) {
      node_to_insert->next = cursor->next;
      cursor->next = node_to_insert;
    }
  }

  llist->length += 1;
}

void llist_remove_node(struct LinkedList *llist, int index) {
  if (index == 0) {
    struct Node *node_to_remove = llist->head;
    if (node_to_remove != NULL) {
      llist->head = node_to_remove->next;
      node_destructor(node_to_remove);
      llist->length -= 1;
    }
  } else {
    struct Node *cursor = llist_retrieve(llist, index - 1);

    struct Node *node_to_remove = cursor->next;

    if (cursor && node_to_remove) {
      cursor->next = node_to_remove->next;
      node_destructor(node_to_remove);
      llist->length -= 1;
    }
  }
}
