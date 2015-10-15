#include <stdio.h>
#include <string.h>
#include "SplayTrees.h"
#include "Rotation.h"
#include "Error.h"
#include "CException.h"


/*
  Function   : add a new element into the root 
  Parameter  :  1) rootPtr : refer to the root of the tree 
                2) addNode : refer to the node that is adding into the tree
  Return    : none              
*/
void addSplayTrees(Node **rootPtr,Node *addNode){
  Node *root = *rootPtr;
  if(root==NULL){
    *rootPtr = addNode;
    return;
  }else{
      if(addNode->data < root->data){
        addSplayTrees(&root->left,addNode);
        rightRotate(rootPtr);
      }else if(addNode->data >= root->data){
        addSplayTrees(&root->right,addNode);
        leftRotate(rootPtr);
      }
  }
}

/*
  Function   : delete an existed element in the root 
  Parameter  :  1) rootPtr : refer to the root of the tree 
                2) deleteNode : refer to the node that is delete from the tree
  Return    : deleted node               
*/

Node *delSplayTrees(Node **rootPtr,Node *deleteNode){
    Node* node; Node *root = *rootPtr;
    if(root==NULL){
        Throw(ERROR_NODE_NOT_FOUND);
    }else{ 
        if(root == deleteNode){
            *rootPtr = NULL;
            if(root->left){
                *rootPtr = root->left;
            }else if(root->right){
                *rootPtr = root->right;
            }
        }else if(deleteNode->data < root->data){
            rightRotate(rootPtr);
            node = delSplayTrees(rootPtr,deleteNode);
        }else if(deleteNode->data >= root->data){
            leftRotate(rootPtr);
            node = delSplayTrees(rootPtr,deleteNode);
        }
    }
    return node;
}

/*
  Function   : find an existed element in the root 
  Parameter  :  1) rootPtr : refer to the root of the tree 
                2) targetNode : refer to the node that is find from the tree
  Return    : found node               
*/

Node *findSplayTrees(Node **rootPtr, Node*targetNode){
   Node *root = *rootPtr;
   if(root==NULL){
       Throw(ERROR_NODE_NOT_FOUND);
   }else{
       if(targetNode->data == root->data){
           *rootPtr = targetNode;
       }else if(targetNode->data >= root->data){
           findSplayTrees(&root->right,targetNode);
           leftRotate(rootPtr);
       }else if(targetNode->data < root->data){
           findSplayTrees(&root->left,targetNode);
           rightRotate(rootPtr);
       }
   }
   return targetNode;    
}
