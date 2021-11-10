//Linked List Practice.
//Here I perform a couple of tasks related to linked lists.
//1) Creating a linked list
//2) Adding a Node to an empty linked list
//3) Adding a Node to the end of a linked list
//4) Adding a Node at the beginning of a linked list
//5) Adding a Node at the nth position of a linked list

#include <iostream>

using namespace std;

//Declaring what a node is. Nodes consist of two members: data and link. 
//Data will be the value at each node and link will be a pointer to the following node.

struct Node{
	int data;
	Node* link;
};
//Head should be a global variable. 



void printList(Node* h);
void insertAtBeginning(Node*& h,int x);
void insertAtEnd(Node*& h, int x);
void insertAtNthNode(Node*& h, int x, int n);
void removeNthNode(Node*& h,int n);
void reverse(Node*& h);


int main() {
	Node* head;
	head = NULL;					//NULL pointer for the first linked list
	Node* head2;
	head2 = NULL;					//NULL pointer for the second linked list
	insertAtBeginning(head,2);		//Inserting 2 at the beginning
	printList(head);		
	insertAtBeginning(head2, 1);	//Inserting 1 at the beginning of the second linked list. 
	printList(head2);
	insertAtEnd(head,3);			//Inserting 3 at the end
	printList(head);	
	insertAtNthNode(head,6, 2);		//Inserting 6 as the 2nd node
	printList(head);
	removeNthNode(head,2);			//Removing the 2nd node
	printList(head);

	insertAtEnd(head,4);		//Inserting 4 at the end
	insertAtEnd(head,7);		//Inserting 7 at the end
	printList(head);

	reverse(head);				//Reversing the list
	printList(head);

}

void printList(Node* h) {
	Node* temp = h;
	while (temp != NULL) {
		cout << temp->data << "\n";
		temp = temp->link;
	}
	cout << "\n";
}

void insertAtBeginning(Node*& h, int x) {
	Node* temp = new Node();	//Pointer to the new Node as well as creating the new node. The pointer can affect the node.
	temp->data = x;				//Setting the value of the new node to 'x'
	temp->link = NULL;			//Since it is the only Node its link will point to NULL
	h = temp;					//Here the head pointer is set to equal the temp pointer (which points to the Node we just created).
}

void insertAtEnd(Node*& h,int x) {
	Node* temp = new Node();			//Create new Node
	temp->data = x;						//Set its value to x
	temp->link = NULL;					//Set its link to NULL
	Node* temp1 = h;					//Pointer used to traverse linked list
	while (temp1->link != NULL) {		//Traversal until we reach the last node (who's link will be NULL)
		temp1 = temp1->link;
	}
	temp1->link = temp;					//Connect the last node to the new node
}

void insertAtNthNode(Node*& h,int x, int n) {
	Node* temp = new Node();			//Creating a new node
	temp->data = x;						//Setting the value to x	
	Node* temp1 = h;					//Pointer used to traverse linked list
	int i = 1;
	while (i != (n - 1)) {				//Traversing the linked list until we reach the (n-1) location
		temp1 = temp1->link;
	}
	Node* temp2 = temp;					//Copying 'temp' so that we can modify 'temp' but still use 'temp' to modify 'temp1'
	temp->link = temp1->link;			//Connect the new node with the (n+1) node
	temp1->link = temp2;				//Connecting the (n-1) node to the new node
}

void removeNthNode(Node*& h,int n) {
	Node* temp1 = h;
	Node* temp2 = h;
	int i = 1;
	int l = 1;
	while (i != (n - 1)) {				//Traversing the list to get to the (n-1) location
		temp1 = temp1->link;
		i++;
	}
	while (l != (n)) {				//Traversing the linked list until we reach the n location
		temp2 = temp2->link;
		l++;
	}
	temp1->link = temp2->link;		//Connecting the n-1 node to the n+1 node. Essentially erasing the nth node. 
}

void reverse(Node*& h) {
	Node* prev = NULL;
	Node* current = h;
	Node* next;

	while (current != NULL) {
		next = current->link;
		current->link = prev;
		prev = current;
		current = next;
	}
	h = prev;
}

