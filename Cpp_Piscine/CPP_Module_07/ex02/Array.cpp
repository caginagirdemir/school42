#include "Array.hpp"

template<typename T>
Array<T>::Array() : length(0), arr(nullptr) {}

template<typename T>
Array<T>::Array(unsigned int n) {
    if (n <= 0)
        throw(Array::ArrayCreationException());
    length = n;
    arr = new T[n];
}

// copy
template<typename T>
Array<T>::Array(Array<T> const &copy) {
    if (length > 0 && length < MAX_VAL)
        delete[] arr;
    this->length = copy.length;
    this->arr = new T[copy.length];
    for (unsigned int i = 0; i < copy.length; i++)
        this->arr[i] = copy.arr[i];
}

template<typename T>
Array<T> Array<T>::operator&=(Array<T> const &copy) {
    (void)copy;
    return (*this);
}

template<typename T>
T &Array<T>::operator[](unsigned int i) {
    if (size() <= i || i < 0)
        throw(Array<T>::IndexOutOfBoundsException());
    return arr[i];
}

// dest
template<typename T>
Array<T>::~Array() {
    if (length > 0)
        delete[] arr;
}

template<typename T>
unsigned int Array<T>::size() const {
    return this->length;
}