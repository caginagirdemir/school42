#pragma once
#define MAX_VAL 750
#include <exception>

template <typename T>
class Array {
public:
    // const
    Array();
    Array(unsigned int n);
    
    // dest
    ~Array();

    // copy
    Array(Array<T> const &copy);

    // oper
    Array<T> operator&=(Array<T> const &other);
    T &operator[](unsigned int i);

    // memb
    unsigned int size() const;

    //excep
    class IndexOutOfBoundsException : public std::exception {
        virtual const char * what() const throw() {return "Index out of bounds.";}
    };

    class ArrayCreationException : public std::exception {
        virtual const char * what() const throw() {return "Array cant be created.";}
    };
private:
    unsigned int length;
    T *arr;
};

#include "Array.cpp"
