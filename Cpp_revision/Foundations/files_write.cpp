#include <fstream>
#include <iostream>

using std::ofstream;

ofstream outFile;
int a = 3, b = 20;

int main()
{
    outFile.open("text.txt");
    if (outFile.fail())
    {
        std::cout << "Couldn't open File" << std::endl;
    }
    else
    {
        outFile << "a : " << a << std::endl;
        outFile << "b : " << b << std::endl;
        outFile << "a + b = " << a + b << std::endl;
        outFile << "a - b " << a - b << std::endl;
        std::cout << "Success" << std::endl;
    }

    return 0;
}