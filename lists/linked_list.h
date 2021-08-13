#ifndef linked_list_h
#define linked_list_h

#include "../node/node.h"

struct LinkedList {
  struct Node *head;
  int length;
};

struct LinkedList *llist_constructor();
void llist_destructor(struct LinkedList *linked_list);

struct Node *llist_retrieve(struct LinkedList *llist, int index);
void llist_insert(struct LinkedList *llist, int index, void *data, unsigned long size);
void llist_remove_node(struct LinkedList *llist, int index);

#endif