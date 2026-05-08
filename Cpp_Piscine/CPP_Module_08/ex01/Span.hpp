#pragma once

#include <exception>
#include <vector>

class Span {
public:
    // const
    Span();
    Span(int n);
    
    // dest
    ~Span();

    // copy
    Span(Span const &copy);
    Span &operator=(Span const &arr);

    // oper
    Span operator&=(Span const &other);

    // memb
    void addNumber(int number);
    template<typename InputIterator>
	void addNumber(InputIterator begin, InputIterator end);
    int shortestSpan();
    int longestSpan();

    //excep
    class IndexOutOfBoundsException : public std::exception {
        virtual const char * what() const throw();
    };
    class NoSpanException : public std::exception {
        virtual const char * what() const throw();
    };
    class ArrayCreationException : public std::exception {
        virtual const char * what() const throw();
    };
    class FullSpanException : public std::exception {
        virtual const char * what() const throw();
    };
public:
    int length;
    std::vector<int> vec;
    int i;
};
