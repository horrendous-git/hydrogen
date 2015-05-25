#include <iostream>
#include <vector>
#include <Eigen/Dense>
// #include <gsl/gsl_sf_bessel.h>

#include "graph.hh"
#include "certificate.hh"

using namespace std;
using namespace Eigen;

Partition* fill_b()
{
	Partition* B = new Partition();
	
	vector<int> v1;
	v1.push_back(0);
	B->add_block(v1);
	vector<int> v2;
	for(int ix=1;ix<=7;ix++)
		v2.push_back(ix);
	B->add_block(v2);
	return B;
}

int main() {
	cout << "hello world" << endl;

	Graph *g = new Graph("./graph1.txt");
	cout << g->num_vertices << endl;
	Certificate *cert = new Certificate();
	cert->add_graph(g);
	Partition *B;
	int j=1;
	// fill partition B
	B = fill_b();
	// cert->split_update(B, j, B->at(0));
	Partition *L = cert->split_update(B, j, B->at(0));

	// todo: uncommenting this will lead to seg fault
	// double free
	// coz L's values are assigned to B
	// FYI: there are two blocks in L which
	// will show up in valgrind
	//delete(L);
	delete(B);
	delete(cert);
	delete(g);
	
	return 0;
}
