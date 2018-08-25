# TreeTraversal
Preorder and PostOrder traversal of Binary Tree

The program is to demonstrate basic Traversal technique in a binary tree.
A sample expression a-b*c-d/e+f is taken as a hardcoded tree in the constructor of our Tree Class
Tree representation:
.               (-)
.          /          \
.        (-)          (+)
.       /  \          / \
.      a    (*)    (/)   f
.     / \    / \
.    b   c  d   e

Traversals on a tree can be done using two basic methods:
1. Using a Stack
2. Using Recursion(Implicit Stack)

I've used explicit STL stack hence,
#include<stack>

Node Class is a basic Node implementation with Char data type
A better implementation could use private generic data items with getter and setter functions

------------------------------------------------------------------------
Preorder Traversal Algorithm:
-----------------------------

1. if root Node is not null
				set currentNodePointer to root
				push currentNodePointer into stack
		else return
2. while stack is not empty:
				pop top element to currentNodePointer
				read currentNodePointer
				if currentNode's leftPointer is NOT NULL
						push leftPointer to stack
				if currentNode's rightPointer is NOT NULL
						push rightPointer to stack

--------------------------------------------------------------------------

PostOrder can be implemented using a slightly different algorithm, but just to simplyfy, I change the order of stack push and then flip the output using another stack.

----------------------------------------------
Postorder Traversal Algorithm:
------------------------------

1. if root Node is not null
				set currentNodePointer to root
				push currentNodePointer into stack
		else return
2. while stack is not empty:
				pop top element to currentNodePointer
				push currentNodePointer to secondStack
				if currentNode's rightPointer is NOT NULL
						push rightPointer to stack
				if currentNode's leftPointer is NOT NULL
						push leftPointer to stack
3. while secondStack is not empty:
				pop an element into tempPointer
				read TempPointer
				
---------------------------------------------------------
