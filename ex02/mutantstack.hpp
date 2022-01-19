#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <iterator>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {

	/*
		By default std::stack container uses std::deque which has iterators	
	*/
	public:

		MutantStack(){};
		MutantStack( MutantStack const & src ) { *this = src; };
		~MutantStack( void ){};
		MutantStack<T> &operator= (MutantStack<T> &rhs) { *this->c = rhs.c; return *this;};

		/*
			reusing iterator from std::deque which is the default sub-container of std::stack
		*/
		typedef typename std::deque<T, std::allocator<T> >::iterator iterator;
		typedef typename std::deque<T, std::allocator<T> >::const_iterator const_iterator;
		typedef typename std::deque<T, std::allocator<T> >::reverse_iterator reverse_iterator;
		typedef typename std::deque<T, std::allocator<T> >::const_reverse_iterator const_reverse_iterator;

		/*
			Using iterator from std::deque which is the default sub-container of std::stack
			"c" is the underlying container of std::stack (in other word, a member object of std::stack)
			Here "c" is a std::deque

			iterator / const_iterator / reverse_iterator / const_reverse_iterator are members of std::deque
			as deque follow both Container and ReversibleContainer requirements 
			source: https://en.cppreference.com/w/cpp/container/deque 
		*/

		iterator begin() { return this->c.begin(); }
		iterator end() { return this->c.end(); }

		reverse_iterator rbegin() { return this->c.rbegin(); }
		reverse_iterator rend() { return this->c.rend(); }

		const_iterator begin() const { return this->c.begin(); }
		const_iterator end() const { return this->c.end(); }

		const_reverse_iterator rbegin() const { return this->c.rbegin(); }
		const_reverse_iterator rend() const { return this->c.rend(); }
};

#endif
