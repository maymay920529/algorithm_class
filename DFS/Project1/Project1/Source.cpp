#include<iostream>
#include "dfs.h"

using namespace std;

int main() {
	//	textbook exercise 20.3-2
	// converting vertex q ~ z to 0 ~ 9 

	int vertex_number = 10;
	DFS dfs(vertex_number);

	dfs.add_directed_edge(0, 2);
	dfs.add_directed_edge(0, 3);
	dfs.add_directed_edge(0, 6);
	dfs.add_directed_edge(1, 4);
	dfs.add_directed_edge(1, 8);
	dfs.add_directed_edge(2, 5);
	dfs.add_directed_edge(3, 7);
	dfs.add_directed_edge(3, 8);
	dfs.add_directed_edge(4, 8);
	dfs.add_directed_edge(5, 6);
	dfs.add_directed_edge(6, 2);
	dfs.add_directed_edge(7, 9);
	dfs.add_directed_edge(8, 0);
	dfs.add_directed_edge(9, 7);


	dfs.calculate();

	for (int i = 0; i < vertex_number; ++i) {
		cout <<"vertex " << char(i + 'q') << " ";
		dfs.print_discover_finish_time(i);
	}


}