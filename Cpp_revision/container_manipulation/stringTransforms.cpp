#include <iostream>
#include <string> 
#include <algorithm>

int main()
{
    std::string s1 = "Normal string";
    std::cout << s1 << std::endl;

    std::string s2(s1.size(),'.');
    std::cout << s2 << std::endl;

    std::transform(
        s1.begin(),
        s1.end(),
        s2.begin(),
        ::toupper
    );

    std::cout << s2 << std::endl;
}