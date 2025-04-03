// Matrix.cpp
#include "matrix.hpp"
#include <vector>
#include <iostream>

// colon after parameter list of a constructor is a list of member
// variables and what to initialize them to
Matrix::Matrix(std::size_t size) : _size(size) {
    for (int i = 0; i < _size; i++) {
        _matrix.push_back(std::vector<int> ());
        for (int j = 0; j < _size; j++) {
            _matrix.at(i).push_back(0);
        }
    }
}

Matrix::Matrix(std::vector<std::vector<int> > matrix) : _matrix(matrix), _size(matrix.size()) {

}

Matrix Matrix::operator+(const Matrix &rhs) const {
    Matrix result(_size);
    for (int i = 0; i < _size; i++) {
        for (int j = 0; j < _size; j++) {
            result.set_value(i, j, (rhs.get_value(i, j) + this->get_value(i, j)));
        }
    }
    return result;
}

Matrix Matrix::operator*(const Matrix &rhs) const {
    Matrix result(_size);
    int product = 0; 
    for (int i = 0; i < _size; i++) {
        for (int j = 0; j < _size; j++) {
            for (int k = 0; k <_size; k++) {
                product += this->get_value(i, k) * rhs.get_value(k, j); 
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

int Matrix::get_size() const {
    return _size;
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
        sum += this->get_value(i, (_size-1) - i);
    }
    return sum;
};

void Matrix::swap_rows(std::size_t r1, std::size_t r2) {
    int value1; 
    int value2;
    for (int i = 0; i < _size; i++) {
        value1 = this->get_value(r1, i);
        value2 = this->get_value(r2, i);
        this->set_value(r1, i, value2);
        this->set_value(r2, i, value1);
    }
};

void Matrix::swap_cols(std::size_t c1, std::size_t c2) {
    int value1; 
    int value2;
    for (int i = 0; i < _size; i++) {
        value1 = this->get_value(i, c1);
        value2 = this->get_value(i, c2);
        this->set_value(i, c1, value2);
        this->set_value(i, c2, value1);
    }
}

void Matrix::print_matrix() const {
    for (int i = 0; i <= _size; i++) {
        for (int j = 0; j <= _size; i++) {
            std::cout <<get_value(i, j) << "\n";
        }
    } 
}