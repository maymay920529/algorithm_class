#pragma once
#include<iostream>
#include<vector>

using namespace std;

class AdjacencyList 
{
protected:
	vector<vector<int> > adj_list;
	vector<int> predecessor;
	vector<bool> has_covered;

	AdjacencyList(int vertex_number);

public:
	void add_directed_edge(int from, int to);
	void add_undirected_edge(int vertex1, int vertex2);

	void print_path(int vertex);
};