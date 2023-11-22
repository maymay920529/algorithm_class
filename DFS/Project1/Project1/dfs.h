#pragma once
#include<iostream>
#include<vector>
#include "adjacency_list.h"

using namespace std;

class DFS :public AdjacencyList
{
private:
	int time = 0;
	vector<int> discover_time;
	vector<int> finish_time;

	void dfs_visit(int vertex);

public:
	DFS(int vertex_number);

	void calculate();

	void print_discover_finish_time(int vertex);

};