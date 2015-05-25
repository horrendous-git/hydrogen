#include "certificate.hh"
#include "block.hh"

#include <iostream>

using namespace std;

Certificate::Certificate()
{
	
}

Partition* Certificate::split_update(Partition *B, int j,
							   Block1 *T)
{
	// initialize L
	L = new Partition(graph->num_vertices);
	Block1 *block = B->at(j);
	int h, u;
	for(auto it=block->elements.begin();
		it != block->elements.end(); ++it) {
		u = *it;
		cout << "u: " << u;
		// h = | T ^ N_G(u)|
		h = T->intersect(graph,u);
		cout << " h: " << h;
		// L[h] << u
		L->at(h)->add_element(u);
		cout << endl;
	}

	// find #non-empty partitions
	int m=0, size_block;
	for(int ix=0;ix<L->size();ix++) {
		size_block = L->at(ix)->size();
		if(size_block>0)
			++m;
	}
	cout << "non-empty blocks: " << m << endl;
	if (m<=1)
		return L;

	// shift B by (m-1)
	B->shift(j,m-1);

	int k =0;
	for(int h=0; h<L->size(); h++) {
		size_block = L->at(h)->size();
		if(size_block == 0)
			continue;

		B->assign(j+k,  L->at(h));
		//S->at(N+k) = L->at(h);
		//U << L->at(h);
		k++;
	}
	B->print();
	// j = j+m-1;
	// N = N+m;
	return L;
}

void Certificate::add_graph(Graph *g)
{
	graph = g;
}

Certificate::~Certificate()
{
	// check if L is valid
	delete(L);
}
