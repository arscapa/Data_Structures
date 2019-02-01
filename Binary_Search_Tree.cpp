#include <iostream>
#include<queue>

struct BstNode {
	int data;
	BstNode* left;
	BstNode* right;
};


//Function to find minimum in a tree. 
BstNode* FindMin(BstNode* root)
{
	while(root->left != NULL) root = root->left;
	return root;
}


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

BstNode* Delete(BstNode* root, int data) {
	if(root == NULL) { return root; }
	else if(data < root->data){ root->left = Delete(root->left,data); }
	else if (data > root->data) { root->right = Delete(root->right,data); }
	else{
		// data found, handle deletion
		
		// Case 1: No child
		if(root->left == NULL && root->right == NULL){
			delete root;
			root = NULL;		// don't leave danling pointer
		}
		// Case 2: One Child
		else if(root->left == NULL){
			BstNode* temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right == NULL){
			BstNode* temp = root;
			root = root->left;
			delete temp;
		}
		// Case 3: 2 Children
		else{
			// find min value in right subtree
			BstNode* temp = FindMin(root->right);
			// set current root data equal to minimum value in right subtree
			root->data = temp->data;
			// now that tree is updated, delete duplicate number from right-subtree
			root->right = Delete(root->right,temp->data);
		}
		return root;
	}
}


//Function to print nodes
void Inorder(BstNode *root) {
	if(root == NULL) return;
 
	Inorder(root->left);       				//Visit left subtree
	std::cout << root->data << std::endl;  //Print data
	Inorder(root->right);     			   // Visit right subtree
}


void levelOrder(BstNode *root) {
	std::cout << "Printing tree by level (breadth first)" << std::endl;
	if(root == NULL) return;
	
	std::queue<BstNode*> Q;
	Q.push(root);
	
	while(!Q.empty()){
		BstNode* current = Q.front();
		std::cout << current->data << std::endl;
		if(current->left != NULL) Q.push(current->left);
		if(current->right != NULL) Q.push(current->right);
		Q.pop();	// remove front element from queue
	}	
	std::cout << "\n";
}


int main() {
	
		/*Code To Test the logic
	  Creating an example tree
	            5
			   / \
			  3   10
			 / \   \
			1   4   11
    */
    
    
	BstNode* root = NULL;	// Creating an empty tree
	root = Insert(root,5);		// collecting pointer returned from 'insert' function and updating root
	root = Insert(root,10);
	root = Insert(root,3); 
	root = Insert(root,4); 
	root = Insert(root,1);
	root = Insert(root,11);

	levelOrder(root);


	//Print Nodes before deletion
	std::cout<<"Tree before deletion: \n";
	Inorder(root);
	std::cout<<"\n";


	// Deleting node with value 5, change this value to test other cases
	root = Delete(root,5);

	//Print tree
	std::cout<<"Tree after deletion: \n";
	Inorder(root);
	std::cout<<"\n";
	
	int number;
	std::cout << "Enter a number to be searched\n";
	std::cin >> number;
	if(Search(root,number)==true) std::cout<< "Found\n";
	else std::cout << "Not found\n";
	

	
	
}
