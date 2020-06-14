#include <iostream>
#include <fstream>
#include <typeinfo>
#include <sstream>

using namespace std;

template<class Key>
class BinaryTree {
public:

	class Node {
	public:
	
		Node* _left;
		Node* _right;
		Key _key;

		Node() : _left(nullptr), _right(nullptr) {}

		~Node() {
			delete _left;
			delete _right;
		}


	};

	//data members:
	//_root - the first Node in the tree
	//_size - _number of nodes in the tree
	Node* _root;
	int _size;

	BinaryTree() : _root(nullptr), _size(0) {
		_root = new Node();
	}

	~BinaryTree() {
		delete _root;
	}

	//insert a new Node to the tree
	void Insert(Key k) {
		//if the new Node is the first and onli Node in the tree
		if (_size == 0) {
			_root->_key = k;
		}
		else {
			Node* n = _root;
			//if the key is smaller than the root ot will go to the left som
			//if the key is greater than the root ot will go to the right som
			while (n->_left != NULL && n->_right != NULL) {
				while (k < n->_key && n->_left != NULL) {
					n = n->_left;
				}

				while (k > n->_key && n->_right != NULL) {
					n = n->_right;
				}
			}

			Node* t = new Node();
			t->_key = k;
			if (k < n->_key)
				n->_left = t;

			if (k > n->_key)
				n->_right = t;
		}
		_size++;
	}

	//this methoed will delete a full sub tree
	void DeleteSubTree(Key k) {
		Node* n = _root;
		Node* prev;
		while (n != NULL && n->_key != k) {
			prev = n;
			if (k < n->_key) {
				n->_left;
			}
			else {
				if (k > n->_key)
					n->_right;
			}
		}

		if (n != NULL && k == n->_key) {
			if (prev->_left == n) {
				n->_left = NULL;
			}
			else {
				prev->_right = NULL;
			}
			delete n;
		}
	}

	//will apply function object on all the tree todes
	template<class Func>
	void forEach(Func f) {
		apply(f, _root);
	}

	//will recursevly apply the function object on a full sub tree
	template<class Func>
	void apply(Func f, Node* n) {
		if (n != NULL) {
			f(n->_key);
			apply(f, n->_left);
			apply(f, n->_right);
		}
	}

	void PrintTree() {
		cout << "         This is how the tree look like : " << endl << endl;
		cout << "                    " << this->_root->_key << "                    " << endl << endl;
		cout << "               " << this->_root->_left->_key << "         " << this->_root->_right->_key << endl << endl;
		cout << "             " << this->_root->_left->_left->_key << "   " << this->_root->_left->_right->_key << "      ";
		cout << this->_root->_right->_left->_key << "   " << this->_root->_right->_right->_key << endl << endl;
	}
};

//struct for the function object
struct INC {
	template<class Num>
	void operator()(Num& num) {
		++num;
	}
};

int main() {

	BinaryTree<int> *tree = new BinaryTree<int>;
	int arr[] = { 5,3,8,1,4,6,9 };

	//insert arr inide the tree
	for (int i = 0; i < 7; i++)
		tree->Insert(arr[i]); 

	//print the tree
	tree->PrintTree();

	//giving the tree function object of ++ to every node in the tree
	tree->forEach(INC());

	//print the tree
	tree->PrintTree();

	return 0;
}


