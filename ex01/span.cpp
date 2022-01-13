#include "span.hpp"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

Span::Span( unsigned int N ) {

	std::cout << "Span - Constructor called\n";
	_arr.reserve(N);
	std::cout << "capacity: " <<  _arr.capacity() << std::endl;
	std::cout << "size: " <<  _arr.size() << std::endl;
	return ;
};

Span::~Span( void ){

	std::cout << "span - Destructor called\n";
	return;
};

void Span::addNumber(const int &n){

	//check size vs capacity
	_arr.push_back(n);
};

void Span::addNumber(std::vector<int>::iterator it_begin, std::vector<int>::iterator it_end){

	//check size vs capacity
	_arr.assign(it_begin, it_end);
};

unsigned int Span::shortestSpan(void){

	//check if _arr.size() > 1
	std::vector<int> dup(_arr);
	std::adjacent_difference(dup.begin(), dup.end(), dup.begin());	
	std::cout << "Diff: ";
	for (std::vector<int>::iterator i=dup.begin(); i < dup.end(); i++)
	{
		std::cout << *i << " ";
	}
	std::cout << "\n";
	for_each(dup.begin(), dup.end(), std::abs);
	return *std::min_element(dup.begin(), dup.end());
};	

unsigned int Span::longestSpan(void){

	int max = *std::max_element(_arr.begin(), _arr.end());
	int min = *std::min_element(_arr.begin(), _arr.end());
	std::cout << "max: " << max << " - min: " << min <<std::endl;
	return max - min;
};

void Span::_printElement(int &n){

	std::cout << " " << n;
};

void Span::printSpan(void){

	for_each(_arr.begin(), _arr.end(), _printElement);
};

const char* Span::ExceptionNoSpanToFind::what() const throw(){

	return "No span to find";
};