#include<iostream>
#include<vector>
#include "disjoint_set_forest.hpp"
using namespace std;

int main() {
	// textbook exercise 19.3-1



	DisjointSet<int> dist_set;

	vector<DisjointSet<int>::Node* > node_table(17);

	for (int i = 1; i <=16 ; ++i) {
		node_table[i] = dist_set.make_set(i);
	}

	for (int i = 1; i <=15; i += 2) {
		dist_set.union_set(node_table[i], node_table[i + 1]);
	}

	for (int i = 1; i <= 13; i += 4) {
		dist_set.union_set(node_table[i], node_table[i + 2]);
	}

	dist_set.union_set(node_table[1], node_table[5]);

	dist_set.union_set(node_table[11], node_table[13]);

	dist_set.union_set(node_table[1], node_table[10]);

	cout << dist_set.find_set(node_table[2])->data << endl;

	cout << dist_set.find_set(node_table[9])->data << endl;

	return 0;
}