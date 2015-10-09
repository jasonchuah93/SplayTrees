#include <stdio.h>
#include "Rotation.h"
#include "Node.h"

/*
  Function   : rotate a node right from the root  
  Parameter  :  1) nodePtr : refer to the node that rotate
  Return    : none              
*/
void rightRotate(Node **nodePtr){
    Node *currentRoot = (*nodePtr)->left;         
    Node *newRoot = currentRoot->right;
    currentRoot->right=(*nodePtr);
    (*nodePtr)->left = newRoot;
    *nodePtr = currentRoot;
}

void leftRotate(Node **nodePtr){
    Node *currentRoot = (*nodePtr)->right;         
    Node *newRoot = currentRoot->left;
    currentRoot->left=(*nodePtr);
    (*nodePtr)->right = newRoot;
    *nodePtr = currentRoot;
}



