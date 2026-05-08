#include <iostream>
#include <time.h>
#include "Span.hpp"
#include <vector>

template<typename InputIterator>
void Span::addNumber(InputIterator begin, InputIterator end)
{
	if (this->i + std::distance(begin, end) > this->vec.capacity())
		throw Span::FullSpanException();
	this->vec.insert(vec.begin() + i, begin, end);
    i += std::distance(begin, end);
}

int main() {
    {
        Span vec(500000);
        srand(time(NULL));
        for (int i = 0; i < 500000; i++) {
            vec.addNumber(rand()%5000000);
        }
        std::cout << vec.shortestSpan() << std::endl;
        std::cout << vec.longestSpan() << std::endl;
    }
    {
        Span sp = Span(5);
        sp.addNumber(3);
        sp.addNumber(4);
        sp.addNumber(20);
        sp.addNumber(1);
        sp.addNumber(8);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    {
        std::vector<int> vec;
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(5);
        vec.push_back(6);
        Span sp = Span(5);
        sp.addNumber(vec.begin(), vec.end() - 2);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    return 0;
}