#include<iostream>
#include<vector>
#include "priority_queue.h"
using namespace std;

int main() {
	vector < pair<int, int> > arr = { pair<int,int>(10,20),pair<int,int>(30,20) ,pair<int,int>(5,25) ,pair<int,int>(10,60) ,pair<int,int>(40,70) };
	priority_queue pq(arr);
	cout << pq.increase_key(20, 100) << endl;
	cout << pq.extract_max().first << " " << pq.maximum().second << endl;
	cout << pq.extract_max().first << " " << pq.maximum().second << endl;
	cout << pq.extract_max().first << " " << pq.maximum().second << endl;
	cout << pq.extract_max().first << " " << pq.maximum().second << endl;

}

