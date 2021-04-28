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

Vector();
Vector(int min, int max);
//Vector(const Vector<T>&);
~Vector();

T& operator[](int index);
T& operator[](int index) const;
Vector<T>& operator=(const Vector<T>&);

void resize(int);

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
