#include <vector>
#include <cassert>
#include <iostream>
#include <iomanip>
#include "celda.h"

#pragma once

template<class T>
class Vector {

private:

int index_zero = 0;
std::vector<T> vector;


public:

Vector() {
    index_zero = -1;
    vector.resize(2);
}

Vector(int min, int max) {
    assert (min < max);
    index_zero = min;
    int sz = max - min;
    vector.resize(sz);
}

Vector(const Vector<T>& r_vec){
    index_zero = r_vec.GetLowerLimit();
    vector = r_vec.vector;
}

~Vector() {}

T& operator[](int index) {
    assert(index >= GetLowerLimit());
    assert(index <= GetUpperLimit());
    return vector[index - index_zero];
}

T& operator[](int index) const {
    assert(index >= GetLowerLimit());
    assert(index <= GetUpperLimit());
    return vector[index - index_zero];
}
/*
Vector<T>& operator=(const Vector<T>& r_vec){
    if (GetSize() < r_vec.GetSize()) {
      vector.resize(r_vec.GetSize());
      index_zero = r_vec.GetLowerLimit();
    }
    for (int i = r_vec.GetLowerLimit(); i < r_vec.GetUpperLimit(); i++)
        vector[i] = r_vec[i];
    return *this;
} */
void resize(int sz) {
    vector.resize(sz);
}

inline std::vector<T>& GetVector(){
    return vector;
}
inline int GetUpperLimit() const {
    return index_zero + vector.size();
}

inline int GetLowerLimit() const {
    return index_zero;
}

inline void SetLowerLimit(int min) {
    index_zero = min;
}

inline int GetSize() const {
    return GetUpperLimit() - GetLowerLimit();
}

};
