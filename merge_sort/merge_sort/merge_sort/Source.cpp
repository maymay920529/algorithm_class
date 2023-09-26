#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>* A, int p, int q, int r) {
	vector<int> left(q - p), right(r - q);
	copy(A->begin() + p, A->begin() + q, left.begin());
	copy(A->begin() + q, A->begin() + r, right.begin());

	int i = 0, j = 0;
	int k = p;
	while (i <left.size() && j <= right.size()) {
		if (left[i] <= right[j]) {
			(*A)[k] = left[i];
			k++;
			i++;
		}
		else {
			(*A)[k] = right[j];
			k++;
			j++;
		}
	}
	copy(left.begin() + i, left.end(), A->begin() + k);
	copy(right.begin() + j, right.end(), A->begin() + k);
}

void merge_sort(vector<int>* A, int p, int r) {
	if (p >= r-1) return;
	int mid = (p + r) / 2;

	merge_sort(A, p, mid);
	merge_sort(A, mid, r);
	merge(A, p, mid, r);
}

void print(vector<int> A) {
	for (auto i : A) {
		cout << i<<" ";
	}
	cout << endl;
}

int main() {
	vector<int> arr = { 10,20,30,1,60,2,30,50,25,100 };
	merge_sort(&arr, 0, arr.size() );
	print(arr);


	return 0;
}