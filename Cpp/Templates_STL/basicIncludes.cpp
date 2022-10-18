#include <iostream>
#include <string>

//Class or Typename are interchangable 

template <class T> 
T printType( const T & type)
{
    std::cout << type << std::endl;
    return 0;
}


int main()
{

    return 0;
}