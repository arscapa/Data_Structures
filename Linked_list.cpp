#include <iostream>

// Linked list of integers

struct Node 
	{
		int value;
		Node* next;
	};
	
void append(int val, Node* ptr)
// Add item to end of list
	{
		// Create new node to add to list
		Node* item = new Node;
		(*item).value = val;
		(*item).next = NULL;
		
		// Traverse through list until reach last item
		Node* lastItem = ptr;
		while(lastItem->next != NULL){
			lastItem = lastItem->next;
		}
		
		// Link new node to current last item in list
		(*lastItem).next = item; 
	};
	
	
void prepend(int val, Node* & ptr)
// Add item to beginning of list
	{
		// Create new node to add to list
		Node* item = new Node;
		item->value = val;
		item->next = ptr;
		
		// Update list ptr so it now points to newly created node as this is now the first item
		ptr = item;

	};
	
void printList(Node* ptr)
	{
		std::cout << (*ptr).value << std::endl;
		if (ptr->next != NULL){
			printList(ptr->next);
		}
	};



int main()
{
	Node* listPtr = NULL;
	Node* root = new Node;
	
	(*root).value = 2;			// could also set values by root->value = 2; 
	(*root).next = NULL;		// could also set values by root->next = NULL;
	
	listPtr = root;				// set ptr equal to address of first node
	
	append(6,listPtr);
	append(8,listPtr);
	prepend(9,listPtr);
	
	printList(listPtr);
	
	return 0;
}
