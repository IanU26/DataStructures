//Array Implementation of Queue.
//Operations for Queue are
//1)EnQueue(x): Adds x to the rear of the queue.
//2)DeQueue(): Removes the front object from the queue and returns its value.
//3)Peek(): Prints the front object in the queue. Doesnt remove it!
//4)IsEmpty(): Returns true if the queue is empty.
//5)IsFull(): Returns true if the queue has reached its memory limit (size of array).

#include<iostream>

using namespace std;

class Queue {

private:
	int a[20];
	int front = -1;
	int rear = -1;

public:
	void EnQueue(int x) {
		if (IsFull()) {
			cout << "Queue is full \n";
		}
		else if (IsEmpty()) {
			rear = 0;
			front = 0;
			a[rear] = x;
		}
		else {
			rear += 1;
			a[rear] = x;
		}
	}
	int DeQueue() {
		int x = front;
		front += 1;
		return a[x];
	}
	void Peek() {
		cout << a[front] << "\n";
	}
	bool IsEmpty() {
		if (front == -1 && rear == -1) return true;
		else return false;
	}
	bool IsFull() {
		int n = size(a);
		if (rear == (n - 1)) return true;
		else return false;
	}
};



int main() {
	Queue s;
	s.EnQueue(5);			//Adding 5 at the front of queue
	s.Peek();
	s.EnQueue(10);			//Adding 10 to end of queue.
	s.Peek();				//We are still peeking the front of the queue. This output remains 5 because we havent DeQueue.
	cout << s.DeQueue() <<"\n";	//DeQueue the 5 off the front of list. 5 Is still the output.
	s.Peek();					//Now 10 is the front of the queue so peeking now should return 10. 

}
