#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>
using namespace std;

int _random_partition(vector<int> & A, int p, int r) {
	int pivot = rand() % (r-p) + p;
	swap(A[pivot], A[r - 1]);

	int last = A[r - 1];

	int j = p - 1;
	for (int i = p; i < r - 1; ++i) {
		if (A[i] < last) {
			++j;
			swap(A[i], A[j]);
		}
	}

	++j;
	swap(A[j], A[r - 1]);

	return j;
}


int random_select_recursive(vector<int> &A,int p,int r,int i_th_small) {
	srand(time(NULL));

	if (p == r - 1) return A[p];

	int q = _random_partition(A, p, r);

	int k = q - p;

	if (i_th_small-1 == k)return A[q];
	else if (i_th_small-1 < k) return random_select_recursive(A, p, q , i_th_small);
	else return random_select_recursive(A, q + 1, r, i_th_small-k-1);
}


int random_select_iterative(vector<int>& A, int p, int r, int i_th_small) {
	srand(time(NULL));

	while (p != r - 1) {
		int q = _random_partition(A, p, r);
		
		if (q == i_th_small - 1) return A[q];
		else if (q > i_th_small - 1) r = q;
		else p = q+1;
	}

	return A[p];
}

int main() {
	//                   3  4  6 1  9 2  7  8  5  10
	vector<int> arr = { 10,20,30,1,60,2,30,50,25,100 };
	int i_th_small = 5;

	int num1 =random_select_recursive(arr, 0, arr.size(),i_th_small);
	cout << num1 << endl;


	int num2 = random_select_iterative(arr, 0, arr.size(), i_th_small);
	cout << num2 << endl;

	return 0;

}