#include "span.hpp"
#include <iostream>

int main()
{
    Span sp = Span(5);
    sp.addNumber(5);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << "Values assigned\n";
    std::cout << "Span: ";
    sp.printSpan();
    std::cout << std::endl;
    std::cout << "Longest span: ";
    std::cout << sp.longestSpan() << std::endl; // 15
    std::cout << "Shortest span: ";
    std::cout << sp.shortestSpan() << std::endl; // 2
}