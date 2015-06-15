#include "block.hh"

#include <iostream>
using namespace std;

Block1::Block1()
{
}

Block1::Block1(vector<int> _elements)
{
	elements = _elements;
}

int Block1::size()
{
	return elements.size();
}

void Block1::add_element(int element)
{
	elements.push_back(element);
}

int Block1::intersect(Graph* graph, int vertex)
{
	int intersections = 0;
	int n = graph->num_vertices;
	for(auto element_block=elements.begin(); element_block != elements.end(); element_block++)
	// for(const auto& element_block : elements)
	{
		for(int ix=0; ix<n; ix++) {
			if((graph->at(vertex,ix)!=0) && // if ix is adjacent to
											// vertex, N_G(vertex)
			   (ix == *element_block))
				intersections++;
		}
	}
	return intersections;
}

void Block1::print()
{
	cout << "{ ";
	for(auto it=elements.begin(); it != elements.end(); it++) {
		cout << *it << " ";
	}
	cout << "}";
}

void Block1::assign_by_copy(Block1 *block)
{
	//elements.erase(elements.begin());
	// elements.assign(block->elements.begin(),
	// 				block->elements.end());
	int sz_new = block->elements.size();
	elements.resize(sz_new);
	for(int ix=0; ix<sz_new; ix++) {
		elements.at(ix) =
			block->elements.at(ix);
	}
}
