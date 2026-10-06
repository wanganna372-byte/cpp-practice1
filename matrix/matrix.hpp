#ifndef HOMEWORK_01_MATRIX_HPP
#define HOMEWORK_01_MATRIX_HPP

#include <cstddef>
#include <iosfwd>
#include <vector>

class Matrix {
public:
    explicit Matrix(const std::vector<std::vector<double>>& values);

    std::size_t rows() const;
    std::size_t cols() const;

    double& at(std::size_t row, std::size_t col);
    double at(std::size_t row, std::size_t col) const;

    Matrix operator+(const Matrix& rhs) const;
    Matrix operator*(const Matrix& rhs) const;

    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);

private:
    std::vector<std::vector<double>> data_;
};

#endif