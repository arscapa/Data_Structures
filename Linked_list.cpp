#include <iostream>
#include <assert.h>

// Linked list of integers
struct Node 
	{
		int value;
		Node* next;
	};
	
void append(int val, Node* & ptr)
// Add item to end of list
	{
		// Create new node to add to list
		Node* item = new Node;
		(*item).value = val;
		(*item).next = NULL;
		
		if(ptr != NULL) 
		{
			// Traverse through list until reach last item
			Node* lastItem = ptr;
			while(lastItem->next != NULL){
				lastItem = lastItem->next;
			}
			// Link new node to current last item in list
			(*lastItem).next = item;
		}
		else
		{
			ptr = item;
		}
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
	
	
void insert(int val, Node* & ptr, int pos)
// Adds item to list at given position
	{
		assert(pos>0);
		
		// Check if location to insert is first in list
		if(pos==1 || ptr==NULL){prepend(val,ptr);} else{	
		
			// Create new node to add to list
			Node* item = new Node;
			item->value = val;
			item->next = NULL;
			
			// If not, traverse through list until reach given item
			int counter = 1;
			Node* currentItem = ptr;
			// Check haven't reached position yet or end of list
			while(counter != pos-1 && currentItem->next != NULL) 
			{
				currentItem = currentItem->next; 
				counter++;
			};
			item->next = currentItem->next;
			currentItem->next = item;	
		};
	};
	
void deleteItem(int pos, Node* & ptr)
// Delete a node from list at given position
{
	assert(pos>0);
	
	Node* currentItem = ptr;
	if(pos==1){
	ptr = currentItem->next;
	delete currentItem;
	return;
	}
	for(int i=1; i<pos-1; i++)
	{
		currentItem = currentItem->next;
	};
	Node* nextItem = currentItem->next;
	currentItem->next = nextItem->next;
	delete nextItem;
	
}
	
	
void printList(const Node* ptr, int itemNum = 1)
	{
		assert(ptr!=NULL);
		std::cout << "List Item #" << itemNum << ": " << (*ptr).value << std::endl;
		if (ptr->next != NULL){
			printList(ptr->next,++itemNum);
		}
	};



int main()
{
	Node* listPtr = NULL;
	
	append(6,listPtr);
	append(8,listPtr);
	prepend(9,listPtr);
	printList(listPtr);
	std::cout << '\n';
	
	insert(5,listPtr,3);
	printList(listPtr);
	std::cout << '\n';
		
	deleteItem(2,listPtr);
	printList(listPtr);
	
	return 0;
}
