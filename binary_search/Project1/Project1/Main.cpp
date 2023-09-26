#include<iostream>
using namespace std;

int Search(int* A, int v, int a, int b) {
	int mid = (a + b) / 2;
	if (A[mid] == v) {
		return mid;
	}
	else if (a >= b) {
		return -1;
	}
	else if (A[mid] > v) {
		return Search(A, v, a, mid - 1);
	}
	else {
		return Search(A, v, mid + 1, b);
	}
}

int main() {
	int arr[] = { 1,2,3,5,6,8,10,12,14,19 };
	int find = Search(arr, 50, 0, 9);
	cout << find << endl;
}