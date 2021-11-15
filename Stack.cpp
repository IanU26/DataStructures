//Stack data structure with linked list. 
//Here the stack has a couple of operations.
//1) 'push(x)' adds an integer x on the top of the stack. 
//2) 'pop()' deletes the top integer on the stack. 
//3) 'top()' prints the top integer on the stack.
//4) 'isEmpty() returns true if the stack is empty and returns false in other cases. 

#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* link;
};

class Stack {
private:
	Node* top1 = NULL;			//'top1' is the same as 'head' in a linked list. We call it 'top1' beacuse it represents the top of the stack now. 
public:
	//Push inserts a node at the beginning of the list. This has a time complexity of O(1).
	void push(int x) {
		Node* temp = new Node();	//Pointer to the new Node as well as creating the new node. The pointer can affect the node.
		temp->data = x;				//Setting the value of the new node to 'x'
		temp->link = top1;			//Since it is the only Node its link will point to NULL
		top1 = temp;				//Here the head pointer is set to equal the temp pointer (which points to the Node we just created).
	}
	void pop() {
		if (top1 == NULL) {
			cout << "No value to pop \n";
		}
		else {
			Node* temp = top1;
			temp = temp->link;			//'temp' now points to the second node.
			top1 = temp;				//'head' is set to point to the second node, effectively deleating the first node. 
		}
	}
	void top() {
		if (top1 == NULL) {
			cout << "Stack is empty. \n";
		}
		else {
			cout << top1->data << "\n";
		}
	}
	bool isEmpty() {
		if (top1 == NULL) {
			return true;
		}
		else {
			return false;
		}
	}
};


int main() {
	Stack s1;
	s1.top();		//Checking if top works when stack is empty.
	s1.push(5);		//Pushing 5 on the stack.
	s1.top();
	s1.push(10);	//Pushing 10 on the stack. 
	s1.top();
	s1.pop();		//Popping the 10 off the stack 
	s1.top();	
	cout << s1.isEmpty() << "\n"; //Checking if 'isEmpty' returns the correct value when stack is not empty. 
}
