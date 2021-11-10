//DOUBLY LINKED LISTS

#include<iostream>

using namespace std;

struct Node {
	int value;
	Node* prev;
	Node* next;
};


class doublyLinkedList {
private:
	Node* head = NULL;
public:
	//Functions 
	void create(int x) {
		Node* temp = new Node();		//Creates a new node.
		temp->value = x;				//Sets value to x.
		temp->next = NULL;				//Sets previous node to NULL since it will be the only node.
		temp->prev = NULL;				//Sets next node to NULL since it will be the only node.
		head = temp;						//Sets head to point to the new node.
	}

	void printList() {
		Node* temp = head;
		while (temp != NULL) {
			cout << temp->value << " ";
			temp = temp->next;
		}
		cout << "\n";
	}

	void insertAtHead(int x) {
		Node* temp = new Node();					//Creates new node.
		temp->value = x;							//Sets the node value.
		temp->next = head;							//Connects the new node the original head node.
		temp->prev = NULL;							//Since the new node will be the first node in the DLL its 'prev' points to NULL.
		head->prev = temp;							//Connects the original head node to the new node. 
		head = temp;								//Connects head pointer to the new node. 
	}

	void insertAtTail(int x) {
		Node* temp = new Node();
		temp->value = x;
		temp->next = NULL;						//Since the new node will be last its 'next' points to NULL.
		Node* temp1 = head;						//temp node to traverse DLL.
		while (temp1->next != NULL) {
			temp1 = temp1->next;				//Traverses DLL until 'temp1' points to the last node.
		}
		temp1->next = temp;						//Connects the original last node to the new node.
		temp->prev = temp1;						//Connects new node to the original last node. 
	}

	void reservePrint() {
		Node* temp = head;
		while (temp->next != NULL) {			//Traverses until 'temp' points to the last node. 
			temp = temp->next;
		}
		while (temp != NULL) {					//Reverse traversal until 'temp' reaches the head node. Prints the value of each node as it traverses. 
			cout << temp->value << " ";
			temp = temp->prev;
		}
		cout << "\n";
	}


};




int main() {
	doublyLinkedList n;
	n.create(5);
	n.printList();
	n.insertAtHead(2);
	n.printList();
	n.insertAtTail(7);
	n.printList();
	n.reservePrint();
}
