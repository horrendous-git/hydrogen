


#include <iostream>
// #include <gsl/gsl_sf_bessel.h>

#include "graph.hh"

using namespace std;

int main() {
	cout << "hello world" << endl;

	// testing gsl
	// double x = 5.0;
	// double y = gsl_sf_bessel_J0(x);
	// cout << "x: " << x << " y: " << y << endl;

	Graph *g = new Graph("./graph1.txt");
	delete(g);
	
	return 0;
}
