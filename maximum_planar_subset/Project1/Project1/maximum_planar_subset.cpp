#include<iostream>
#include<fstream>
#include<algorithm>
#include "maximum_planar_subset.h"

using namespace std;


void MPS::read_file(const char* input_file_name) {
    fstream fin;
    fin.open(input_file_name, fstream::in);
    if (!fin.is_open())
    {
        cout << "Error: the input file is not opened!!" << endl;
        exit(1);
    }


    char buffer[100];

    fin >> buffer;
    this->num_chord = atoi(buffer);

    this->chord_point = new int[this->num_chord];
    this->mis = new int[this->num_chord * this->num_chord];
    this->mis_chord_case = new int[this->num_chord*this->num_chord];


    
    for (int i = 0; i < num_chord / 2; ++i)
    {
        fin >> buffer;
        int point1 = atoi(buffer);
        fin >> buffer;
        int point2 = atoi(buffer);

        this->chord_point[point1] = point2;
        this->chord_point[point2] = point1;

        this->mis_chord_case[point1 * this->num_chord + point2] = 0;
        this->mis_chord_case[point2 * this->num_chord + point1] = 0;
    }

    cout << "reading successfully! Getting " << this->num_chord << " chords" << endl;
}

inline void MPS::mis_case(int lower, int upper) {
    int mid = this->chord_point[upper];

    if (lower == upper) {
        this->mis[lower * this->num_chord + upper] = 0;
    }

    else if (mid > upper || mid < lower) {
        this->mis[lower * this->num_chord + upper] = this->mis[lower * this->num_chord + upper - 1];
        this->mis_chord_case[lower * this->num_chord + upper] = 1;
    }

    else if (mid<upper && mid>lower) {
        if (upper - mid == 1 ) {
            this->mis[lower * this->num_chord + upper] = this->mis[lower * this->num_chord + mid - 1] + 1; // k-1=j-2
            this->mis_chord_case[lower * this->num_chord + upper] = 2;
        }
        else if(this->mis[lower * this->num_chord + upper - 1] < (this->mis[lower * this->num_chord + mid - 1] + this->mis[(mid + 1) * this->num_chord + upper - 1] + 1)) {
            this->mis[lower * this->num_chord + upper] = this->mis[lower * this->num_chord + mid - 1] + mis[(mid + 1) * this->num_chord + upper - 1] + 1;
            this->mis_chord_case[lower * this->num_chord + upper] = 3;
        }
        else {
            this->mis[lower * this->num_chord + upper] = mis[lower * this->num_chord + upper - 1];
            this->mis_chord_case[lower * this->num_chord + upper] = 1;
        }
    }

    else {
        if (upper - lower == 1) {
            this->mis[lower * this->num_chord + upper] = 1;
            this->mis_chord_case[lower * this->num_chord + upper] = 4;
        }
        else{
            this->mis[lower * this->num_chord + upper] = this->mis[(lower + 1) * this->num_chord + (upper - 1)] + 1;
            this->mis_chord_case[lower * this->num_chord + upper] = 5;
        }
      
    }

}


void MPS::compute_mps() {

    for (int length = 0; length < this->num_chord; ++length) {
        for (int i = 0; i < this->num_chord-length; ++i) {
            mis_case(i, i+length);
        }
    }

    cout << "computing successfully" << endl;
}


void MPS::recursive_ans(bool* ans, int lower, int upper) {
    if (lower == upper) return;
    else {
        int case_number = this->mis_chord_case[lower * this->num_chord + upper];
        int mid = this->chord_point[upper];

        switch (case_number) {
            case 1:
                recursive_ans(ans, lower, --upper);
                break;
            case 2:
                ans[mid] = true;
                recursive_ans(ans, lower, upper -2);
                break;
            case 3:
                ans[mid] = true;
                recursive_ans(ans, lower, mid - 1);
                recursive_ans(ans, mid + 1, upper);
                break;
            case 4:
                ans[lower] = true;
                break;
            case 5:
                ans[lower] = true;
                recursive_ans(ans, lower + 1, upper -1);
        }


    }

}

void MPS::write_file_and_print(const char* output_file_name) {
    fstream fout;
    fout.open(output_file_name, fstream::out);
    if (!fout.is_open())
    {
        cout << "Error: the output file is not opened!!" << endl;
        exit(1);
    }

    fout << this->mis[this->num_chord - 1] << endl;

    bool* ans = new bool[this->num_chord];
    fill(ans, ans + this->num_chord, false);

    recursive_ans(ans, 0, this->num_chord-1);

    for (int i = 0; i < this->num_chord; ++i) {
        if (ans[i]) {
            fout << i << " " << this->chord_point[i] << endl;
        }
    }
}