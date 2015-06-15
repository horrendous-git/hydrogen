#include "certificate.hh"
#include "block.hh"

#include <iostream>

using namespace std;

Certificate::Certificate()
{
	
}

void Certificate::refine(Partition *A) {
	// B = A -- by copy
	Partition* B = A.copy();
	// S = B -- by copy
	Partition* S = B.copy();
	//U = vertex list, a vector whose elements are 0...n
	int n = graph->num_vertices;
	Vertices* V = new Vertices(n);
	int N = B->size();

	Partition* T;
	int j;
	while(N > 0) {
		--N;
		T = S->at(N);
		if (T->is_proper_subset(U)) {
			U->remove(T);
			j = 0;
			while(j < B->size() && B->size() < n) {
				if (B->size() != 1)
					split_update(B, S, U, j, N);
			}
		}
	}
	
}

void Certificate::split_update(Partition *B, Partition *S, Partition *U, int &j, int &N)
{
	// initialize L
	L = new Partition(graph->num_vertices);
	Block1 *block = B->at(j);
	int h;
	cout << "su: updating L ..." << endl;
	for(const auto& u : block->elements) {
		cout << "u: " << u;
		// h = | T n N_G(u)|
		h = T->intersect(graph, u);
		cout << " h: " << h;
		// L[h] << u
		L->at(h)->add_element(u);
		cout << endl;
	}

	// find #non-empty partitions
	int m=0;
	for(auto block: L->blocks) {
		if(block->size() > 0)
			++m;
	}
	cout << "#non-empty blocks: " << m << endl;
	// if there is one non-empty block, dont have to do anything
	if (m<=1)
		return;

	// shift B by (m-1) to make some space in positions (j+1)..(|B|-1)
	B->shift(j,m-1);

	int k = 0;
	// for(int h=0; h<L->size(); h++) {
	for(auto block : L->blocks) {
		if(block->size() == 0)
			continue;

		B->assign(j+k,  block);
		S->at(N+k) = L->at(h);
		U.append(h);
		k++;
	}
	B->print();
	j = j+m-1;
	N = N+m;
	delete(L);
}

void Certificate::add_graph(Graph *g)
{
	graph = g;
}

Certificate::~Certificate()
{
}
