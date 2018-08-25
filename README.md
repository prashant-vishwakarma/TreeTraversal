# TreeTraversal
Preorder and PostOrder traversal of Binary Tree

The program is to demonstrate basic Traversal technique in a binary tree.
A sample expression a-b*c-d/e+f is taken as a hardcoded tree in the constructor of our Tree Class
Tree representation:
                   (-)
              /          \
	          (-)          (+)
		       /  \         / \
	        a    (*)    (/)   f
        / \    / \
       b   c  d   e

Traversals on a tree can be done using two basic methods:
1. Using a Stack
2. Using Recursion(Implicit Stack)

I've used explicit STL stack hence,
#include<stack>

Node Class is a basic Node implementation with Char data type
A better implementation could use private generic data items with getter and setter functions

Preorder Traversal Algorithm:

1. if root Node is not null
				set root node as currentNode
				push current node into stack
		else return
2. while stack is not empty:
				pop top element to currentNode
				read currentNode
				if currentNode's leftPointer is NOT NULL
						push leftPointer to stack
				if currentNode's rightPointer is NOT NULL
						push rightPointer to stack
						
				
				


void Tree::displayPostOrder() {
	stack<Node*> s, d;			//s to Order	d to Reverse
	int count = 0;				//Explicit element counter
	Node *temp;					//iteration mean
	temp = root;
	if (temp != NULL) {
		s.push(temp);
	}
	while (!s.empty()) {
		temp = s.top();
		s.pop();
		d.push(temp);
		count++;
		if (temp->left != NULL) {
			s.push(temp->left);
		}
		if (temp->right != NULL) {
			s.push(temp->right);
		}
	}
	for (int i = 0; i < count; i++) {		//Increases Space Complexity
		temp = d.top();
		temp->visit();
		d.pop();
	}
}

int main() {
	cout << "Program to Print Post Order Sequence" << endl;
	Tree t;
	cout << "PreOrder" << endl;
	t.displayPreOrder();
	cout << endl;
	cout << "PostOrder" << endl;
	t.displayPostOrder();
	return 0;
}
