#include <iostream>

struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
};

struct Node* head;			// global variable - pointer to head node

struct Node* GetNewNode(int x) {
	struct Node* temp = new struct Node;
	
	temp->data = x;
	temp->prev = NULL;
	temp->next = NULL;
	return temp; 
}

void InsertAtHead(int x){
	struct Node* temp = GetNewNode(x);
	if(head == NULL) {
		head = temp;
		return;
	}
	head->prev = temp;
	temp->next = head;
	head = temp;
}

void Print() {
	struct Node* temp = head;
	std::cout << "Forward: ";
	while(temp != NULL){
		std::cout << temp->data << " " ;
		temp = temp->next;
	}
	std::cout << "\n";
}

void ReversePrint(){
	struct Node* temp = head;
	if(temp == NULL) return;		// empty list, exit
	// Going to last Node
	while(temp->next != NULL){
		temp = temp->next;
	}
	// Traverse backwards using prev pointer
	std::cout << "Reverse: ";
	while(temp != NULL) {
		std::cout << temp->data << " ";
		temp = temp->prev;
	}
	std::cout << "\n";
}

void InsertAtTail(int x){
		struct Node* newNode = GetNewNode(x);
		if(head == NULL) {
			head = newNode;
			return;
		}
		// Traverse to last item in list
		struct Node* temp = head;
		while(temp->next != NULL){
			temp = temp->next;
		}
		
		newNode->prev = temp;
		temp->next = newNode;
};

int main()
{
	head = NULL; // empty list
	InsertAtHead(2); Print(); ReversePrint();
	InsertAtHead(4); Print(); ReversePrint();
	InsertAtHead(6); Print(); ReversePrint();
	InsertAtTail(8); Print(); ReversePrint();
}
