#include "matrix.hpp"

#include <ostream>
#include <stdexcept>

Matrix::Matrix(const std::vector<std::vector<double>>& values)
    : data_(values)
{
    if (data_.empty() || data_.front().empty()) {
        throw std::invalid_argument("a matrix must have at least one row and one column");
    }

    const std::size_t column_count = data_.front().size();
    for (const auto& row : data_) {
        if (row.size() != column_count) {
            throw std::invalid_argument("all matrix rows must have the same length");
        }
    }
}

std::size_t Matrix::rows() const
{
    return data_.size();
}

std::size_t Matrix::cols() const
{
    return data_.front().size();
}

double& Matrix::at(std::size_t row, std::size_t col)
{
    return data_.at(row).at(col);
}

double Matrix::at(std::size_t row, std::size_t col) const
{
    return data_.at(row).at(col);
}

Matrix Matrix::operator+(const Matrix& rhs) const
{
    // TODO: Check dimensions and return the element-wise sum.
    if (rows() != rhs.rows() || cols() != rhs.cols()) {
        throw std::invalid_argument(
            "matrix dimensions must match for addition");
    }

    std::vector<std::vector<double>> result = data_;

    for (std::size_t i = 0; i < rows(); ++i) {
        for (std::size_t j = 0; j < cols(); ++j) {
            result[i][j] = data_[i][j] + rhs.data_[i][j];
        }
    }
    return Matrix(result);
}

Matrix Matrix::operator*(const Matrix& rhs) const
{
    // TODO: Check dimensions and return the matrix product.
    if (cols() != rhs.rows()) {
        throw std::invalid_argument(
            "left columns must equal right rows for multiplication");
    }

    Matrix result(std::vector<std::vector<double>>(
        rows(), std::vector<double>(rhs.cols(), 0.0)));

    for (std::size_t i = 0; i < rows(); ++i) {
        for (std::size_t j = 0; j < rhs.cols(); ++j) {
            for (std::size_t k = 0; k < cols(); ++k) {
                result.at(i, j) += at(i, k) * rhs.at(k, j);
            }
        }
    }

    return Matrix(result);
}

std::ostream& operator<<(std::ostream& os, const Matrix& matrix)
{
    // TODO: Write the matrix to os, one row per line.
    for (std::size_t i = 0; i < matrix.rows(); ++i) {
        for (std::size_t j = 0; j < matrix.cols(); ++j) {
            if (j > 0) {
                os << ' ';
            }
            os << matrix.data_[i][j];
        }
        os << '\n';
    }
    return os;
}