#include <iostream>
#include <fstream>
#include "maximum_planar_subset.h"

using namespace std;

int main(int argc, char** argv)
{
    MPS mps;
    mps.read_file("C:\\Users\\Mayma\\Desktop\\課程\\大三上\\演算法作業\\HW1\\prog1_resource\\5000.in");

    mps.compute_mps();

    mps.write_file_and_print("C:\\Users\\Mayma\\Desktop\\課程\\大三上\\演算法作業\\HW1\\prog1_resource\\5000.out");
    return 0;
}
