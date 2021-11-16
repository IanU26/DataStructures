//Array Implementation of Queue.
//Operations for Queue are
//1)EnQueue(x): Adds x to the rear of the queue.
//2)DeQueue(): Removes the front object from the queue and returns its value.
//3)Peek(): Prints the front object in the queue. Doesnt remove it!
//4)IsEmpty(): Returns true if the queue is empty.
//5)IsFull(): Returns true if the queue has reached its memory limit (size of array).

#include<iostream>

using namespace std;

struct Node {
	int value;
	Node* link;
};

class Queue {

private:
	Node* front = NULL;
	Node* rear = NULL;

public:
	void EnQueue(int x) {				//Adding to the queue occurs at the end of the list (opposite end of the front pointer).
		Node* temp = new Node();		//Create a new node
		temp->value = x;				//Set the new node value to x
		temp->link = NULL;				//Set the new node link to NULL because it will be at end of list
		if (front == NULL) {			//In the case of an empty linked list, set 'front' to point to the new node. If not empty, front isnt effected.
			front = temp;				
		}
		if (rear != NULL) {				//Connecting the original last node to the new node. If the list is empty this isn't possible, hence the if statement.
			rear->link = temp;
		}
		rear = temp;					//Finally set 'rear' to point to the new node. 
	}

	int DeQueue() {
		if (IsEmpty()) {			//If 'front' == NULL the list is empty, nothing to DeQueue.
			cout << "The queue is empty \n";
		}
		else {
			int x;						
			x = front->value;			//Store the value of 'front' node.
			front = front->link;		//Connect 'front' node to the second node in the list, effectively deleting the first node. 
			return x;					//Return the value of the original first node. 
		}
	}
	void peek() {
		if (IsEmpty()) {			//If 'front' == NULL the list is empty, nothing to DeQueue.
			cout << "The queue is empty \n";
		}
		else {
			cout << "\'" << front->value << "\' is at the front of the queue \n";
		}

	}
	bool IsEmpty() {			//If the 'front' node is NULL, the list is empty. 
		if (front == NULL) return true;
		else return false;
	}
};



int main() {
	Queue s;
	cout << s.IsEmpty() <<"\n";			//Should return true because queue is empty.
	s.EnQueue(5);						//Adding 5 into the queue.
	s.peek();							//Checking if 5 is at front of queue.
	s.EnQueue(10);						//Adding 10 into the queue.
	s.peek();							//Checking if 5 is still at front of queue.
	cout << s.DeQueue() << "\n";		//DeQueue 5 off the front of the queue.
	s.peek();							//Checking if 10 is now at the front of the queue.
	cout << s.IsEmpty() << "\n";		//Should return false because the queue is not empty.

}
