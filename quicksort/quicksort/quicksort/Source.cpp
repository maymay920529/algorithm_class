#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


template<class T>
int partition(vector<T>* A, int p, int r) {
	int last = (* A)[r - 1];

	int j = p - 1;
	for (int i = p; i < r - 1; ++i) {
		if ((*A)[i] < last) {
			++j;
			swap((*A)[i], (*A)[j]);
		}
	}

	++j;
	swap((*A)[j], (*A)[r - 1]);

	return j;
}

template<class T>
void quicksort(vector<T>* A, int p, int r) {
	if (p >= r) return;
	else {
		int mid=partition(A, p, r);
		quicksort(A, p, mid);
		quicksort(A, mid + 1, r);
	}
}

template<class T>
void print(vector<T> A) {
	for (auto i : A) {
		cout << i << " ";
	}
	cout << endl;
}


int main() {
	vector<int> arr = { 10,20,30,1,60,2,30,50,25,100 };
	quicksort(&arr, 0, arr.size());
	print(arr);

	return 0;
}