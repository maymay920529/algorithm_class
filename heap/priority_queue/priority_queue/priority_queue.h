#pragma once
#include<vector>
#include<iostream>
using namespace std;

class priority_queue {
public:
	priority_queue(vector< pair<int,int> > A);
	void insert(int x, int k);
	pair<int,int> maximum();
	pair<int,int> extract_max();
	int increase_key(int x, int k);

private:
	vector< pair<int, int> > A;
	void build_max_heap(int size);
	void max_heapify(int i, int size);
};
