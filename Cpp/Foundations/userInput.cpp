#include <iostream> 
#include <string> 

int main()
{
    //Fetch the string and insert it to str 
    std::string str; 
    std::cout << "Please enter your name : "; 
    std::getline(std::cin,str);
    std::cout << "Hi " << str << std::endl;
}