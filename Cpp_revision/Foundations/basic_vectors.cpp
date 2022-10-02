//Vectors is a generic container class where memory is managed for us.
//Part of the STD C++ lib

#include <vector>
#include <iostream>
#include <string> 

#include "public/student.hpp"

std::vector<int> primes;
std::vector<student> studentList;

int main()
{
    primes.push_back(2);
    primes.push_back(3);
    primes.push_back(5);
    primes.push_back(7);
    primes.push_back(11);
    int index = 1;

    std::cout << "Vector has " << primes.size() << " Elements " << std::endl;
    std::cout << "Index : " << index + 1 << " Value : " << primes[index] << std::endl;

    studentList.push_back(student("StudOne",12,71.2));
    studentList.push_back(student("StudTwo",14,61.88));
    studentList.push_back(student("StudThree",11,68.1));
    
    for(int i = 0; i < studentList.size() ; i++)
    {
        std::cout << studentList[i].get_name() << std::endl;
    }

    std::cout << "First Student is  : " << studentList.begin()->get_name() <<std::endl;
    std::cout << "Last Student is   : " << (studentList.end() -1)->get_name() <<std::endl;

    return 0;
}