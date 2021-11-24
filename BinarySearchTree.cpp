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
//8) Checking if a binary tree is a BST in 2 ways: 1) Interval Method 2) Traversing tree Inorder and storing value.
//9) Deleting a node in the BST while preserving the properties of a BST.

#define NOMINMAX
#define max(a,b)            (((a) > (b)) ? (a) : (b))
#include <iostream>
#include<queue>

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
			return ( max(Height(r->left), Height(r->right) ) + 1);
		}
	}

	void LevelOrder(Node* r) {
		if (r == NULL) {
			cout << "There are no values in the tree. \n";
		}
		else {
			cout << "The tree current reads in the level order: ";
			queue<Node*> Q;												//C++ built in Q data structure 
			Q.push(r);													//Starting with pushing the root pointer to the queue
			while (!Q.empty()) {										//While the queue is not empty
				Node* current = Q.front();								//Set 'current' to be the pointer at the front of the queue
				if(current ->left != NULL) Q.push(current->left);		//Pushing the left child of 'current' into the queue
				if(current->right != NULL) Q.push(current->right);		//Pushing the right child of 'current' into the queue
				cout << current->value << " ";							//Printing the value of the front pointer in the queue
				Q.pop();												//Popping the current pointer, essentially moving to the next level in the tree. 
			}
		}
	}	

	void DLR(Node* r) {
		if (root == NULL) {
			cout << "There are no values in the tree. \n";
		}
		if (r == NULL) {
			return;
		}
		else {
			cout << r->value << " ";
			DLR(r->left);
			DLR(r->right);
		}
	}

	void LDR(Node* r) {
		if (root == NULL) {
			cout << "There are no values in the tree. \n";
		}
		if (r == NULL) {
			return;
		}
		else {
			LDR(r->left);
			cout << r->value << " ";
			LDR(r->right);
		}
	}

	void LRD(Node* r) {
		if (root == NULL) {
			cout << "There are no values in the tree. \n";
		}
		if (r == NULL) {
			return;
		}
		else {
			LRD(r->left);
			LRD(r->right);
			cout << r->value << " ";
		}
	}
	
	//This is a utility function for IsBST. This is done so we can start IsBST with INT_MAX and INT_MIN but can also still change min and max 
	//throughout the recursions.
	//This function traverses the tree and at every node compares the value of the node to the interval that it must be in to be a BST. 
	//The intervals are initially INT_MAX and INT_MIN but as the function is called recursively it is updated to be specific to each node. 
	bool IsBSTUtil(Node* r, int min, int max) {
		if (r == NULL) return true;
		if (r->value > min && r->value < max && IsBSTUtil(r->left, min, r->value) && IsBSTUtil(r->right, r->value, max)) {
			return true;
		}
		else {
			return false;
		}
	}

	//Here we use IsBSTUtil but set the initial max and min to INT_MAX and INT_MIN
	bool IsBST(Node* r) {
		return IsBSTUtil(r, INT_MIN, INT_MAX);
	}



	//Here we traverse the BT in LDR order. At each node instead of print the value, we store the value in a queue.
	void IsBST1Util(Node* r, queue<int>& Q) {
		if (root == NULL) {
			cout << "There are no values in the tree. \n";
		}
		if (r == NULL) {
			return;
		}
		else {
			DLR(r->left);
			Q.push(r->value);
			DLR(r->right);
		}
	}

	//We take the queue from IsBST1Util and compare each value in the queue and compare it to the last value. If it is a BST, 
	//each value will be larger than the last value. If this is fulfilled, then BT is a BST. 
	bool IsBST1(queue<int>& Q) {
		int min = INT_MIN;
		while (!Q.empty()) {
			int current = Q.front();
			if (current < min) {
				return false;
			}
			else {
				min = current;
				Q.pop();
			}
		}
		return true;
	}
	
	//Deleting a node while preserving the properties of a BST. We pass 'r' by reference so we can set it to NULL when needed (in case 3).
	void Delete(Node*& r, int x) {
		if (root == NULL) {
			cout << "There are no values in the tree. \n";
		}
		else if (r == NULL) {
			cout << "Value is not present in the tree. \n";
		}
		else if (x < r->value) {				//If the value is less than the node, Delete() again with the left child
			Delete(r->left, x);
		}
		else if (x > r->value) {				//If the value is greater than the node, Delete() again with the right child
			Delete(r->right, x);
		}

		//Here we found the node we want to delete. Now there are a couple cases. 
		// 1) The node is a leaf node and we can simply delete it. 
		// 2) The node only has one child node. In this case we can simply connect the node's parent to the node's child.
		// 3) The node has two children. In this case we find the minimum value in the node's right subtree. This value will replace the node's 
		//    value. 
		else if (r->value == x) {				
			if (r->left == NULL && r->right == NULL) {			//Case 1
				r = NULL;
			}
			else if (r->left == NULL) {							//Case 2
				r = r->right;
			}
			else if (r->right == NULL) {						//Case 2
				r = r->left;
			}
			else {												//Case 3
				int min = Min(r->right);						//Finding the minimum value in the subtree to the node.
				r->value = min;									//Replacing the node's value with the minimum value.
				Delete(r->right, min);							//Deleting the original minimum value node. This works because the minimum value node can't have a left child. 
			}
		}
	}
};

int main() {
	queue<int> Q;
	BinarySearchTree s1;
	s1.Insert(s1.root, 5);
	s1.Insert(s1.root, 10);
	s1.Insert(s1.root, 15);
	s1.Insert(s1.root, 2);
	s1.Insert(s1.root, 3);
	s1.Insert(s1.root, 4);

	cout << "Values inserted (in order) into the BST: 5, 10, 15, 2, 3, 4. \n \n";
	cout << "The root value of the BST is: " << s1.root->value << "\n";
	cout << "Checking if a value is present in the Binary Search Tree. 1 = Present/0 = Not Present. \n \n";
	cout << "Checking if 5 is in the BST: " <<s1.Search(s1.root, 5) <<"\n";
	cout << "Checking if 6 is in the BST: " << s1.Search(s1.root, 6) << "\n";
	cout << "Checking if 10 is in the BST: " << s1.Search(s1.root, 10) << "\n";
	cout << "The maximum value in the BST is: " << s1.Max(s1.root) << "\n";
	cout << "The minimum value in the BST is: " << s1.Min(s1.root) << "\n";
	cout << "The height of the the BST is: " << s1.Height(s1.root) << "\n";
	s1.LevelOrder(s1.root);
	cout << "The Preorder traversal is: "; s1.DLR(s1.root); cout << "\n";
	cout << "The Inorder traversal is: "; s1.LDR(s1.root); cout << "\n";
	cout << "The Postorder traversal is: "; s1.LRD(s1.root); cout << "\n";
	cout << "(Using Interval Solution)Checking if the BT is a BST(Should return 1 because it was created as a BST): " << s1.IsBST(s1.root) << "\n";
	s1.IsBST1Util(s1.root, Q);
	cout << "(Using LDR traversal)Checking if the BT is a BST(Should return 1 because it was created as a BST): " << s1.IsBST1(Q) << "\n";
	cout << "Now we use the delete function to delete the value 10 from the DST. \n"; s1.Delete(s1.root, 10);
	cout << "The Inorder traversal is: "; s1.LDR(s1.root); cout << "\n";
}
