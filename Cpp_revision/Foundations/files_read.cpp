#include <iostream>
#include <string>
#include <fstream>


std::ifstream inFile; 
std::string str;

int number;
char letter;

int main()
{
    inFile.open("text.txt");
    if (inFile.fail())
        std::cout << std::endl << "File not found" << std::endl;
    else 
    {
        while (!inFile.eof())
        {
            getline(inFile,str);
            std::cout << str << std::endl;
        }
    }
    return 0;
}