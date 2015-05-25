#ifndef __GRAPH_HH
#define __GRAPH_HH

#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

class Graph {
public:
int num_vertices;
MatrixXf mat;

Graph(int _num_vertices);

// read from file
Graph(string filename);
~Graph();

// init the matrix with zeros
void init_matrix(int num_vertices);
int at(int row, int col);
private:
void set_num_vertices(string line);
void read_adj_list(ifstream file);
};

#endif
