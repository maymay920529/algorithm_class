#pragma once
#include<iostream>
using namespace std;

class MPS {
public:
	void read_file(const char* input_file_name);
	void write_file_and_print(const char* output_file_name);
	void compute_mps();

private:
	int num_chord;
	
	int* chord_point = NULL;
	int* mis = NULL;
	int* mis_chord_case = NULL;
	inline void mis_case(int lower, int upper);
	void recursive_ans(bool* ans, int lower, int upper);
};