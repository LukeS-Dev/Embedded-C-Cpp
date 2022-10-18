#include <iostream>
#include <string>

//Dependencies
#include "public/student.hpp"

int main()
{
    int a = 37;    
    //point to a.
    int *ptr = &a;
    std::cout << "Address location : " << ptr << std::endl;
    std::cout << "Value            : " << *ptr << std::endl;
    
    //Dynamic Memory allocation for classes is done in Cpp
    student *myStudent = new student("Student!!!",18,89.22);

    std::cout << "Student Name  : " << myStudent->get_name() << std::endl;
    std::cout << "Student age   : " << myStudent->get_age() << std::endl;
    std::cout << "Student WAM   : " << myStudent->get_wam() << std::endl;

    delete myStudent;

    return 0;
}