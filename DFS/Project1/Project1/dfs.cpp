#include<iostream>
#include "adjacency_list.h"
#include "dfs.h"

using namespace std;




DFS::DFS(int vertex_number) :AdjacencyList(vertex_number) {
	
	this->discover_time.resize(vertex_number);
	this->finish_time.resize(vertex_number);
}



void DFS::calculate() {
	this->time = 0;
	fill(this->has_covered.begin(), this->has_covered.end(), false);

	for (int vertex = 0 ; vertex < adj_list.size() ; ++vertex) {
		if (!this->has_covered[vertex]) {
			dfs_visit(vertex);
		}
	}
}

void DFS::dfs_visit(int vertex) {
	++this->time;
	this->has_covered[vertex] = true;

	this->discover_time[vertex] = time;

	for (auto adj_vertex : adj_list[vertex]) {
		if (!this->has_covered[adj_vertex]) {
			dfs_visit(adj_vertex);
			
		}
	}

	++this->time;
	this->finish_time[vertex] = time;

	
}

void DFS::print_discover_finish_time(int vertex) {
	cout << "discover time: " << this->discover_time[vertex] << "\t,  finish time: " << this->finish_time[vertex] << endl;
}