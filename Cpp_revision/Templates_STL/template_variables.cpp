#include <iostream>
#include <string>

//Class or Typename are interchangable
//Specialization creates a new function at compile time. 

template <class T> 
//We do typecasing here.
//Constexpr makes Pi a constant.
constexpr T pi = T(3.1416926535897932385L);


template <class T>
T area_of_circle(const T & radius) 
{
    return radius * radius * pi<T>;
}

int main()
{
    std::cout.precision(20);

    //Limits at double because double can't support precision
    //of 20.
    std::cout << pi<double> << std::endl;
    std::cout << pi<long double> << std::endl;

    double rad = 10.0;

    std::cout << "Area of circle with radius : " << rad << " = ";
    std::cout << area_of_circle<long double>(rad) << std::endl;

    return 0;
}