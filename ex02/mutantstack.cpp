#include "mutantstack.hpp"
#include <iostream>

MutantStack::MutantStack( void ){

	std::cout << "MutantStack - Default constructor called\n";
	return ;
};

MutantStack::MutantStack( MutantStack const & src ){

	std::cout << "MutantStack - Copy constructor called\n";
	*this = src;
	return ;
};

MutantStack::~MutantStack( void ){

	std::cout << "MutantStack - Destructor called\n";
	return;
};

MutantStack	&MutantStack::operator= ( MutantStack const & rhs ){

	this-> = ;
	return *this;
};

