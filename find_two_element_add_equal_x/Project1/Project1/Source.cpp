#include<iostream>
#include<iterator>
#include<set>
using namespace std;

bool find_add(set<int> S,int x,int a,int b) {
	while (a < b) {
		set<int>::iterator a_value = next(S.begin(), a);
		set<int>::iterator b_value = next(S.begin(), b);

		if (*a_value + *b_value == x) {
			return true;
		}
		else if (*a_value + *b_value < x) {
			a++;
		}
		else {
			b--;
		}
	}

	return false;
}

int main() {
	set<int> S{ 1,2,3,5,8,10,15,18,20 };
	int x = 24;
	cout << find_add(S, x, 0, 8) << endl;
}