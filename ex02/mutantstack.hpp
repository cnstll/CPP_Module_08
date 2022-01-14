#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <iterator>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {

	public:

		MutantStack();
		MutantStack( MutantStack const & src );
		~MutantStack( void );
		class iterator {
			public :
				iterator(pointer ptr) : _ptr(ptr) {};
			private :
				pointer ptr;
		};

	private:

};
#endif
