#include <algorithm>
#include <exception>

class ExceptionElementNotFound : public std::exception {
    public :
        const char* what() const throw() { return "Element not found"; };
};

template <typename T>
typename T::iterator easyfind(T &hayStack, int &needle){

    typename T::iterator returnValue;
    returnValue = std::find(hayStack.begin(), hayStack.end(), needle);
    if (returnValue == hayStack.end())
        throw ExceptionElementNotFound();
    else
        return returnValue;
};