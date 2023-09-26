#include<iostream>
#include<vector>
#include "priority_queue.h"
using namespace std;

void extract_and_print(priority_queue &A) {
	pair<int, int> element = A.extract_max();
	cout << element.first << " " << element.second << endl;
}
int main() {
	// pair<int,int> a={key,value};

	vector < pair<int, int> > arr = { {10,20} ,{30,20} ,{5,25} ,{10,60} ,{40,70} };
	priority_queue pq(arr);
	cout << pq.increase_key(20, 100) << endl; //first argument: value, second augument: key
	extract_and_print(pq);
	extract_and_print(pq);
	cout << pq.decrease_key(60, 2) << endl;  //first argument: value, second augument: key
	extract_and_print(pq);
	extract_and_print(pq);
	extract_and_print(pq);

}

