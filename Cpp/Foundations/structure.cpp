#include <iostream>
#include <string>

using std::cout; using std::endl;
using std::string;

enum cowPurpose
{
    unassigned,
    pet,
    milk,
    breeding,
    meat
};

struct cow
{
    string name;
    int age;
    int purpose;
};

int main() 
{
    cow my_cow;
    my_cow.name = "Steve";
    my_cow.age = 10;
    my_cow.purpose = pet;

    cout << "Cow name : " << my_cow.name << "\nCow Age : " << my_cow.age << "\nCow purpose : " << my_cow.purpose << endl;

}
