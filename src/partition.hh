#ifndef __PARTITION_HH
#define __PARTITION_HH

#include <vector>

#include "block.hh"

using namespace std;

class Partition {
public:
	Partition();
	Partition(int size);
	~Partition();
	vector<Block1*> blocks;
	void add_block(vector<int> block);
	int num_blocks();
	int size();
	void increase(int m);
	Block1* at(int j);
	void set(int j, Block1* block);
	void shift(int j, int m);
	void print();
	bool valid(int j);
	void assign(int j, Block1* block);
	// private
	
};

#endif


