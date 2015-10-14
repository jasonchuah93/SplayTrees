#ifndef SplayTrees_H
#define SplayTrees_H

#include "Node.h"

void addSplayTrees(Node **rootPtr,Node *addNode);
Node *delSplayTrees(Node **rootPtr,Node *deleteNode);
Node *findSplayTrees(Node **rootPtr, Node*targetNode);

#endif // SplayTrees_H
