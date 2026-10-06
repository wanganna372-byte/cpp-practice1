#include "matrix.hpp"

#include <cmath>
#include <iostream>
#include <stdexcept>
#include <string>

bool close(double lhs, double rhs, double tolerance = 1e-9)
{
    return std::abs(lhs - rhs) <= tolerance;
}

void check(bool condition, const std::string& label)
{
    std::cout << label << ": " << (condition ? "PASS" : "FAIL") << '\n';
}

int main()
{
    const Matrix a({{1.0, 2.0}, {3.0, 4.0}});
    const Matrix b({{2.0, 0.0}, {1.0, 2.0}});

    const Matrix sum = a + b;
    check(close(sum.at(0, 0), 3.0) && close(sum.at(0, 1), 2.0)
              && close(sum.at(1, 0), 4.0) && close(sum.at(1, 1), 6.0),
          "matrix addition");

    const Matrix product = a * b;
    check(close(product.at(0, 0), 4.0) && close(product.at(0, 1), 4.0)
              && close(product.at(1, 0), 10.0) && close(product.at(1, 1), 8.0),
          "matrix multiplication");

    std::cout << "Matrix a:\n" << a;

    // TODO: Add at least one addition test, one multiplication test,
    // and one invalid-dimension test.
// 1. 加零矩阵，结果应保持不变。
const Matrix zero({{0.0, 0.0}, {0.0, 0.0}});
const Matrix unchanged = a + zero;

check(close(unchanged.at(0, 0), 1.0)
          && close(unchanged.at(0, 1), 2.0)
          && close(unchanged.at(1, 0), 3.0)
          && close(unchanged.at(1, 1), 4.0),
      "addition with zero matrix");

// 2. 2×3 矩阵乘以 3×2 矩阵，结果为 2×2。
const Matrix c({{1.0, 2.0, 3.0},
                {4.0, 5.0, 6.0}});
const Matrix d({{7.0, 8.0},
                {9.0, 10.0},
                {11.0, 12.0}});

const Matrix result = c * d;

check(result.rows() == 2 && result.cols() == 2
          && close(result.at(0, 0), 58.0)
          && close(result.at(0, 1), 64.0)
          && close(result.at(1, 0), 139.0)
          && close(result.at(1, 1), 154.0),
      "rectangular matrix multiplication");

// 3. 2×2 与 2×3 矩阵不能相加，应抛出异常。
bool addition_threw = false;

try {
    (void)(a + c);
} catch (const std::invalid_argument&) {
    addition_threw = true;
}

check(addition_threw, "invalid addition dimensions");

// 4. 2×3 与 2×2 矩阵不能相乘，应抛出异常。
bool multiplication_threw = false;

try {
    (void)(c * a);
} catch (const std::invalid_argument&) {
    multiplication_threw = true;
}

check(multiplication_threw, "invalid multiplication dimensions");
    return 0;
}