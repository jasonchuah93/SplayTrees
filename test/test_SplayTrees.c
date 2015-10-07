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
* root		       root
*	 |     add 10	  |
*	 v    ------>   v
*	NULL           10
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
* root		        root                        root
*	 |     add 7	   |     rotate                |
*	 v    ------>    v     right at 10           v
*	10              10  --------------->         7
*                 /                            \
*                7                             10
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
