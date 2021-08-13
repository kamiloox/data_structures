#ifndef node_h
#define node_h

struct Node {
  void *data;

  struct Node *next;
};

struct Node *node_constructor(void *data, unsigned long size);

void node_destructor(struct Node *node);

#endif
