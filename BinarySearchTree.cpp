//Binary Search Tree: Normal Tree where each parent node can only have at max 2 child nodes.
//The left child node must be LESS THAN OR EQUAL to the value of the parent.
//The right child node must be GREATER to the value of the parent.
//Operations include:
//1) Inserting a value into the BST.
//2) Search if a value is present in the BST.
//3) Finding the MAX value in the BST.
//4) Finding the MIN value in the BST.
//5) Finding the Height of the BST.
//6) Breadth Order Traversal and printing of the BST.
//7) Depth Order Traversal and printing of the BST.

#define NOMINMAX
#define max(a,b)            (((a) > (b)) ? (a) : (b))
#include <iostream>

using namespace std;


struct Node {
	int value;
	Node* left;
	Node* right;
};

class BinarySearchTree {
private:
	
public:
	Node* root = NULL;		//Always keeping address of root node

	void Insert(Node* r, int x) {
		Node* temp = new Node();			//Creating new node.
		temp->value = x;
		temp->left = NULL;
		temp->right = NULL;

		if (root == NULL) {					//If tree is empty set the new node as the root node.
			root = temp;
		}

		//IF THE VALUE IS LESS THAN OR EQUAL
		else if (x <= r->value) {			//If the new node value is LESS THAN OR EQUAL to the root node
			if (r->left == NULL) {			//AND there are no nodes under the root on the left, connect the new node as the left child of the root.
				r->left = temp;
			}
			else {							//If there are nodes below the root node, Run insert again with the left child of root becoming the new root.
				Insert(r->left,x);
			}
		}

		//IF THE VALUE IS GREATER THAN
		else if (x > r->value) {				//If the new node value is GREATER THAN to the root node
			if (r->right == NULL) {				//AND there are no nodes under the root on the right, connect the new node as the right child of the root.
				r->right = temp;
			}
			else {
				Insert(r->right, x);			//If there are nodes below the root node, Run insert again with the right child of root becoming the new root.
			}
		}
	}

	bool Search(Node* r, int x) {
		if (root == NULL) return false;			//If tree is empty then return false
		if (r->value == x) return true;			//If the root value is x then return true

		else if (x <= r->value) {				//If the value is less than or equal to the root value
			if (r->left == NULL) {				//AND there are no nodes under the root on the left,'x' can't possibly be in the tree. Return false 
				return false;
			}
			else {							//If there are nodes below the root node, Run insert again with the left child of root becoming the new root.
				Search(r->left, x);
			}
		}

		else if (x > r->value) {				//If the value is less than or equal to the root value
			if (r->right == NULL) {				//AND there are no nodes under the root on the right, 'x' can't possibly be in the tree. Return false 
				return false;
			}
			else {							//If there are nodes below the root node, Run search again with the right child of root becoming the new root.
				Search(r->right, x);
			}
		}
	}

	int Max(Node* r) {
		int x;
		if (r == NULL) {											//If root is null the BST is empty.
			cout << "There are no values in the tree \n";
			return -1;
		}
		else {														
			x = r->value;											//First we store the value of the current node.
			if (r->right == NULL) {									//If this is the furthest right node, return its value
				return x;
			}
			else {													//If the current node has a right child node, start the process over at the child node. 
				Max(r->right);
			}
		}
	}

	int Min(Node* r) {
		int x;
		if (r == NULL) {											//If root is null the BST is empty.
			cout << "There are no values in the tree. \n";
			return -1;
		}
		else {
			x = r->value;											//First we store the value of the current node.
			if (r->left == NULL) {									//If this is the furthest left node, return its value
				return x;
			}
			else {													//If the current node has a left child node, start the process over at the child node. 
				Min(r->left);
			}
		}
	}

	int Height(Node* r) {
		if (r == NULL) {
			return -1;
		}
		else {
			return ( max(Height(r->left), Height(r->right)) + 1);
		}
	}

};

int main() {
	BinarySearchTree s1;
	s1.Insert(s1.root, 5);
	s1.Insert(s1.root, 10);
	s1.Insert(s1.root, 15);
	s1.Insert(s1.root, 2);
	s1.Insert(s1.root, 3);
	s1.Insert(s1.root, 4);

	cout << "Values inserted into the BST: 2, 3, 4, 5, 10, 15. \n \n";
	cout << "The root value of the BST is: " << s1.root->value << "\n";
	cout << "Checking if a value is present in the Binary Search Tree. 1 = Present/0 = Not Present. \n \n";
	cout << "Checking if 5 is in the BST: " <<s1.Search(s1.root, 5) <<"\n";
	cout << "Checking if 6 is in the BST: " << s1.Search(s1.root, 6) << "\n";
	cout << "Checking if 10 is in the BST: " << s1.Search(s1.root, 10) << "\n";
	cout << "The maximum value in the BST is: " << s1.Max(s1.root) << "\n";
	cout << "The minimum value in the BST is: " << s1.Min(s1.root) << "\n";
	cout << "The height of the the BST is: " << s1.Height(s1.root) << "\n";
}
