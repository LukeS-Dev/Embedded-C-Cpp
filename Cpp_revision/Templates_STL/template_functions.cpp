#include <iostream>
#include <string>

//In templates, we don't need to worry about type at 
//the beginning. compiler constructs "specialization"
//on compile time.

//Templates can dynamically used to compare different
//Types. - Template is compiler extraction.
template <typename T> 
T maxof (const T & a, const T & b) 
{
    return (a > b ? a : b);
}

int main()
{
    int a = 7;
    int b = 9;

    //Int comparison
    std::cout << "max is " << maxof<int> (a,b) << std::endl;

    std::string c = "seven";
    std::string d = "nine";
    
    //Alphabet comparison 
    std::cout << "max is " << maxof<std::string> (c,d) << std::endl;

    return 0;
}