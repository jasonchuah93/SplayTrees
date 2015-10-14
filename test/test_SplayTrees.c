#include <stdio.h>
#include "unity.h"
#include "SplayTrees.h"
#include "Node.h"
#include "Rotation.h"
#include "CustomAssertions.h"
#include "CException.h"

void setUp(void){}

void tearDown(void){}

/*****************************************

	1 NODE tests

*******************************************/
/**
* root		         root
*	 |     add 10	  |
*	 v    ------>     v
*	NULL              10
**/

void test_addSplayTrees_add_value_10_into_the_tree(void){
  Node node10 = {.left=NULL, .right=NULL, .data = 10};
  Node *root = NULL;
  
  addSplayTrees(&root,&node10);
  
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,root);
}

/*****************************************

	2 NODE tests

*******************************************/
/**
*  root		        root                        root
*	 |     add 7	 |     rotate                |
*	 v    ------>    v     right at 10           v
*	10              10  --------------->         7
*                  /                              \
*                 7                                10
**/

void test_addSplayTrees_add_value_7_into_the_tree_with_root_10_and_should_rotate_right(void){
  Node node7 = {.left=NULL, .right=NULL, .data = 7};
  Node node10 = {.left=NULL, .right=NULL, .data = 10};
  Node *root = &node10;
  
  addSplayTrees(&root,&node7);
  
  TEST_ASSERT_EQUAL_PTR(&node7,root);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,&node10);
  TEST_ASSERT_EQUAL_NODE(NULL,&node10,root);
}

/**
*  root		         root                        root
*	 |     add 15	  |         rotate            |
*	 v    ------->    v        left at 10         v
*	10                10    --------------->      15
*                      \                          /
*                      15                       10
**/

void test_addSplayTrees_add_value_15_into_the_tree_with_root_10_and_should_rotate_left(void){
  Node node10 = {.left=NULL, .right=NULL, .data = 10};
  Node node15 = {.left=NULL, .right=NULL, .data = 15};
  Node *root = &node10;
  
  addSplayTrees(&root,&node15);
  
  TEST_ASSERT_EQUAL_PTR(&node15,root);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,&node10);
  TEST_ASSERT_EQUAL_NODE(&node10,NULL,root);
}

/*****************************************

	3 NODE tests

*******************************************/
/**
*     root               root                      root                      root
*	   |                   |                         |                        |
*	   v                   v                         v                        v
*	   7      add 20       7     rotate left         7      rotate left       20
*       \     ------>       \    at 10                \      at 7             /
*        10                 10   ------------>        20    ------------>    7
*                             \                         \                     \
*                             20                        10                    10
**/

void test_addSplayTrees_add_value_20_into_the_tree_with_root_7_and_should_rotate_left_left(void){
  Node node10 = {.left=NULL, .right=NULL, .data = 10};
  Node node20 = {.left=NULL, .right=NULL, .data = 20};
  Node node7 = {.left=NULL, .right=&node10, .data = 7};
  Node *root = &node7;
  
  addSplayTrees(&root,&node20);
  
  TEST_ASSERT_EQUAL_PTR(&node20,root);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,&node10);
  TEST_ASSERT_EQUAL_NODE(NULL,&node10,&node7);
  TEST_ASSERT_EQUAL_NODE(&node7,NULL,root);
}

/*****************************************

	4 NODE tests

*******************************************/
/**
*     root               root                      root                     root                      root
*	   |                   |                         |                       |                          |
*	   v                   v                         v                       v                          v
*	   20    add 15        20     rotate left       20    rotate left       20    rotate right          15
*      /     ------>       /       at 10            /     at 7             /      at 20                /  \
*     7                   7     ------------>       7    ------------>    15       ------------->      7   20
*      \                   \                        \                    /                              \
*      10                   10                      15                  7                               10
*                            \                      /                    \
*                            15                    10                    10
**/
void test_addSplayTrees_add_value_15_into_the_tree_with_root_20_and_should_rotate_left_left_right(void){
  Node node15 = {.left=NULL, .right=NULL, .data = 15};
  Node node10 = {.left=NULL, .right=NULL, .data = 10};
  Node node7 = {.left=NULL, .right=&node10, .data = 7};
  Node node20 = {.left=&node7, .right=NULL, .data = 20};
  Node *root = &node20;
  
  addSplayTrees(&root,&node15);
  
  TEST_ASSERT_EQUAL_PTR(&node15,root);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,&node10);
  TEST_ASSERT_EQUAL_NODE(NULL,&node10,&node7);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,&node20);
  TEST_ASSERT_EQUAL_NODE(&node7,&node20,&node15);
}

