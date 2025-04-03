// Matrix.cpp
#include "matrix.hpp"
#include <vector>
#include <iostream>

// colon after parameter list of a constructor is a list of member
// variables and what to initialize them to
Matrix::Matrix(std::size_t size) : _size(size) {

}

Matrix::Matrix(std::vector<std::vector<int>> matrix) : _matrix(matrix) {
    std::vector<std::vector<int>> _matrix(_size, std::vector<int>(_size));
}

Matrix Matrix::operator+(const Matrix &rhs) const {
    Matrix result(_size);
    for (int i = 0; i < _size; i++) {
        for (int j = 0; j < _size; j++) {
            result.set_value(i, j, rhs.get_value(i, j) + this->get_value(i, j));
        }
    }
    return result;
}

Matrix Matrix::operator*(const Matrix &rhs) const {
    Matrix result(_size);
    int product; 
    for (int i = 0; i < _size; i++) {
        for (int j = 0; j < _size; j++) {
            for (int k = 0; k <_size; k++) {
                product += rhs.get_value(i, k) * this->get_value(i, k); 
            }
            result.set_value(i, j, product);
            product = 0;
        }
    }
    return result;
}

int Matrix::get_value(std::size_t i, std::size_t j) const{
    return _matrix.at(i).at(j);
}

void Matrix::set_value(std::size_t i, std::size_t j, int k) {
    _matrix.at(i).at(j) = k;
}

int Matrix::sum_diagonal_major() const {
    int sum = 0;
    for (int i = 0; i < _size; i++) {
        sum += this->get_value(i, i);
    }
    return sum;
}

int Matrix::sum_diagonal_minor() const {
    int sum = 0;
    for (int i = 0; i < _size; i++) {
        sum += this->get_value(i, _size-i);
    }
    return sum;
};

void Matrix::swap_rows(std::size_t r1, std::size_t r2) {


};

void Matrix::swap_cols(std::size_t c1, std::size_t c2) {

}

void Matrix::print_matrix() const {
    for (int i = 0; i <= _size; i++) {
        for (int j = 0; j <= _size; i++) {
            std::cout <<get_value(i, j) << "\n";
        }
    } 
}