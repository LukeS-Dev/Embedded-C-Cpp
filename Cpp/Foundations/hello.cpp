#include <iostream>

//Declorations - Included in Cpp for now but will transition to .hpp later.
int mainUsingStd();

int main()
{
    std::cout << "Hello World" << std::endl;
    mainUsingStd();
    return 0;
}

//Using namespace might make code harder to read in future applications.
//I'll try to avoid this.
using namespace std;

int mainUsingStd()
{
    cout << "This section is printed with STD namespace!" << endl;
    cout << "Hello World" << endl;
    return 0;
}