#include "node.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Node *node_constructor(void *data, unsigned long size) {
  Node *node = malloc(sizeof(Node));

  node->data = malloc(size);
  memcpy(node->data, data, size);

  node->next = NULL;

  return node;
}

void node_destructor(Node *node) {
  free(node->data);
  free(node);
}
