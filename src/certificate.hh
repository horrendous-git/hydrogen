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
	void split_update(Partition *B,
					  Partition *S,
					  Partition *U,
					  int& j,
					  int& N);
	void refine(Partition* A);
	// private:
	Partition *L;
};

#endif
