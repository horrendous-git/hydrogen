
#include "partition.hh"

#include <iostream>

using namespace std;

Partition::Partition()
{
}

Partition::Partition(int size)
{
	Block1 *block;
	// blocks.resize(size);
	for(int ix=0; ix<size; ix++) {
		block = new Block1();
		blocks.push_back(block);
	}
}

Block1* Partition::at(int j)
{
	return blocks.at(j);
}
void Partition::set(int j, Block1 *block)
{
}

void Partition::add_block(vector<int> _block)
{
	Block1 *block = new Block1(_block);
	blocks.push_back(block);
}

int Partition::num_blocks()
{
	return blocks.size();
}
int Partition::size()
{
	return blocks.size();
}
void Partition::increase(int m)
{
	blocks.resize(size()+m);
}

Partition::~Partition()
{
	for(int ix=0; ix<blocks.size(); ix++) {
		//cout << "d-p: " << ix << endl;
		delete(blocks.at(ix));
	}
}

void Partition::shift(int j, int m)
{
	int sz_b_original = size();
	increase(m);
	cout << "sz: " << sz_b_original << " j: " << j << endl;
	for(int ix=sz_b_original-1; ix>=j+1; ix--) {
		blocks.at(m+ix) = blocks.at(ix);
		cout << blocks.at(ix)->size() << " "
			 << blocks.at(ix+m)->size() << endl;
	}
}

void Partition::print()
{
	cout << "partition[" << size() << "] - [ ";
	for(auto it=blocks.begin(); it != blocks.end(); it++) {
		(*it)->print();
		cout << " ";
	}
	cout << "]" << endl;
}

bool Partition::valid(int j)
{
	return (at(j)->size() > 0);
}

void Partition::assign(int j, Block1 *block)
{
	blocks.at(j) = new Block1();
	blocks.at(j)->assign_by_copy(block);
}
