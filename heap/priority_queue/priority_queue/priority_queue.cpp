#include<iostream>
#include<vector>
#include<algorithm>
#include "priority_queue.h"
using namespace std;

priority_queue::priority_queue(vector< pair<int, int> > A) {
	this->A = A;
	build_max_heap(this->A.size());
}

void priority_queue::max_heapify(int i, int size) {
	int left = 2 * i+1;
	int right = 2 * i + 2;

	int largest = i;
	if (left < size && A[largest].first < A[left].first)largest = left;
	if (right < size && A[largest].first < A[right].first)largest = right;

	if (largest != i) {
		swap(A[i], A[largest]);
		max_heapify( largest, size);
	}

}

void priority_queue::build_max_heap(int size) {
	for (int i = size / 2 - 1; i >= 0; i--) {
		max_heapify( i, size);
	}
}


int priority_queue::increase_key(int x,int k) {
	int i = 0;
	while (i < A.size() && x != A[i].second) ++i;
	if (i == A.size())return -1;

	A[i].first = k;
	while (i > 0 && A[(i - 1) / 2].first < A[i].first) {
		swap(A[(i - 1) / 2], A[i]);
		i = (i - 1) / 2;
	}
	return 0;
}

void priority_queue::insert(int x, int k) {
	pair<int, int> val(k, x);
	A.push_back(val);
	int i = A.size() - 1;
	while (i > 0 && A[(i - 1) / 2].first < A[i].first) {
		swap(A[(i - 1) / 2], A[i]);
		i = (i - 1) / 2;
	}
}

 pair<int,int> priority_queue::maximum() {
	 return A[0];
}

 pair<int, int> priority_queue::extract_max() {
	 pair<int, int> ans = A[0];
	 A[0] = A[A.size() - 1];
	 A.pop_back();
	 max_heapify(0, A.size());
	 return ans;
}

