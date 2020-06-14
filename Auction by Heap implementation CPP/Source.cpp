
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
using namespace std;

class Node {
public:
 
	char* _name;   // the name of the bidder
	int _key;      // the auction bid
	int _index;

	Node() : _name(nullptr), _key(0), _index(-1) {}

	Node(int index, const char* name) : _name(NULL), _key(0), _index(index) {
		_key = rand() % 50 + 1; // the auction bid is selected at random. 
		_name = strdup(name);
	}

	void SetIndex(int index) { _index = index; }
	int GetIndex() { return _index; }

	~Node() {};

};

class Heap{
public:
	

	Node** _bids = nullptr; // the array that the heap made of
	Node* _root = nullptr;  // the first Node of the heap
	int _size;

	//return  the first Node the the highst bid
	Node* GetHighestBid() { return _root; } 

	// swap two Nodes inside the heap
	void SwapNodes(Node* a, Node* b) {
		int ia = a->GetIndex();  
		int ib = b->GetIndex(); 
		swap(*a, *b);
		b->SetIndex(ib);
		a->SetIndex(ia);
	}

	//Insert the Bid to the Heap
	void Insert(int index, const char* name){
		_bids[_size] = new Node(_size, name);
		if (_size >= 1)
			HeapifyUp(_bids[_size], _size);

		_size++;
	}	

	// heapify is a function that we run on a node
	// when we know it does not perform the heap feature
	void Heapify(Node* i, int size){
		
		Node *largest = i; //i is the parent
		Node *l = _bids[(i->_index * 2) + 1];  // left son 2i (here it wil be 2*index + 1)
		Node *r = _bids[(i->_index * 2) + 2];  // right son 2i+1 (here it wil be 2*index + 2)

		/// If left child is larger than root
		if ((i->_index * 2) + 1 < size && l->_key > largest->_key){
				largest = l;
		}

		// If right child is larger than largest so far
		if ((i->_index * 2) + 2 < size-1 && r->_key > largest->_key) {
				largest = r;
		}

		//if largest is not the father
		if (largest != i){
			SwapNodes(i, largest);
			Heapify(largest, size-1); // Recursively heapify the affected sub-tree
		}
	}

	// Function to heapify ith node in a Heap 
    // of size n following a Bottom-up approach 
	void HeapifyUp(Node* i, int size) {
		int indexOfParent = (i->_index - 1) / 2;

		// If current node is greater than its parent 
	    // Swap both of them and call heapify again 
	    // for the parent 
		if (i->_key > _bids[indexOfParent]->_key) {
			SwapNodes(i, _bids[indexOfParent]);
			HeapifyUp(_bids[indexOfParent], size); // Recursively heapify the the parent Node
		}
	}

	// return the Node with the k size'd bid
	Node* ReturnKSizeBid(int k, int size){
		_root = _bids[0];
		if (k == 1)
			return _root;
		SwapNodes(_bids[0], _bids[size - 1]);
		Heapify(_bids[0], size);
		_root = ReturnKSizeBid(k - 1, size - 1);
	}

	//print the heap
	void printHeap(){
		for (int i = 0; i < _size; ++i)
			cout << "inedx: "<< _bids[i]->_index + 1 << endl << "name: " 
			<< _bids[i]->_name << endl << "bid: " << _bids[i]->_key 
			<< ": " << endl << endl << endl;

		// k selected randomly 
		int k = (rand() % _size) + 1;
		cout << "the chosen k is: " << k << endl;

		// find and print the k size'd bid
		Node* a = ReturnKSizeBid(k, _size);
		cout << "the k bid is: " << a->_key << endl;
		cout << "---------------------------------" << endl << endl;
	}

	Heap() : _root(nullptr), _bids(nullptr), _size(0) {
		_bids = new Node*[10];	
	}

	Heap(int k) : _root(nullptr), _bids(nullptr), _size(0) {
		_bids = new Node*[k];
	}

	Node* kthLargest(int Heap* h, int size, int k)
	{
		Heap* kHeap= new Heap(k);
		int i;
		for (i = 0; i < k; i++)
			minHeap[i] = a[i];
		buildMinHeap(minHeap, k);
		for (i = k; i < size; i++)
		{
			if (a[i] > minHeap[0])
			{
				minHeap[0] = a[i];
				minHeapify(minHeap, k, 0);
			}
		}
		return minHeap[0];
	}


	~Heap() {}
	};

void Auction() {
	// building the heap and creat a new bid tracking system
	Heap* auction = new Heap();

	// insert all the bidders 
	auction->Insert(0, "Aviv");
	auction->Insert(1, "Ofir");
	auction->Insert(2, "Yarden");
	auction->Insert(3, "Yossi");
	auction->Insert(4, "Ori");
	auction->Insert(5, "Michal");
	auction->Insert(6, "Shmuel");
	auction->Insert(7, "Tzahi");
	auction->Insert(8, "Luda");
	auction->Insert(9, "Tamar");

	auction->printHeap();
}

void main() {
	// print 50 auctions 
	for (int i = 0; i < 50; i++)
	{
		cout << "------- Aucttion number " << i + 1
			<< " -------" << endl << endl;
		Auction();
	}
}