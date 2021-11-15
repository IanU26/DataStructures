//Linked Lists and Node data structure. 


//Here I perform a couple of tasks related to linked lists.
//1) Creating a linked list
//2) Adding a Node to an empty linked list
//3) Adding a Node to the end of a linked list
//4) Adding a Node at the beginning of a linked list
//5) Adding a Node at the nth position of a linked list
//6)Reversing a linked list 
//7)Printing a linked list

#include <iostream>

using namespace std;

//Declaring what a node is. Nodes consist of two members: data and link. 
//Data will be the value at each node and link will be a pointer to the following node.

struct Node{
	int data;
	Node* link;
}; 

//Our Linked List will be a class with several member functions. 
class linkedList {
private:
	Node* head = NULL;
public: 
	void printList() {
		Node* temp = head;
		while (temp != NULL) {
			cout << temp->data << "\n";
			temp = temp->link;
		}
		cout << "\n";
	}

	void insertAtBeginning(int x) {
		Node* temp = new Node();	//Pointer to the new Node as well as creating the new node. The pointer can affect the node.
		temp->data = x;				//Setting the value of the new node to 'x'
		temp->link = NULL;			//Since it is the only Node its link will point to NULL
		head = temp;					//Here the head pointer is set to equal the temp pointer (which points to the Node we just created).
	}

	void insertAtEnd(int x) {
		Node* temp = new Node();			//Create new Node
		temp->data = x;						//Set its value to x
		temp->link = NULL;					//Set its link to NULL
		Node* temp1 = head;					//Pointer used to traverse linked list
		while (temp1->link != NULL) {		//Traversal until we reach the last node (who's link will be NULL)
			temp1 = temp1->link;
		}
		temp1->link = temp;					//Connect the last node to the new node
	}

	void insertAtNthNode(int x, int n) {
		Node* temp = new Node();			//Creating a new node
		temp->data = x;						//Setting the value to x	
		Node* temp1 = head;					//Pointer used to traverse linked list
		int i = 1;
		while (i != (n - 1)) {				//Traversing the linked list until we reach the (n-1) location
			temp1 = temp1->link;
		}
		Node* temp2 = temp;					//Copying 'temp' so that we can modify 'temp' but still use 'temp' to modify 'temp1'
		temp->link = temp1->link;			//Connect the new node with the (n+1) node
		temp1->link = temp2;				//Connecting the (n-1) node to the new node
	}

	void removeNthNode(int n) {
		Node* temp1 = head;
		Node* temp2 = head;
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

	void reverse() {
		Node* prev = NULL;
		Node* current = head;
		Node* next;

		while (current != NULL) {
			next = current->link;
			current->link = prev;
			prev = current;
			current = next;
		}
		head = prev;
	}
};

int main() {
	linkedList firstList;				//Creating an object of class linkedList
	linkedList secondList;				//Creating a second object of class linkedList

	firstList.insertAtBeginning(2);		//Inserting 2 at the beginning of list 1
	firstList.printList();		
	secondList.insertAtBeginning(1);	//Inserting 1 at the beginning of list 2. 
	secondList.printList();
	firstList.insertAtEnd(3);			//Inserting 3 at the end of list 1
	firstList.printList();
	firstList.insertAtNthNode(6, 2);		//Inserting 6 as the 2nd node of list 1 
	firstList.printList();
	firstList.removeNthNode(2);			//Removing the 2nd node of list 1
	firstList.printList();

	firstList.insertAtEnd(4);		//Inserting 4 at the end of list 1 
	firstList.insertAtEnd(7);		//Inserting 7 at the end of list 1 
	firstList.printList();

	firstList.reverse();				//Reversing list 1 
	firstList.printList();

}
