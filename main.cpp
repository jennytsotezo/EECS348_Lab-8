#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "matrix.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    if(argc < 2) {
        cerr << "Usage: " << argv[0] << " input_file" << endl;
        return 1;
    }
    
    ifstream infile(argv[1]);
    if(!infile.is_open()) {
        cerr << "Error opening file: " << argv[1] << endl;
        return 1;
    }
    int N;
    infile >> N;
    infile.ignore();

    vector<vector<int>> nums1;
    for (int i = 0; i < N; i++) {
        vector<int> row;
        for (int j = 0; j < N; j++) {
            int val;
            infile >> val;
            row.push_back(val);
        }
        nums1.push_back(row);
    }

    vector<vector<int>> nums2;
    for (int i = 0; i < N; i++) {
        vector<int> row;
        for (int j = 0; j < N; j++) {
            int val;
            infile >> val;
            row.push_back(val);
        }
        nums2.push_back(row);
    }

    infile.close();
    Matrix mat1(nums1);
    Matrix mat2(nums2);

    cout << "Matrix 1:" << endl;
    mat1.print_matrix();
    cout << endl;
    cout << "Matrix 2:" << endl;
    mat2.print_matrix();
    cout << endl;

    Matrix addResult = mat1 + mat2;
    cout << "Addition (Matrix 1 + Matrix 2):" << endl;
    addResult.print_matrix();
    cout << endl;

    Matrix multResult = mat1 * mat2;
    cout << "Multiplication (Matrix 1 * Matrix 2):" << endl;
    multResult.print_matrix();
    cout << endl;

    int sumMajor = mat1.sum_diagonal_major();
    int sumMinor = mat1.sum_diagonal_minor();
    cout << "Sum of major diagonal (Matrix 1): " << sumMajor << endl;
    cout << "Sum of minor diagonal (Matrix 1): " << sumMinor << endl;
    cout << endl;

    if (N > 1) {
        cout << "Swapping rows 0 and 1 in Matrix 1:" << endl;
        mat1.swap_rows(0, 1);
        mat1.print_matrix();
        cout << endl;
    }

    if (N > 1) {
        cout << "Swapping columns 0 and 1 in Matrix 1:" << endl;
        mat1.swap_cols(0, 1);
        mat1.print_matrix();
        cout << endl;
    }

    cout << "Updating element at (0, 0) to 99 in Matrix 1:" << endl;
    mat1.set_value(0, 0, 99);
    mat1.print_matrix();
    cout << endl;
    return 0;
}