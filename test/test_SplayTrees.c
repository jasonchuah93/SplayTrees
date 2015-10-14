#include <stdio.h>
#include "unity.h"
#include "SplayTrees.h"
#include "Node.h"
#include "Rotation.h"
#include "CustomAssertions.h"
#include "Error.h"
#include "CException.h"

void setUp(void){}
void tearDown(void){}

/*****************************************

	addSplayTrees

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

/*****************************************

	findSplayTrees

*******************************************/
/**
*  root		             root
*	 |     locate 10	  |
*	 v    ---------->     v
*	NULL                 NULL <------ Element 10 not found 
**/

void test_findplayTrees_find_value_10_in_empty_tree_should_throw_error(void){
  Node node10 = {.left=NULL, .right=NULL, .data = 10};
  Node *root = NULL;
  ErrorNode e;
  Try{
      findSplayTrees(&root,&node10);
      TEST_FAIL_MESSAGE("Element not found")
  }
  Catch(e){
      TEST_ASSERT_EQUAL(ERROR_NODE_NOT_FOUND,e);
  }
}

/**
*  root		             root
*	 |     locate 10	  |
*	 v    ---------->     v
*	 10                   10 <------ Element 10 found 
**/
void test_findSplayTrees_find_value_10_in_tree_should_find_10_and_become_root(void){
  Node node10 = {.left=NULL, .right=NULL, .data = 10};
  Node *root = &node10;
  Node *targetNode;
  
  targetNode = findSplayTrees(&root,&node10);
  
  TEST_ASSERT_NOT_NULL(targetNode);
  TEST_ASSERT_EQUAL_PTR(root,targetNode);
}

/**
*  root		             root
*	 |     locate 10	  |
*	 v    ---------->     v
*	 10                   10 <------ Element 10 found 
*      \                   \
*      30                  30
**/
void test_findSplayTrees_find_value_10_in_tree_with_child_and_become_root(void){
  Node node30 = {.left=NULL, .right=NULL, .data = 30};
  Node node10 = {.left=NULL, .right=&node30, .data = 10};
  Node *root = &node10;
  Node *targetNode;
  
  targetNode = findSplayTrees(&root,&node10);
  
  TEST_ASSERT_NOT_NULL(targetNode);
  TEST_ASSERT_EQUAL_PTR(root,targetNode);
}

/**
*  root		             root                          root       
*	 |     locate 30	  |                              |
*	 v    ---------->     v                              v
*	 10                   10                             30
*      \                   \                            / 
*      30                  30 <-- Element 30 found     10
*                                 and rotate left
**/
void test_findSplayTrees_find_value_30_in_tree_and_become_root(void){
  Node node30 = {.left=NULL, .right=NULL, .data = 30};
  Node node10 = {.left=NULL, .right=&node30, .data = 10};
  Node *root = &node10;
  Node *targetNode;
  
  targetNode = findSplayTrees(&root,&node30);
  
  TEST_ASSERT_NOT_NULL(targetNode);
  TEST_ASSERT_EQUAL_PTR(root,targetNode);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,&node10);
  TEST_ASSERT_EQUAL_NODE(&node10,NULL,&node30);
}

/**
*  root		                          root             root       
*	 |     locate 5	                   |                 |
*	 v    ---------->                  v                 v
*	 10                               10     ------->    5            
*   /  \                             /  \                 \
*  5    30      Element 5 found --> 5    30                10
*               and rotate right                            \
*                                                            30
**/
void test_findSplayTrees_find_value_5_in_tree_and_become_root(void){
  Node node5 = {.left=NULL, .right=NULL, .data = 5};
  Node node30 = {.left=NULL, .right=NULL, .data = 30};
  Node node10 = {.left=&node5, .right=&node30, .data = 10};
  Node *root = &node10;
  Node *targetNode;
  
  targetNode = findSplayTrees(&root,&node5);
  
  TEST_ASSERT_NOT_NULL(targetNode);
  TEST_ASSERT_EQUAL_PTR(root,targetNode);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,&node30);
  TEST_ASSERT_EQUAL_NODE(NULL,&node30,&node10);
  TEST_ASSERT_EQUAL_NODE(NULL,&node10,&node5);
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
void test_findSplayTrees_find_value_10_in_the_tree_and_become_root(void){
  Node node15 = {.left=NULL, .right=NULL, .data = 15};
  Node node10 = {.left=NULL, .right=&node15, .data = 10};
  Node node7 = {.left=NULL, .right=&node10, .data = 7};
  Node node20 = {.left=&node7, .right=NULL, .data = 20};
  Node *root = &node20;
  Node *targetNode;
  
  targetNode = findSplayTrees(&root,&node10);
  
  TEST_ASSERT_NOT_NULL(targetNode);
  TEST_ASSERT_EQUAL_PTR(root,targetNode);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,&node15);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,&node7);
  TEST_ASSERT_EQUAL_NODE(&node15,NULL,&node20);
  TEST_ASSERT_EQUAL_NODE(&node7,&node20,&node10);
}

