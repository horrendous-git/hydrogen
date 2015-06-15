#include "certificate.hh"
#include "block.hh"

#include <iostream>

using namespace std;

Certificate::Certificate()
{
	
}

Partition* Certificate::split_update(Partition *B, int j, Block1 *T)
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
		return L;

	// shift B by (m-1) to make some space in positions (j+1)..(|B|-1)
	B->shift(j,m-1);

	int k = 0;
	// for(int h=0; h<L->size(); h++) {
	for(auto block : L->blocks) {
		if(block->size() == 0)
			continue;

		B->assign(j+k,  block);
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
