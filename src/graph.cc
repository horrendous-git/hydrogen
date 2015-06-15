#include "graph.hh"

#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

Graph::Graph(int _num_vertices) {
	num_vertices = _num_vertices;
}

Graph::Graph(string filename)
{
	ifstream file(filename.c_str());
	string line;
	// read number of vertices
	getline(file, line);
	set_num_vertices(line);
	cout << "num: " << num_vertices << endl;
	// todo: move this to separate method
	init_matrix(num_vertices);
	int ix_row = 0;
	int vertex;
	while(getline(file, line)) {
		istringstream iss(line);
		// cout << line << endl;
		while((iss >> vertex)) {
			//cout << vertex << endl;
			mat(ix_row, vertex) = 1;
		}
		ix_row++;
	}
	// todo: end
	// cout << mat << endl;
}
void Graph::set_num_vertices(string line)
{
	istringstream iss(line);
	iss >> num_vertices;
}

// returns the adj matrix value at (row, col)
int Graph::at(int row, int col)
{
	return mat(row, col);
}

void Graph::read_adj_list(ifstream file)
{
	
}

void Graph::init_matrix(int num_vertices)
{
	mat.resize(num_vertices, num_vertices);
	for (int ix = 0; ix < num_vertices; ix++)
		for (int iy = 0; iy < num_vertices; iy++)
			mat(ix, iy) = 0;
}



Graph::~Graph() {
}