/**
*    root                                     root             root
*     |                                        |                 |
*     v                                        v                 v
*     10                    Element 7 found    10                7
*    /  \  locate 7         and rotate right  /  \                \
*   7   20 -------->        ---------------> 7   20 ------>        10   
*       /                                        /                   \
*      15                                       15                   20            
*                                                                    /
*                                                                   15
**/
void test_findSplayTrees_find_value_7_in_the_tree_and_become_root(void){
  Node node15 = {.left=NULL, .right=NULL, .data = 15};
  Node node7 = {.left=NULL, .right=NULL, .data = 7};
  Node node20 = {.left=&node15, .right=NULL, .data = 20};
  Node node10 = {.left=&node7, .right=&node20, .data = 10};
  Node *root = &node10;
  Node *targetNode;
  
  targetNode = findSplayTrees(&root,&node7);
  
  TEST_ASSERT_NOT_NULL(targetNode);
  TEST_ASSERT_EQUAL_PTR(root,targetNode);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,&node15);
  TEST_ASSERT_EQUAL_NODE(&node15,NULL,&node20);
  TEST_ASSERT_EQUAL_NODE(NULL,&node20,&node10);
  TEST_ASSERT_EQUAL_NODE(NULL,&node10,&node7);
}

/**
*    root                  root                           root                       root
*     |                     |                               |                         |
*     v                     v                               v                         v
*     10                   10                               10                        15
*    /  \  locate 15      /  \    Element 15 found         /  \     Rotate left      /  \  
*   7   20 --------->    7   20   and rotate right        7   15    at 10           10  20
*       /                   /    ------------------>            \   ------------>  /       
*      15                  15                                   20                7
*                                                                    
*                                                                   
**/
void test_findSplayTrees_find_value_15_in_the_tree_and_become_root(void){
  Node node15 = {.left=NULL, .right=NULL, .data = 15};
  Node node7 = {.left=NULL, .right=NULL, .data = 7};
  Node node20 = {.left=&node15, .right=NULL, .data = 20};
  Node node10 = {.left=&node7, .right=&node20, .data = 10};
  Node *root = &node10;
  Node *targetNode;
  
  targetNode = findSplayTrees(&root,&node15);
  
  TEST_ASSERT_NOT_NULL(targetNode);
  TEST_ASSERT_EQUAL_PTR(root,targetNode);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,&node7);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,&node20);
  TEST_ASSERT_EQUAL_NODE(&node7,NULL,&node10);
  TEST_ASSERT_EQUAL_NODE(&node10,&node20,&node15);
}

/*****************************************

	delSplayTrees

*******************************************/
/**
*  root		             root
*	 |     delete 10	  |
*	 v    ---------->     v
*	NULL                 NULL <------ Element 10 not found 
**/
void test_delplayTrees_delete_value_10_in_empty_tree_should_throw_error(void){
  Node node10 = {.left=NULL, .right=NULL, .data = 10};
  Node *root = NULL;
  ErrorNode e;
  Try{
      delSplayTrees(&root,&node10);
      TEST_FAIL_MESSAGE("Element not found")
  }
  Catch(e){
      TEST_ASSERT_EQUAL(ERROR_NODE_NOT_FOUND,e);
  }
}

/**
*  root		             root
*	 |     delete 100	  |
*	 v    ----------->    v
*	100                  NULL 
**/
void test_delSplayTrees_delete_value_100_in_tree_and_tree_become_NULL(void){
  Node node100 = {.left=NULL, .right=NULL, .data = 100};
  Node *root = &node100;
  
  delSplayTrees(&root,&node100);
  
  TEST_ASSERT_EQUAL_PTR(NULL,root);
}

