/*
An easy one to start off on the right foot...
Make a template function called easyfind, templated on a type T, that takes a T
and an int.
Assume the T is a container of int, and find the first occurrence of the second parameter in the first parameter.
If it can’t be found, handle the error either using an exception or using an error return
value. Take ideas from how standard containers work.
Of course, you will provide a main function that tests it thoroughly
*/
#include <iostream>
#include <vector>

//template <typename T>
//T easyfind(T hayStack, int hay);

int main( void ){

    std::vector<int> vect1;
    int max = 5;
    for (int index=0; index < max; index++)
    {
        vect1.push_back(index);
        if (index == 3)
            vect1.push_back(42);
    }
    int hay = 442;
    std::vector<int>::const_iterator it;
    it = vect1.begin();
    while (it != vect1.end()){

        if (*it == hay)
        {
            std::cout << "Hay found at index: " << *it << std::endl;
            break ;
            //return *it;
        }
        ++it;
    }
    if (it == vect1.end())
        std::cout << "Hay not found" << std::endl; // Throw exception
    return 0;
};