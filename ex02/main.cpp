#include "mutantstack.hpp"
#include <iostream>

int main( void )
{
    /*
     *  Testing MutantStack with integers 
     */
    std::cout << "Generating a MutantStack of integers, mstack..." << std::endl;
    MutantStack<int> mstack;
    std::cout << "Is mstack empty ? : " << mstack.empty() << std::endl;
    std::cout << std::endl;
    std::cout << "Pushing elements to the stack.." << std::endl;
    mstack.push(5);
    mstack.push(17);
    std::cout << "Size of mutantStack is: " << mstack.size() << std::endl;
    std::cout << "Top element of mutantStack is: " << mstack.top() << std::endl;
    std::cout << std::endl;
    std::cout << "Removing top of element of the stack.." << std::endl;
    mstack.pop();
    std::cout << "Now Size of mutantStack is: " << mstack.size() << std::endl;
    std::cout << "And top element of mutantStack is: " << mstack.top() << std::endl;
    std::cout << std::endl;
    std::cout << "Pushing new elements to the stack.." << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    std::cout << "Now Size of mutantStack is: " << mstack.size() << std::endl;
    std::cout << "And top element of mutantStack is: " << mstack.top() << std::endl;
    std::cout << std::endl;
    std::cout << "Testing forward iterators.." << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    std::cout << "Printing the stack from bottom to top:" << std::endl;
    while (it != ite)
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Testing reverse iterators.." << std::endl;
    MutantStack<int>::const_reverse_iterator rev_it = mstack.rbegin();
    MutantStack<int>::const_reverse_iterator rev_ite = mstack.rend();
    std::cout << "Printing the stack from top to bottom:" << std::endl;
    while (rev_it != rev_ite)
    {
        std::cout << *rev_it << " ";
        ++rev_it;
    }
    std::cout << std::endl;
    std::stack<int> copystack(mstack);
    std::cout << std::endl;
    std::cout << "Copy creation of copyStack from mStack..." << std::endl;
    std::cout << "Size of copystack is: " << copystack.size() << std::endl;
    std::cout << "Top element of copystack is: " << copystack.top() << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    /*
     *  Testing MutantStack with strings
     */
    std::cout << "Generating a MutantStack of strings, stringstack..." << std::endl;
    MutantStack<std::string> stringstack;
    std::cout << "Is stringstack empty ? : " << stringstack.empty() << std::endl;
    std::cout << std::endl;
    std::cout << "Pushing elements to the stack.." << std::endl;
    stringstack.push("apple");
    stringstack.push("banana");
    std::cout << "Size of mutantStack is: " << stringstack.size() << std::endl;
    std::cout << "Top element of mutantStack is: " << stringstack.top() << std::endl;
    std::cout << std::endl;
    std::cout << "Removing top of element of the stack.." << std::endl;
    stringstack.pop();
    std::cout << "Now Size of mutantStack is: " << stringstack.size() << std::endl;
    std::cout << "And top element of mutantStack is: " << stringstack.top() << std::endl;
    std::cout << std::endl;
    std::cout << "Pushing new elements to the stack.." << std::endl;
    stringstack.push("chips");
    stringstack.push("coconuts");
    stringstack.push("pasta");
    stringstack.push("coffee");
    std::cout << "Now Size of mutantStack is: " << stringstack.size() << std::endl;
    std::cout << "And top element of mutantStack is: " << stringstack.top() << std::endl;
    std::cout << std::endl;
    std::cout << "Testing forward iterators.." << std::endl;
    MutantStack<std::string>::iterator s_it = stringstack.begin();
    MutantStack<std::string>::iterator s_ite = stringstack.end();
    ++s_it;
    --s_it;
    std::cout << "Printing the stack from bottom to top:" << std::endl;
    while (s_it != s_ite)
    {
        std::cout << *s_it;
        if (s_it != s_ite - 1)
            std::cout << ", ";
        ++s_it;
    }
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Testing reverse iterators.." << std::endl;
    MutantStack<std::string>::const_reverse_iterator s_rev_it = stringstack.rbegin();
    MutantStack<std::string>::const_reverse_iterator s_rev_ite = stringstack.rend();
    std::cout << "Printing the stack from top to bottom:" << std::endl;
    while (s_rev_it != s_rev_ite)
    {
        std::cout << *s_rev_it;
        if (s_rev_it != s_rev_ite - 1)
            std::cout << ", ";
        ++s_rev_it;
    }
    std::cout << std::endl;
    return 0;
}