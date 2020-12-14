//
// Created by glebd on 14.12.2020.
//

#include "magic.hpp"

int main() {
//    int size;
//    std::cout << "Enter size of matrix: ";
//    std::cin >> size;
    Matrix<int> a(5), b(5), c(5), d(5), e(5);

    int i, j;
    std::cout << "Testing support of representation of triangular matrix" << std::endl;

    for (i = 0; i < 5; i++) {
        for (j = i; j < 5; j++) {
            d[i][j] = i * 10 + j;
            e[i][j] = (i * 10 + j) * 100;
        }
    }

    std::cout << "Matrix d" << std::endl << d << std::endl;

    d = d * 2;
    std::cout << "Matrix d = d * 2" << std::endl << d << std::endl;
    std::cout << "Matrix e" << std::endl << e << std::endl;

    std::cout << "Testing support of representation of triangular matrix" << std::endl;

    for (i = 0; i < 5; i++) {
        for (j = i; j < 5; j++) {
            a[i][j] = i * 10 + j;
            b[i][j] = (i * 10 + j) * 100;
        }
    }

    c = a + b;
    std::cout << "Matrix a = " << std::endl << a << std::endl;
    std::cout << "Matrix b = " << std::endl << b << std::endl;
    std::cout << "Matrix c = a + b" << std::endl << c << std::endl;

    c = b - a;
    std::cout << "Matrix c = b - a" << std::endl << c << std::endl;

    c = a * b;
    std::cout << "Matrix c = a * b" << std::endl << c << std::endl;

    return 0;
}
