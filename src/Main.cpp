#include<iostream>
#include<string>
#include<stack>

using namespace std;

//Node with data members in public domain
class Node {
public:

	//data members
	Node *left, *right;
	char data;				//all members considered as character type

	//constructors
	Node() :
			left(NULL), right(NULL), data(NULL) { //Default Constructor: Unused Here
	}
	Node(char d) :									//Constructor In Use Here
			left(NULL), right(NULL) {
		data = d;
	}
	Node(Node* l, Node* r, char d) {					//Unused Constructor
		left = l;
		right = r;
		data = d;
	}

	//member functions
	void visit() {							//Alternate Internal Print Function
		cout << " " << data;
	}

};

//Node Class Handler : Public
class Tree {
public:
	//data members
	Node *root;

	//Constructor: HardCoded Problem Statement a-b*c-d/e+f
	Tree() {
		root = new Node('-');
		root->left = new Node('-');
		root->right = new Node('+');
		root->left->left = new Node('a');
		root->left->right = new Node('*');
		root->right->left = new Node('/');
		root->right->right = new Node('f');
		root->left->right->left = new Node('b');
		root->left->right->right = new Node('c');
		root->right->left->left = new Node('d');
		root->right->left->right = new Node('e');
	}

	//member functions
	void displayPreOrder();					//PreOrder Display
	void displayPostOrder();				//PostOrder Display

	void visit(Node* p) {					//Main External Node Print Function
		cout << " " << p->data;
	}

};


void Tree::displayPreOrder() {
	stack<Node*> s;							//single stack needed
	Node *temp;								//Iteration mean
	temp = root;
	if (temp != NULL) {
		s.push(temp);
	}
	while (!s.empty()) {
		temp = s.top();
		s.pop();
		visit(temp);

		if (temp->right != NULL) {
			s.push(temp->right);
		}
		if (temp->left != NULL) {
			s.push(temp->left);
		}

	}
}

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
