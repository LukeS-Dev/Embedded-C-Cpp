#include <iostream> 
#include <string> 

int main()
{
    //Standard I/O interaction.
    std::string str; 
    std::cout << "Please enter your name : "; 
    std::cin >> str;
    std::cout << "Hi " << str << std::endl;
}