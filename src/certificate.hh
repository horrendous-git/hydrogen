#ifndef __CERTIFICATE_HH
#define __CERTIFICATE_HH

#include "graph.hh"
#include "partition.hh"

class Certificate {
public:
	Graph *graph;
	Certificate();
	~Certificate();
	void add_graph(Graph *g);
	void generate_certificate();
	// todo: make this private
	Partition* split_update(Partition *B,
					  int j,
					  Block1 *T);
	// private:
	Partition *L;
};

#endif
