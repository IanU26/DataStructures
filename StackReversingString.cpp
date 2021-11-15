#include <iostream>

using namespace std;

struct Node {
	char data;
	Node* link;
};

class Stack {
private:
	Node* top1 = NULL;			
public:
	void push(char x) {
		Node* temp = new Node();	
		temp->data = x;				
		temp->link = top1;			
		top1 = temp;				
	}
	void pop() {
		if (top1 == NULL) {
			cout << "No value to pop \n";
		}
		else {
			Node* temp = top1;
			temp = temp->link;			
			top1 = temp;				
		}
	}
	void top() {
		if (top1 == NULL) {
			cout << "Stack is empty. \n";
		}
		else {
			cout << top1->data;
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
	string s = "Hello World";
	
	int n = s.length();
	Stack s1;
	
	for (int i = 0; i < n; i++) {
		s1.push(s[i]);
	}
	
	cout << "Original string: " << s << "\n";
	cout << "Reversed string: ";
	for (int i = 0; i < n ; i++) {
		s1.top();
		s1.pop();
	}
