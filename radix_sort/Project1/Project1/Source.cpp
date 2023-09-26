#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

void _counting_sort(vector< pair<int, int> > in_A, vector< pair<int, int> >& out_A, int n, int k) {
	vector<int> C(k, 0);

	for (auto it : in_A) ++C[it.first];

	--C[0];
	for (int i = 1; i < k; ++i) C[i] += C[i - 1];

	for (int i = n - 1; i >= 0; --i) {
		out_A[C[in_A[i].first]] = in_A[i];
		C[in_A[i].first] -= 1;
	}

}


void radix_sort(vector<int>& arr, int n, int d, int radix = 10) {
	vector< pair<int, int> > A(n);
	vector< pair<int, int> > B(n);
	for (int i = 0; i < n; ++i) A[i] = make_pair(0, arr[i]);


	vector< pair<int, int> >* pA = &A;
	vector< pair<int, int> >* pB = &B;

	for (int i = 0; i < d; ++i) {
		for (auto& it : *pA) {
			it.first = it.second / int(pow(radix, i));
			it.first = it.first % 10;
		} 
		_counting_sort(*pA, *pB, n, radix);
		swap(pA, pB);
	}

	for (int i = 0; i < n; ++i) arr[i] = (*pA)[i].second;

}

template<class T>
void print(vector<T> const A) {
	for (auto i : A) {
		cout << i << " ";
	}
	cout << endl;
}

int main() {
	vector<int> arr = { 10,20,50,40,555,882,883,814,709,220,70,1,30,29,40,50,99,576,999,2,3,9,29 };
	radix_sort(arr, arr.size(), 3);
	print(arr);
}