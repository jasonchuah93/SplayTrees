#include <stdio.h>
#include "SplayTrees.h"
#include "Rotation.h"


/*
  Function   : add a new element into the root 
  Parameter  :  1) rootPtr : refer to the root of the tree 
                2) addNode : refer to the node that is adding into the tree
  Return    : none              
*/
void addSplayTrees(Node **rootPtr,Node *addNode){
  Node *root = *rootPtr;
  if(root ==NULL){
    *rootPtr = addNode;
    return;
  }
  if(addNode->data < root->data){
    addSplayTrees(&root->left,addNode);
  }else if(addNode->data >= root->data){
    addSplayTrees(&root->right,addNode);
  }
  if(addNode->data < root->data ){
    rightRotate(rootPtr);
  }else if(addNode->data > root->data){
    leftRotate(rootPtr);
  }
}

/*
  Function   : delete an existed element in the root 
  Parameter  :  1) rootPtr : refer to the root of the tree 
                2) deleteNode : refer to the node that is delete from the tree
  Return    : deleted node               
*/

Node *delSplayTrees(Node **rootPtr,Node *deleteNode){
  
}

/*
  Function   : find an existed element in the root 
  Parameter  :  1) rootPtr : refer to the root of the tree 
                2) targetNode : refer to the node that is find from the tree
  Return    : found node               
*/

Node *findSplayTrees(Node **rootPtr, Node*targetNode){
    
}
