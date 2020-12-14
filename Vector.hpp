//
// Created by glebd on 14.12.2020.
//

#ifndef CPP_3S_LAB_VECTOR_HPP
#define CPP_3S_LAB_VECTOR_HPP

#include <iostream>

template <class T> class Vector {

protected:
    T *pVec;
    int Size;
    int StartIndex;

public:
    Vector(int s = 10, int si = 0);
    Vector(const Vector &v);
    int GetSize() { return Size; };
    int GetStartIndex() { return StartIndex; };
    T &GetValue(int pos);
    T &operator[](int pos);
    bool operator==(const Vector &v);
    bool operator!=(const Vector &v);
    Vector &operator=(const Vector &v);
    Vector operator+(const T &val);
    Vector operator-(const T &val);
    Vector operator*(const T &val);
    Vector operator+(const Vector &v);
    Vector operator-(const Vector &v);
    T operator*(const Vector &v);
    friend std::istream &operator>> (std::istream &in, Vector &v) {
        for (int i = 0; i < v.Size; i++)
            in >> v.pVec[i];
        return in;
    }
    friend std::ostream &operator<<(std::ostream &out, Vector &v) {
        for (int i = 0; i < v.Size; i++)
            out << v.pVec[i] << " ";
        out << std::endl;
        return out;
    }
};

template <class T> Vector<T>::Vector(int s, int si) {
    Size = s;
    StartIndex = si;
    pVec = new T[Size];
    for (int i = 0; i < Size; i++)
        pVec[i] = 0;
}

template <class T> Vector<T>::Vector(const Vector &v) {
    Size = v.Size;
    StartIndex = v.StartIndex;
    pVec = new T[Size];
    for (int i = 0; i < Size; i++)
        pVec[i] = v.pVec[i];
}

template <class T> T &Vector<T>::GetValue(int pos) {
    return pVec[pos - StartIndex];

}

template <class T> T &Vector<T>::operator[](int pos) {
    return pVec[pos - StartIndex];
}

template <class T> bool Vector<T>::operator==(Vector const &v) {
    if (Size != v.Size || StartIndex != v.StartIndex)
        return false;
    for (int i = 0; i < v.Size; i++) {
        if (v.pVec[i] != pVec[i])
            return false;
    }
    return true;
}

template <class T> bool Vector<T>::operator!=(Vector const &v) {
    if (Size != v.Size || StartIndex != v.StartIndex)
        return true;
    for (int i = 0; i < v.Size; i++) {
        if (v.pVec[i] != pVec[i])
            return true;
    }
    return false;
}

template <class T> Vector<T> &Vector<T>::operator=(const Vector &v) {
    if (this != &v) {
        if (Size != v.Size) {
            delete[] pVec;
            pVec = new T[v.Size];
        }
        Size = v.Size;
        StartIndex = v.StartIndex;
        for (int i = 0; i < Size; i++) {
            pVec[i] = v.pVec[i];
        }
    }
    return *this;
}

template <class T> Vector<T> Vector<T>::operator+(T const &val) {
    Vector<T> tmp(*this);
    for (int i = 0; i < this->Size; i++)
        tmp.pVec[i] += val;
    return tmp;
}

template <class T> Vector<T> Vector<T>::operator-(T const &val) {
    Vector<T> tmp(*this);
    for (int i = 0; i < this->Size; i++)
        tmp.pVec[i] -= val;
    return tmp;
}

template <class T> Vector<T> Vector<T>::operator*(const T &val) {
    Vector<T> tmp(*this);
    for (int i = 0; i < this->Size; i++)
        tmp.pVec[i] *= val;
    return tmp;
}

template <class T> Vector<T> Vector<T>::operator+(const Vector &v) {
    Vector<T> tmp(*this);
    if (v.Size != tmp.Size || v.StartIndex != tmp.StartIndex) throw std::length_error("Vectors' sizes must be equal");
    for (int i = 0; i < tmp.Size; i++)
        tmp.pVec[i] = tmp.pVec[i] + v.pVec[i];
    return tmp;
}

template <class T> Vector<T> Vector<T>::operator-(const Vector &v) {
    Vector<T> tmp(*this);
    if (v.Size != tmp.Size || v.StartIndex != tmp.StartIndex) throw std::length_error("Vectors' sizes must be equal");
    for (int i = 0; i < tmp.Size; i++)
        tmp.pVec[i] = tmp.pVec[i] - v.pVec[i];
    return tmp;
}

template <class T> T Vector<T>::operator*(const Vector &v) {
    T tmp = T();
    if (v.Size != Size || v.StartIndex != StartIndex) throw std::length_error("Vectors' sizes must be equal");
    for (int i = 0; i < Size; i++)
        tmp = tmp + (this->pVec[i] * v.pVec[i]);
    return tmp;
}

#endif //CPP_3S_LAB_VECTOR_HPP
