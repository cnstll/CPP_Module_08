#include "easyfind.hpp"
#include <iostream>
#include <list>
#include <vector>

int main( void ){

    {
        std::cout << "Testing std::vector..." << std::endl;
        std::vector<int> vect1;
        int max = 5;
        for (int index=0; index < max; index++)
        {
            vect1.push_back(index);
            if (index == 3)
                vect1.push_back(42);
        }
        int needle = 42;
        std::cout << "Is " << needle << " in vector?" << std::endl;
        std::vector<int>::iterator easyfindReturn1;
        try {
            easyfindReturn1 = easyfind(vect1, needle);
            std::cout << needle << " was found!" << std::endl;
        }
        catch (std::exception &e){
            std::cerr << "Exception: " << e.what() << std::endl;
        }
        needle = 442;
        std::cout << "Is " << needle << " in vector?" << std::endl;
        std::vector<int>::iterator easyfindReturn2;
        try {
            easyfindReturn2 = easyfind(vect1, needle);
            std::cout << needle << " was found!" << std::endl;
        }
        catch (std::exception &e){
            std::cerr << "Exception: " << e.what() << std::endl;
        }
    }
    {
        std::cout << std::endl;
        std::cout << "Testing std::list..." << std::endl;
        std::list<int> lst1;
        int max = 5;
        for (int index=0; index < max; index++)
        {
            lst1.push_back(index);
            if (index == 2)
                lst1.push_back(21);
        }
        int needle = 21;
        std::cout << "Is " << needle << " in list?" << std::endl;
        std::list<int>::iterator easyfindReturn1;
        try {
            easyfindReturn1 = easyfind(lst1, needle);
            std::cout << needle << " was found!" << std::endl;
        }
        catch (std::exception &e){
            std::cerr << "Exception: " << e.what() << std::endl;
        }
        needle = 42;
        std::cout << "Is " << needle << " in list?" << std::endl;
        std::list<int>::iterator easyfindReturn2;
        try {
            easyfindReturn2 = easyfind(lst1, needle);
            std::cout << needle << " was found!" << std::endl;
        }
        catch (std::exception &e){
            std::cerr << "Exception: " << e.what() << std::endl;
        }
    }
    return 0;
};