#include "vector.h"

//template class Vector<Cell>;

template <class T>
Vector<T>::Vector() {
    index_zero = -1;
    vector.resize(2);
}

template <class T>
Vector<T>::Vector(int min, int max) {
    assert (min < max);
    index_zero = min;
    int sz = max - min;
    vector.resize(sz);
}



template <class T>
Vector<T>::~Vector() {}

template <class T>
T& Vector<T>::operator[](int index) {
    assert(index >= GetLowerLimit());
    assert(index <= GetUpperLimit());
    return vector[index - index_zero];
}

template <class T>
T& Vector<T>::operator[](int index) const {
    assert(index >= GetLowerLimit());
    assert(index <= GetUpperLimit());
    return vector[index - index_zero];
}

template <class T>
void Vector<T>::resize(int sz) {
    vector.resize(sz);
}

template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& r_vec){
    index_zero = r_vec.index_zero;
    vector = r_vec.vector;
return *this;
}