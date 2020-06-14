

#include <iostream>
#include <queue>
#include <string>

using namespace std;

class Edge;
class Node;

class Edge {
public:
	int m_weight; //cost of the edge
	Node* m_from;
	Node* m_to;

	Edge(int weight, Node* from, Node* to) : m_weight(weight), m_from(from), m_to(to) {};
	~Edge() {};

};

//comperator to create a min heap of edges
struct CompareWeight {
	bool operator()(Edge* e1, Edge* e2) {
		return (e1->m_weight > e2->m_weight);
	}
};

class Node {
public:

	string m_name;
	string m_Pi; //father of the node
	int m_d; //the path
	priority_queue<Edge*, vector<Edge*>, CompareWeight> Q; // the neghibers (min heap)
	int m_h; // heuristic function (BFS from E)
	int m_AstarScore; //the cost of A star

	Node(string name, int h) :m_d(1000), m_name(name), m_h(h), m_AstarScore(0) {};
	~Node() {};
};

//comperator to create a min heap of nodes
struct CompareNode {
	bool operator()(Node* n1, Node* n2) {
		return (n1->m_d > n2->m_d);
	}
};

struct CompareNodeByHu {
	bool operator()(Node* n1, Node* n2) {
		return (n1->m_AstarScore > n2->m_AstarScore);
	}
};


class Graph {
public:

	priority_queue<Node*, vector<Node*>, CompareNode> N; // the nodes in the graph (min heap)

	void Print() {
		while (!this->N.empty()) {
			cout << "Vertex name: " << this->N.top()->m_name << endl;
			cout << "Distance from s: " << this->N.top()->m_d << endl;
			cout << "Pi: " << this->N.top()->m_Pi << endl << endl;
			this->N.pop();
		}
	}

	void PrintStar() {
		priority_queue<Node*, vector<Node*>, CompareNode> N1;
		N1 = N;

		while (!N1.empty()) {
			cout << "Vertex Name: " << N1.top()->m_name << endl;
			cout << "Distance From s: " << N1.top()->m_d << endl;
			cout << "Heuristic (BFS from E): " << N1.top()->m_h << endl;
			cout << "A Star Cost: " << N1.top()->m_AstarScore << endl;
			cout << "Pi: " << N1.top()->m_Pi << endl << endl;
			N1.pop();
		}

		priority_queue<Node*, vector<Node*>, CompareNodeByHu> N2;

		while (!N.empty()) {
			N2.push(N.top());
			N.pop();
		}
		cout << "The shortest path from S to E by A star algorithm is: " << endl << endl;
		cout << N2.top()->m_name;
		string tmp = N2.top()->m_name;
		while (tmp != "E") {
			if (N2.top()->m_Pi == tmp) {
				cout << "-->" << N2.top()->m_name;
				tmp = N2.top()->m_name;
			}
			N2.pop();
		}
	}

	Graph() {};
	~Graph() {};
};

//relax for Dijxtra
void Relax(Node* from, Node* to, Edge* e) {
	if (to->m_d > (from->m_d + e->m_weight)) {
		to->m_d = (from->m_d + e->m_weight);
		to->m_Pi = from->m_name;
	}
}

//relax for A star
void RelaxStar(Node* from, Node* to, Edge* e) {
	if (to->m_d > (from->m_d + e->m_weight)) {
		to->m_d = (from->m_d + e->m_weight);
		to->m_AstarScore = to->m_h + to->m_d;
		to->m_Pi = from->m_name;
	}
}

//A star show the sortest path to E by following the smallest score of A star
void Astar(Graph* g, Node* s) {
	priority_queue<Node*, vector<Node*>, CompareNode> V;
	V = g->N;

	while (!V.empty()) {
		while (!V.top()->Q.empty()) {
			RelaxStar(V.top(), V.top()->Q.top()->m_to, V.top()->Q.top());
			V.top()->Q.pop();
		}
		V.pop();
	}
}

//Dijastra show the smallest path to S
void Dijkstra(Graph* g, Node* s) {
	priority_queue<Node*, vector<Node*>, CompareNode> V;
	V = g->N;

	while (!V.empty()) {
		while (!V.top()->Q.empty()) {
			Relax(V.top(), V.top()->Q.top()->m_to, V.top()->Q.top());
			V.top()->Q.pop();
		}
		V.pop();
	}
}

int main() {
	//Nodes
	Node* s = new Node("S", 10);
	s->m_d = 0;
	Node* a = new Node("A", 5);
	Node* b = new Node("B", 20);
	Node* c = new Node("C", 10);
	Node* d = new Node("D", 15);
	Node* f = new Node("F", 5);
	Node* e = new Node("E", 0);
	Node* h = new Node("H", 10);

	Edge* s_a = new Edge(33, s, a);
	Edge* a_e = new Edge(11, a, e);
	Edge* f_e = new Edge(25, f, e);
	Edge* f_a = new Edge(3, f, a);
	Edge* s_c = new Edge(10, s, c);
	Edge* c_f = new Edge(9, c, f);
	Edge* c_h = new Edge(13, c, h);
	Edge* h_f = new Edge(6, h, f);
	Edge* s_b = new Edge(8, s, b);
	Edge* c_d = new Edge(6, c, d);
	Edge* d_h = new Edge(5, d, h);
	Edge* b_d = new Edge(12, b, d);

	//Node S
	s->Q.push(s_a);
	s->Q.push(s_b);
	s->Q.push(s_c);

	//Node B
	b->Q.push(b_d);

	//Node C
	c->Q.push(c_f);
	c->Q.push(c_h);
	c->Q.push(c_d);

	//Node D
	d->Q.push(d_h);

	//Node H
	h->Q.push(h_f);

	//Node F
	f->Q.push(f_e);
	f->Q.push(f_a);

	//Node A
	a->Q.push(a_e);

	Graph* g = new Graph();
	g->N.push(s);
	g->N.push(b);
	g->N.push(c);
	g->N.push(d);
	g->N.push(e);
	g->N.push(f);
	g->N.push(h);
	g->N.push(a);

	//Dijkstra(g, s);
	//g->Print();

	Astar(g, s);
	g->PrintStar();

	return 0;
}

