#include<iostream>
#include "adjacency_list.h"

using namespace std;

AdjacencyList::AdjacencyList(int vertex_number) {
	this->adj_list.resize(vertex_number);
	this->predecessor.resize(vertex_number,-1);
	this->has_covered.resize(vertex_number, false);
}

void AdjacencyList::add_directed_edge(int from, int to) {
	adj_list[from].emplace_back(to);
}

void AdjacencyList::add_undirected_edge(int vertex1, int vertex2) {
	adj_list[vertex1].emplace_back(vertex2);
	adj_list[vertex2].emplace_back(vertex1);
}



void AdjacencyList::print_path(int vertex) {
	while (vertex != -1) {
		cout << vertex ;

		vertex = this->predecessor[vertex];
		if (vertex != -1) {
			cout << " <-- ";
		}
	}
	cout << endl;
}