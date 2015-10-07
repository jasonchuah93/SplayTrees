#include "unity.h"
#include "CustomAssertions.h"

/**
* Custom assertion of Splay Trees node
**/
void assertNode(Node *left,Node *right,Node *actualNode,int lineNumber){
		//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ ^^^^^^^^^^^^^^^^
		//			Expected contents				Actual content
		//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ ^^^^^^^^^^^^^^^^
	UNITY_TEST_ASSERT_EQUAL_PTR(left,actualNode->left,lineNumber,"Wrong left node");
	UNITY_TEST_ASSERT_EQUAL_PTR(right,actualNode->right,lineNumber,"Wrong right node");
}



