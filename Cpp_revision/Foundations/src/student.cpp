#include <iostream>
#include <string>

//Public
#include "../public/student.hpp"

//Constructor
student::student(std::string name_i, int age_i, int wam_i)
{
    name = name_i;
    age = age_i;
    wam = wam_i;
}

//Get Functions
std::string student::get_name()
{
    return this->name;
}

int student::get_age()
{
    return this->age;
}

int student::get_wam()
{
    return this->wam;
}

//Set functoins
void student::set_name(std::string new_name)
{
    name = new_name;
}

void student::set_age(int new_age)
{
    age = new_age;
}

void student::set_wam(int new_wam)
{
    wam = new_wam;
}

int main()
{
    return 0;
}