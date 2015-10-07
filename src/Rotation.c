#include <stdio.h>
#include "Rotation.h"
#include "Node.h"

void rightRotate(Node **nodePtr){
  Node *currentRoot = (*nodePtr)->left; 
	Node *newRoot = currentRoot->right;
	currentRoot->right=(*nodePtr);
	(*nodePtr)->left = newRoot;
  *nodePtr = currentRoot;
}