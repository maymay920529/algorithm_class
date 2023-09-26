#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void max_heapify(vector<int>* A,int i,int size) {
	int left = 2 * i+1;
	int right = 2 * i + 2;

	int largest = i;
	if (left < size && (*A)[largest] < (*A)[left])largest = left;
	if (right < size && (*A)[largest] < (*A)[right])largest = right;

	if (largest != i) {
		swap((*A)[i],(*A)[largest]);
		max_heapify(A, largest,size);
	}

}

void build_max_heap(vector<int>* A, int size) {
	for (int i = size/2 -1; i >= 0; i--) {
		max_heapify(A, i, size);
	}
}

void heap_sort(vector<int>* A) {
	build_max_heap(A,A->size());

	for (int i = A->size() - 1; i > 0; i--) {
 		swap((*A)[0], (*A)[i]);
		max_heapify(A, 0,i);
	}
	
}

void print(vector<int> A) {
	for (auto i : A) {
		cout << i << " ";
	}
	cout << endl;
}

int main() {
	vector<int> arr = { 10,30,5,10,40 };
	heap_sort(&arr);
	print(arr);


	return 0;
}