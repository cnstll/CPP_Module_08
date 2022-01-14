#include "span.hpp"
#include <algorithm>
#include <iostream>
#include <exception>
#include <cstdlib>
#include <ctime>

int genRandomNumber(void ) {

    int i;
    static bool done = false;
    if (done == false){
        std::srand(static_cast<unsigned int>(time(NULL)));
        done = true;
    }
    i = std::rand() % 100;
    return i;
};

void printInt(int i){

    std::cout << i << " ";
};

void printSpanWithName(Span &sp, const char *name){

    std::cout << "Span `" << name << "' content: ";
    std::cout << std::endl;
    sp.printSpan();
    std::cout << std::endl;
};

int main(void)
{
    { 
        std::cout << "Test: Simple Span\n";
        Span sp = Span(5);
        sp.addNumber(5);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        try {
            sp.addNumber(12);
        }
        catch (std::exception &e){
            std::cerr << "Exception: " << e.what() << std::endl;
        }
        printSpanWithName(sp, "sp");
        std::cout << "Longest span: ";
        std::cout << sp.longestSpan() << std::endl; // 14
        std::cout << "Shortest span: ";
        std::cout << sp.shortestSpan() << std::endl; // 2
    }
    { 
        std::cout << std::endl;
        std::cout << "Test: Simple Span with negative numbers\n";
        Span sp = Span(5);
        sp.addNumber(-1);
        sp.addNumber(16);
        sp.addNumber(-17);
        sp.addNumber(9);
        sp.addNumber(3);
        printSpanWithName(sp, "sp");
        std::cout << "Longest span: ";
        std::cout << sp.longestSpan() << std::endl; // 14
        std::cout << "Shortest span: ";
        std::cout << sp.shortestSpan() << std::endl; // 2
    }
    { 
        std::cout << std::endl;
        std::cout << "Test: No Span\n";
        Span sp = Span(5);
        printSpanWithName(sp, "sp");
        try {

            std::cout << "Longest span: ";
            std::cout << sp.longestSpan() << std::endl;
        }
        catch (std::exception &e){
            std::cerr << "Exception: " << e.what() << std::endl;
        }
        try {

            std::cout << "Shortest span: ";
            std::cout << sp.shortestSpan() << std::endl;
        }
        catch (std::exception &e){
            std::cerr << "Exception: " << e.what() << std::endl;
        }
        sp.addNumber(5);
        printSpanWithName(sp, "sp");
        try {

            std::cout << "Longest span: ";
            std::cout << sp.longestSpan() << std::endl;
        }
        catch (std::exception &e){
            std::cerr << "Exception: " << e.what() << std::endl;
        }
        try {

            std::cout << "Shortest span: ";
            std::cout << sp.shortestSpan() << std::endl;
        }
        catch (std::exception &e){
            std::cerr << "Exception: " << e.what() << std::endl;
        }
    }
    { 
        std::cout << std::endl;
        std::cout << "Test: Long Span\n";
        std::vector<int> vec1(100);
        std::generate(vec1.begin(), vec1.end(), genRandomNumber);
        //for_each(vec1.begin(), vec1.end(), printInt);
        //std::cout << std::endl;
        Span sp1 = Span(150);
        sp1.addNumber(vec1.begin(), vec1.end());
        printSpanWithName(sp1, "sp1");
        std::cout << "Trying to add 100 int to sp1 which has a size of 100 and a capacity of 150...\n";
        try {
            sp1.addNumber(vec1.begin(), vec1.end());
        }
        catch (std::exception &e){
            std::cerr << "Exception: " << e.what() << std::endl;
        }
        std::cout << "Sp1 did not change after exception...\n";
        printSpanWithName(sp1, "sp1");
        std::cout << std::endl;
        Span sp2 = Span(200);
        sp2.addNumber(vec1.begin(), vec1.end());
        std::cout << "Trying to add 100 int to sp2 which has a size of 100 and a capacity of 200...\n";
        sp2.addNumber(vec1.begin(), vec1.end());
        printSpanWithName(sp2, "sp2");
        std::cout << "Longest span: ";
        std::cout << sp2.longestSpan() << std::endl;
        std::cout << "Shortest span: ";
        std::cout << sp2.shortestSpan() << std::endl;
    }
    { 
        std::cout << std::endl;
        std::cout << "Test: Very Very Long Span\n";
        std::vector<int> vec1(100000);
        std::generate(vec1.begin(), vec1.end(), genRandomNumber);
        Span sp1 = Span(200000);
        std::cout << "Adding a range of 100 000 integers to span...\n";
        sp1.addNumber(vec1.begin(), vec1.end());
        std::cout << "Done\n";
        std::cout << "(Feel lucky I did not print that span...)\n";
        //printSpanWithName(sp1, "sp1");
    }
}