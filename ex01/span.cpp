#include "Span.hpp"
#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>

Span::Span( unsigned int N ) {

	//std::cout << "Span - Constructor called\n";
	_arr.reserve(N);
	//std::cout << "Ctor capacity: " <<  _arr.capacity() << std::endl;
	//std::cout << "Ctor size: " <<  _arr.size() << std::endl;
	return ;
};

Span::Span( Span const &src ) : _arr(src._arr) {

	//std::cout << "Span - Copy Constructor called\n";
	return ;
};

Span::~Span( void ){

	//std::cout << "Span - Destructor called\n";
	return ;
};

Span &Span::operator= (Span &rhs){

	this->_arr = rhs._arr;
	return *this;
};

void Span::addNumber(const int &n){

	if (_vectorCapacityIsSufficient(1) == false){
		throw ExceptionVectorCapacityInsufficient();
		return ;
	}
	_arr.push_back(n);
};

void Span::addNumber(std::vector<int>::iterator it_begin, std::vector<int>::iterator it_end){

	if (_vectorCapacityIsSufficient(std::distance(it_begin, it_end)) == false){
		throw ExceptionVectorCapacityInsufficient();
		return ;
	}
	_arr.insert(_arr.begin(), it_begin, it_end);
};

unsigned int Span::shortestSpan(void){

	if (_checkSpan() == false){
		throw ExceptionNoSpanToFind();
		return 0;
	}
	std::vector<int> dup(_arr);
	std::sort(dup.begin(), dup.end());
	int shortestSpan = std::numeric_limits<int>::max();
	for (std::vector<int>::iterator i=dup.begin(); i < dup.end(); i++) {
		if (i + 1 != dup.end() && shortestSpan > std::abs((*(i + 1)) - (*i)))
			shortestSpan = std::abs((*(i + 1)) - (*i));
	}
	return shortestSpan;
};	

unsigned int Span::longestSpan(void){

	if (_checkSpan() == false){
		throw ExceptionNoSpanToFind();
		return 0;
	}
	int max = *std::max_element(_arr.begin(), _arr.end());
	int min = *std::min_element(_arr.begin(), _arr.end());
	return max - min;
};

void Span::_printElement(int &n){

	std::cout << " " << n;
};

bool Span::_checkSpan(void){

	return (this->_arr.size() > 1);
};

bool Span::_vectorCapacityIsSufficient(int nbrElementsToAdd){

	return (this->_arr.size() + nbrElementsToAdd <= this->_arr.capacity());
};

void Span::printSpan(void){

	for_each(_arr.begin(), _arr.end(), _printElement);
};

const char* Span::ExceptionNoSpanToFind::what() const throw(){

	return "No span to find";
};

const char* Span::ExceptionVectorCapacityInsufficient::what() const throw(){

	return "Span capacity insufficient";
};