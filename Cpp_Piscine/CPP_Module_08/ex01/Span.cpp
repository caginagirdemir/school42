#include "Span.hpp"
#include <vector>
#include <algorithm>
#include <limits>

Span::Span() : length(0), i(0) {}

Span::Span(int n) : i(0) {
    if (n <= 0)
        throw(Span::ArrayCreationException());
    length = n;
    vec = std::vector<int>(n);
}

// copy
Span::Span(Span const &copy) : length(copy.length) {
    vec = std::vector<int>(copy.length);
    for (int j = 0; j < copy.length; j++)
        this->vec[j] = copy.vec[j];
}

Span Span::operator&=(Span const &copy) {
    this->length = copy.length;
    vec = std::vector<int>(copy.length);
    for (int j = 0; j < copy.i; j++)
        this->vec[j] = copy.vec[j];
    return (*this);
}

// dest
Span::~Span() {}

void Span::addNumber(int number) {
    if (i >= length)
        throw(Span::IndexOutOfBoundsException());
    this->vec[i++] = number;
}

int Span::shortestSpan() {
    if (i < 2)
        throw(Span::NoSpanException());
    std::vector<int> tmp = vec;
    sort(tmp.begin(), tmp.begin() + i);
    int min = std::numeric_limits<int>::max();
    for (int j = 0; j < i - 1; j++) {
        if (tmp[j + 1] - tmp[j] < min)
            min = tmp[j + 1] - tmp[j];
    }
    return min;
}

int Span::longestSpan() {
    if (i < 2)
        throw(Span::NoSpanException());
    return *std::max_element(vec.begin(), vec.begin() + i) - *std::min_element(vec.begin(), vec.begin() + i);
}

template<typename InputIterator>
void Span::addNumber(InputIterator begin, InputIterator end)
{
	this->vec.insert(vec.end(), begin, end);
}

const char *Span::IndexOutOfBoundsException::what(void) const throw()
{
	return "Index out of bounds.";
};

const char *Span::NoSpanException::what(void) const throw()
{
	return "No span found.";
};

const char *Span::ArrayCreationException::what(void) const throw()
{
	return "Span cant be created.";
}

const char *Span::FullSpanException::what(void) const throw()
{
	return "Span is full.";
};