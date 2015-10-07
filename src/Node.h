#ifndef Node_H
#define Node_H

typedef struct Node Node;

struct Node{
  Node *left;
  Node *right;
  int data;
};

#endif // Node_H
