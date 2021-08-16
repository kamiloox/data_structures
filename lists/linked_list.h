#ifndef linked_list_h
#define linked_list_h

#include "../node/node.h"

typedef struct LinkedList {
  Node *head;
  int length;
} LinkedList;

LinkedList *llist_constructor();
void llist_destructor(LinkedList *linked_list);

Node *llist_retrieve(LinkedList *llist, int index);
void llist_insert(LinkedList *llist, int index, void *data, unsigned long size);
void llist_remove_node(LinkedList *llist, int index);

#endif