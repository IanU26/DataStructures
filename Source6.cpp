//DOUBLY LINKED LISTS

#include<iostream>

using namespace std;

struct Node {
	int value;
	Node* prev;
	Node* next;
};

//Function Declarations
void create(Node*& h, int x);		//Creates the first node in DLL.
void printList(Node* h);			//Prints the DLL associated with a head node.
void insertAtHead(Node*& h, int x);	//Inserts a node at the beginning of a DLL.
void insertAtTail(Node*& h, int x);	//Inserts a node at the end of a DLL.
void reservePrint(Node* h);			//Prints DLL in reverse order.



int main() {
	Node* head;
	head = NULL;
	create(head,5);
	printList(head);
	insertAtHead(head, 2);
	printList(head);
	insertAtTail(head, 7);
	printList(head);
	reservePrint(head);
}

//Functions 
void create(Node*& h,int x) {
	Node* temp = new Node();		//Creates a new node.
	temp->value = x;				//Sets value to x.
	temp->next = NULL;				//Sets previous node to NULL since it will be the only node.
	temp->prev = NULL;				//Sets next node to NULL since it will be the only node.
	h = temp;						//Sets head to point to the new node.
}

void printList(Node* h) {
	Node* temp = h;					
	while (temp != NULL) {
		cout << temp->value <<" ";
		temp = temp->next;
	}
	cout << "\n";
}

void insertAtHead(Node*& h, int x) {
	Node* temp = new Node();				//Creates new node.
	temp->value = x;						//Sets the node value.
	temp->next = h;							//Connects the new node the original head node.
	temp->prev = NULL;						//Since the new node will be the first node in the DLL its 'prev' points to NULL.
	h->prev = temp;							//Connects the original head node to the new node. 
	h = temp;								//Connects head pointer to the new node. 
}

void insertAtTail(Node*& h, int x) {
	Node* temp = new Node();				
	temp->value = x;
	temp->next = NULL;						//Since the new node will be last its 'next' points to NULL.
	Node* temp1 = h;						//temp node to traverse DLL.
	while (temp1->next != NULL) {
		temp1 = temp1->next;				//Traverses DLL until 'temp1' points to the last node.
	}
	temp1->next = temp;						//Connects the original last node to the new node.
	temp->prev = temp1;						//Connects new node to the original last node. 
}

void reservePrint(Node* h) {
	Node* temp = h;
	while (temp->next != NULL) {			//Traverses until 'temp' points to the last node. 
		temp = temp->next;
	}
	while (temp != NULL) {					//Reverse traversal until 'temp' reaches the head node. Prints the value of each node as it traverses. 
		cout << temp->value << " ";
		temp = temp->prev;
	}
	cout << "\n";
}