/**
*     root               root                      root                     root                      root
*	   |                   |                         |                       |                          |
*	   v                   v                         v                       v                          v
*	   20    add 9        20     rotate right       20    rotate left       20    rotate right          9
*      /     ------>       /       at 10            /     at 7             /      at 20                / \
*     7                   7     ------------>       7    ------------>    9     ------------->        7  20
*      \                   \                         \                   /                               /
*      10                   10                        9                 7                               10
*                           /                          \                 \
*                          9                           10                10
**/
void test_addSplayTrees_add_value_9_into_the_tree_with_root_20_and_should_rotate_left_left_right(void){
  Node node9 = {.left=NULL, .right=NULL, .data = 9};
  Node node10 = {.left=NULL, .right=NULL, .data = 10};
  Node node7 = {.left=NULL, .right=&node10, .data = 7};
  Node node20 = {.left=&node7, .right=NULL, .data = 20};
  Node *root = &node20;
  
  addSplayTrees(&root,&node9);
  
  TEST_ASSERT_EQUAL_PTR(&node9,root);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,&node10);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,&node7);
  TEST_ASSERT_EQUAL_NODE(&node10,NULL,&node20);
  TEST_ASSERT_EQUAL_NODE(&node7,&node20,&node9);
}

/**
*     root               root                      root                     
*	   |                   |                         |                      
*	   v                   v                         v                      
*	   20    add 30        20      rotate left       30  
*      /     ------>      / \       at 20            /     
*     7                  7  30     ------------>    20    
*      \                  \                        /                
*      10                 10                      7               
*                                                  \              
*                                                  10              
**/
void test_addSplayTrees_add_value_30_into_the_tree_with_root_20_and_should_rotate_left(void){
  Node node30 = {.left=NULL, .right=NULL, .data = 30};
  Node node10 = {.left=NULL, .right=NULL, .data = 10};
  Node node7 = {.left=NULL, .right=&node10, .data = 7};
  Node node20 = {.left=&node7, .right=NULL, .data = 20};
  Node *root = &node20;
  
  addSplayTrees(&root,&node30);
  
  TEST_ASSERT_EQUAL_PTR(&node30,root);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,&node10);
  TEST_ASSERT_EQUAL_NODE(NULL,&node10,&node7);
  TEST_ASSERT_EQUAL_NODE(&node7,NULL,&node20);
  TEST_ASSERT_EQUAL_NODE(&node20,NULL,&node30);
}

/**
*     root               root                      root                       root    
*	   |                   |                         |                         |
*	   v                   v                         v                         v
*	   20    add 1        20      rotate right      20    rotate right         1
*      /     ------>      /        at 7            /      at 20                 \
*     7                  7       ------------>    1     --------------->         20
*      \               /  \                        \                             /
*      10             1    10                       7                           7    
*                                                    \                           \
*                                                    10                          10
**/
void test_addSplayTrees_add_value_1_into_the_tree_with_root_20_and_should_rotate_right_right(void){
  Node node1 = {.left=NULL, .right=NULL, .data = 1};
  Node node10 = {.left=NULL, .right=NULL, .data = 10};
  Node node7 = {.left=NULL, .right=&node10, .data = 7};
  Node node20 = {.left=&node7, .right=NULL, .data = 20};
  Node *root = &node20;
  
  addSplayTrees(&root,&node1);
  
  TEST_ASSERT_EQUAL_PTR(&node1,root);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,&node10);
  TEST_ASSERT_EQUAL_NODE(NULL,&node10,&node7);
  TEST_ASSERT_EQUAL_NODE(&node7,NULL,&node20);
  TEST_ASSERT_EQUAL_NODE(NULL,&node20,&node1);
}

/**
*     root                root                   root                    root                              
*	   |                    |                      |                       |                         
*	   v                    v                      v                       v                        
*	   20    locate 10      20    rotate left     20    rotate right       10            
*      /     --------->    /       at 7           /     at 20             /  \    
*     7                   7     ------------>    10    -------------->   7   20
*      \                   \                    /  \                         /                
*      10                   10                 7   15                       15                       
*        \                   \                                         
*        15                   15                                       
**/
void test_findSplayTrees_find_value_10_in_the_tree(void){
  Node node15 = {.left=NULL, .right=NULL, .data = 15};
  Node node10 = {.left=NULL, .right=&node15, .data = 10};
  Node node7 = {.left=NULL, .right=&node10, .data = 7};
  Node node20 = {.left=&node7, .right=NULL, .data = 20};
  Node *root = &node20;
  
  findSplayTrees(&root,&node10);
  
  TEST_ASSERT_EQUAL_PTR(&node10,root);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,&node15);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,&node7);
  TEST_ASSERT_EQUAL_NODE(&node15,NULL,&node20);
  TEST_ASSERT_EQUAL_NODE(&node7,&node20,&node10);
}