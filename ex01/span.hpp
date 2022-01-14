#ifndef SPAN_HPP
#define SPAN_HPP
#include <exception>
#include <vector>

class Span {

	public:

		Span( unsigned int N );
		~Span( void );

		void addNumber(const int &n);
		void addNumber(std::vector<int>::iterator it_begin, std::vector<int>::iterator it_end);
		unsigned int shortestSpan(void);
		unsigned int longestSpan(void);
		void printSpan(void);
		class ExceptionNoSpanToFind : public std::exception {
			public:
				const char *what() const throw();
		};
		class ExceptionVectorCapacityInsufficient : public std::exception {
			public:
				const char *what() const throw();
		};

	private:
		std::vector<int> _arr;
		static void _printElement(int &n);
		bool _vectorCapacityIsSufficient(int nbrElementsToAdd);
		bool _checkSpan(void);

};
#endif