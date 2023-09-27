#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
using namespace std;


void _insertion_sort(list<double>& A, int size) {
	list<double>::iterator now_node = ++A.begin();
	for (int i = 1; i < size; ++i) {
		double key = *now_node;
		list<double>::iterator pre_node = now_node;

		do {
			--pre_node;
		} while (pre_node != A.begin() && *pre_node>key);

		A.insert(++pre_node, key);

		now_node=A.erase(now_node);

	}
}


void bucket_sort(vector<double>& A, int size) {
	vector< list<double> > B(size);

	for (auto it : A) {
		int index = int(it * size);
		B[index].push_back(it);
	}

	for (int i = 1; i < size; i++) B[0].splice(B[0].end(), B[i]);

	copy(B[0].begin(), B[0].end(),A.begin());
}

template<class T>
void print(T A) {
	for (auto i : A) {
		cout << i << " ";
	}
	cout << endl;
}

int main() {

	vector<double> A = { 0.9,0.23,0.34,0.5632,0.66,0.77 };
	bucket_sort(A, A.size());
	print(A);
	return 0;
}