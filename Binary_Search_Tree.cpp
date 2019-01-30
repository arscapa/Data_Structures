#include <iostream>

struct BstNode {
	int data;
	BstNode* left;
	BstNode* right;
};

BstNode* GetNewNode(int data) {
	BstNode* newNode = new BstNode();;
	newNode->data = data;
	newNode->left = newNode->right = NULL;	// set left and right childs of node to NULL
	return newNode;
}

BstNode* Insert(BstNode* head, int data){		// return type of function is pointer, we will need to collect this and update the root variable in main as head's scope is limited to this function	
	if (head == NULL) {		// empty tree
		head = GetNewNode(data);		// root in this function is local variable within function
	}
	else if (data <= head->data){
		head->left = Insert(head->left,data);
	}
	else{
		head->right = Insert(head->right,data);
	}
	return head;
}


bool Search(BstNode* head, int data) {
	// Tree is empty or reached last item
	if (head == NULL){ return false; }
	// Found data
	else if (data == head->data){ return true; }
	// Data less than current node
	else if (data < head->data){ return Search(head->left,data); }
	// Data greater than current node
	else { return Search(head->right,data); }
}

int main() {
	BstNode* root = NULL;	// Creating an empty tree
	root = Insert(root,15);		// collecting pointer returned from 'insert' function and updating root
	root = Insert(root,10);
	root = Insert(root,20);
	root = Insert(root,25);
	root = Insert(root,74);
	
	int number;
	std::cout << "Enter a number to be searched\n";
	std::cin >> number;
	if(Search(root,number)==true) std::cout<< "Found\n";
	else std::cout << "Not found\n";
	
}
