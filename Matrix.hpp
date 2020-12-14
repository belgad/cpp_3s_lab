//
// Created by glebd on 14.12.2020.
//

#ifndef CPP_3S_LAB_MATRIX_HPP
#define CPP_3S_LAB_MATRIX_HPP

#include "Vector.hpp"

template <class T> class Matrix : public Vector<Vector<T>> {

public:
    Matrix(int s = 10);
    Matrix(const Matrix &mt);
    Matrix(const Vector<Vector<T>> &mt);
    bool operator==(const Matrix &mt);
    Matrix &operator=(const Matrix &mt);
    Matrix operator+(const Matrix &mt);
    Matrix operator-(const Matrix &mt);
    Matrix operator*(const Matrix &mt);
    friend std::istream &operator>>(std::istream &in, Matrix &mt) {
        for (int i = 0; i < mt.Size; i++)
            in >> mt.pVec[i];
        return in;
    }
    friend std::ostream &operator<<(std::ostream &out, Matrix &mt) {
        for (int i = 0; i < mt.Size; i++)
            out << mt.pVec[i];
        return out;
    }
};

template <class Type> Matrix<Type>::Matrix(int s) : Vector<Vector < Type>>(s) {
    for (int i = 0; i < s; i++)
        this->pVec[i] = Vector<Type>(s - i, i);
}

template <class Type> Matrix<Type>::Matrix(const Matrix<Type> &mt) : Vector<Vector < Type>>(mt) {}

template <class Type> Matrix<Type>::Matrix(const Vector<Vector<Type> > &mt) : Vector<Vector < Type>>(mt) {
    for (int i = 0; i < this->GetSize(); i++) {
        if (this->pVec[i].GetSize() != this->GetSize() - i)
            throw std::out_of_range("This is not a triangle matrix");
    }
}

template <class Type> Matrix<Type> &Matrix<Type>::operator=(const Matrix &mt) {
    if (this != &mt) {
        if (this->Size != mt.Size) {
            delete[] this->pVec;
            this->pVec = new Vector<Type>[mt.Size];
        }
        this->Size = mt.Size;
        this->StartIndex = mt.StartIndex;
        for (int i = 0; i < this->Size; i++) {
            this->pVec[i] = mt.pVec[i];
        }
    }
    return *this;
}

template <class Type> bool Matrix<Type>::operator==(Matrix const &mt) {
    if (this->Size != mt.Size || this->StartIndex != mt.StartIndex)
        return false;
    for (int i = 0; i < mt.Size; i++) {
        if (mt.pVec[i] != this->pVec[i])
            return false;
    }
    return true;
}

template <class Type> Matrix<Type> Matrix<Type>::operator+(const Matrix &mt) {
    Matrix tmp(*this);
    for (int i = 0; i < tmp.Size; i++)
        tmp.pVec[i] = tmp.pVec[i] + mt.pVec[i];
    return tmp;
}

template <class Type> Matrix<Type> Matrix<Type>::operator-(const Matrix &mt) {
    Matrix tmp(*this);
    for (int i = 0; i < tmp.Size; i++)
        tmp.pVec[i] = tmp.pVec[i] - mt.pVec[i];
    return tmp;
}

template <class Type> Matrix<Type> Matrix<Type>::operator*(const Matrix &mt) {
    Matrix<Type> tmp(this->Size);
    for (int i = 0; i < this->Size; i++)
        for (int j = 0; j < this->Size / 2; j++) { // size/2
            Type tp = Type();
            for (int k = i; k <= j; ++k) {
                tp = tp + (this->pVec[i][k] * mt.pVec[k][j]);
            }
            tmp.pVec[i][j] = tp;
        }
    return tmp;
}

#endif //CPP_3S_LAB_MATRIX_HPP
