
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