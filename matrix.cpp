#include "matrix.hpp"
#include <iostream>
#include <iomanip>

Matrix::Matrix(size_t N) : n(N), data(N, std::vector<int>(N, 0)) {}

Matrix::Matrix(std::vector<std::vector<int>> nums) : n(nums.size()), data(nums) {}

Matrix Matrix::operator+(const Matrix &rhs) const {
    if(n != rhs.n) {
        std::cerr << "Matrix sizes do not match for addition." << std::endl;
        exit(1);
    }
    Matrix result(n);
    for (std::size_t i = 0; i < n; i++) {
        for (std::size_t j = 0; j < n; j++) {
            result.data[i][j] = data[i][j] + rhs.data[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator*(const Matrix &rhs) const {
    if(n != rhs.n) {
        std::cerr << "Matrix sizes do not match for multiplication." << std::endl;
        exit(1);
    }
    Matrix result(n);
    for (std::size_t i = 0; i < n; i++) {
        for (std::size_t j = 0; j < n; j++) {
            int sum = 0;
            for (std::size_t k = 0; k < n; k++) {
                sum += data[i][k] * rhs.data[k][j];
            }
            result.data[i][j] = sum;
        }
    }
    return result;
}

void Matrix::set_value(std::size_t i, std::size_t j, int val) {
    if(i >= n || j >= n) {
        std::cerr << "Index out of bounds in set_value." << std::endl;
        return;
    }
    data[i][j] = val;
}

int Matrix::get_value(std::size_t i, std::size_t j) const {
    if(i >= n || j >= n) {
        std::cerr << "Index out of bounds in get_value." << std::endl;
        return 0;
    }
    return data[i][j];
}

int Matrix::get_size() const {
    return static_cast<int>(n);
}

int Matrix::sum_diagonal_major() const {
    int sum = 0;
    for (std::size_t i = 0; i < n; i++) {
        sum += data[i][i];
    }
    return sum;
}

int Matrix::sum_diagonal_minor() const {
    int sum = 0;
    for (std::size_t i = 0; i < n; i++) {
        sum += data[i][n - 1 - i];
    }
    return sum;
}

void Matrix::swap_rows(std::size_t r1, std::size_t r2) {
    if(r1 >= n || r2 >= n) {
        std::cerr << "Row index out of bounds in swap_rows." << std::endl;
        return;
    }
    std::swap(data[r1], data[r2]);
}

void Matrix::swap_cols(std::size_t c1, std::size_t c2) {
    if(c1 >= n || c2 >= n) {
        std::cerr << "Column index out of bounds in swap_cols." << std::endl;
        return;
    }
    for (std::size_t i = 0; i < n; i++) {
        std::swap(data[i][c1], data[i][c2]);
    }
}

void Matrix::print_matrix() const {
    int width = 0;
    for (std::size_t i = 0; i < n; i++) {
        for (std::size_t j = 0; j < n; j++) {
            int len = std::to_string(data[i][j]).length();
            if(len > width) width = len;
        }
    }
    for (std::size_t i = 0; i < n; i++) {
        for (std::size_t j = 0; j < n; j++) {
            std::cout << std::setw(width + 1) << data[i][j];
        }
        std::cout << std::endl;
    }
}