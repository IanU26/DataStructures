//Binary Tree

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

};

int main() {
	BinarySearchTree s1;
	s1.Insert(s1.root, 5);
	s1.Insert(s1.root, 10);
	cout << "The root value of the BST is: " << s1.root->value << "\n";
	cout << "Checking if a value is present in the Binary Search Tree. 1 = Present/0 = Not Present. \n";
	cout << "Checking if 5 is in the BST: " <<s1.Search(s1.root, 5) <<"\n";
	cout << "Checking if 6 is in the BST: " << s1.Search(s1.root, 6) << "\n";
	cout << "Checking if 10 is in the BST: " << s1.Search(s1.root, 10) << "\n";
	
}