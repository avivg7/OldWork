
#include<iostream>
#include<list>
using namespace std;

class Node {
public:
	list<Node*> m_outLst;
	string m_courseName;
	int m_d_in;

	Node(string name) : m_courseName(name), m_d_in(0), m_outLst(NULL) {}

	//print the vertex's members
	void Print() {
		cout << "Course name: " << m_courseName << endl
			<< "d[" << m_courseName << "] = " << m_d_in << endl << endl;
	}

	//decrease each vertex's from the out list by 1
	void DecreaseByOne() {
		auto it = m_outLst.begin();
		while (it != m_outLst.end()) {
			(*it)->m_d_in -= 1;
			it++;
		}
	}

	~Node() {}
};

class Graph {
public:
	list<Node*> m_courses;
	Graph() {}

	//set the d[v] in degree for each vertex
	void InDegree() {
		auto it = m_courses.begin();
		while (it != m_courses.end()) {
			auto it1 = (*it)->m_outLst.begin();
			while (it1 != (*it)->m_outLst.end()) {
				(*it1)->m_d_in += 1;
				it1++;
			}
			it++;
		}
	}

	//print a full graph
	void PrintGraph() {
		auto it = m_courses.begin();
		while (it != m_courses.end()) {
			(*it)->Print();
			it++;
		}
	}

	//sort the print the courses by topological sort
	void TopologicalSort() {
		//set the d[v] in degree for each vertex
		this->InDegree();
		
		//print the graph after the degree
		cout << "This is the graph after we set d[v] on degree for each vertex:" << endl << endl;
		this->PrintGraph();

		cout << endl << endl << "The graph after Topological Sort:" << endl << endl;

		Node* tmp;
		auto it = m_courses.begin();
		while (m_courses.empty() == false)
		{		
			if ((*it)->m_d_in == 0) {
				(*it)->Print();
				(*it)->DecreaseByOne();
				tmp = (*it);
			}

			it++;
			m_courses.remove(tmp);

			if (it == m_courses.end() && (m_courses.size() > 1) &&( !(m_courses.empty()))) {
				it = m_courses.begin();
			}
		}
	}

	~Graph() {}
};

int main() {
	Node* bdida1 = new Node("bdida1");
	Node* bdida2 = new Node("bdida2");
	Node* algo1 = new Node("algo1");
	Node* algo2 = new Node("algo2");
	Node* mivneiNetunim = new Node("mivneiNetunim");
	Node* mavoLemahshevim = new Node("mavoLemahshevim");
	Node* modelimHishuvim = new Node("modelimHishuvim");
	Node* hishuviut = new Node("hishuviut");

	bdida1->m_outLst.push_front(bdida2);
	bdida2->m_outLst.push_front(algo2);
	algo2->m_outLst.push_front(hishuviut);
	algo1->m_outLst.push_front(modelimHishuvim);
	algo1->m_outLst.push_front(algo2);
	mivneiNetunim->m_outLst.push_front(algo1);
	mavoLemahshevim->m_outLst.push_front(mivneiNetunim);
	modelimHishuvim->m_outLst.push_front(hishuviut);

	Graph* g = new Graph();
	g->m_courses.push_back(bdida1);
	g->m_courses.push_back(bdida2);
	g->m_courses.push_back(algo1);
	g->m_courses.push_back(algo2);
	g->m_courses.push_back(mivneiNetunim);
	g->m_courses.push_back(mavoLemahshevim);
	g->m_courses.push_back(modelimHishuvim);
	g->m_courses.push_back(hishuviut);

	g->TopologicalSort();

	return 0;
}

