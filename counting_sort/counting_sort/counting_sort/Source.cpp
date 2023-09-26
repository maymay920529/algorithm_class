#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> counting_sort(vector<int> A, int n, int k) {
	vector<int> B(n);
	vector<int> C(k, 0);

	for (auto it : A) ++C[it];

	--C[0];
	for (int i = 1; i < k; ++i) C[i] += C[i - 1];

	for (int i = n - 1; i >= 0; --i) {
		C[A[i]];
		B[C[A[i]]] = A[i];
		C[A[i]] -= 1;
	}

	return B;
}

template<class T>
void print(vector<T> const A) {
	for (auto i : A) {
		cout << i << " ";
	}
	cout << endl;
}
int main() {
	vector<int> A = { 1,5,2,6,9,3,7,8,4,10,1,2,5,2,2,5,10,9,2,8,7,3,2,1,0,0,4,3 };
	vector<int> B(A.size());

	int max = *max_element(A.begin(), A.end());

	B = counting_sort(A, A.size(), max+1);

	print(B);
}