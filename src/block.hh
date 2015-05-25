#ifndef __BLOCK_HH
#define __BLOCK_HH

#include <vector>

#include "graph.hh"

// todo: use namespace

class Block1 {
public:
	Block1();
	Block1(vector<int> _elements);
	vector<int> elements;
	void add_element(int element);
	int size();
	int intersect(Graph* g, int vertex);
	// const_iterator begin();
	// const_iterator end();
	void print();
	void assign_by_copy(Block1* block);
};

#endif
