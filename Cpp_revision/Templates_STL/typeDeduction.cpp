#include <iostream>
#include <string>
#include <vector> 

//Type deduction means that the compiler can 
//Determine type based on the input - in these situations we don't
//Have to specify types.

template <class T> 
T maxof( const T & a, const T & b)
{
    return (a > b ? a : b);
}

//This is good because vector will take property of the type
template <class T> 
void printv(const std::vector<T> & v)
{
    if (v.empty()) return;
    std::cout << "Vector elements : ";
    //Here we iterate over vector.
    for(const T & i : v) std::cout << i << " ";
}

int main()
{
    int a = 7;
    int b = 9;

    //Int is resolved based on input types
    std::cout << "MAX is " << maxof(a,b) << std::endl;

    std::string c = "Hi there";
    std::string d = "Hi I have more characters";

    //String is resolved based on input types
    std::cout << "MAX is " << maxof(c,d) << std::endl;

    std::vector<int> v1 = {1,2,3,4,5,6};
    printv(v1);
    std::cout << std::endl;

    //By template deduction can also resolve string.
    std::vector<std::string> vStr = {"Hi","My","name","is","hello"};
    printv(vStr);
    
    return 0;
}