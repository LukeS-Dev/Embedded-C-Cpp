#include <iostream>
#include <string>

//What auto will do is make this type safe. 
//Since we don't have 2 variables being added and we dont
//know the individual types of the functions.
template <class lT, class rT> 
auto tf(const lT & lhs, const rT & rhs)
{
    return lhs + rhs;
}

int main()
{
    std::string temp = "Hello there";

    //Iterate over string. 
    //We can use auto if we don't know the type
    for (auto it = temp.begin(); it!=temp.end(); ++it)
    {
        std::cout << *it << " ";
    }
    
    std::cout << std::endl;

    //This is the "range method"
    for (auto c : temp )
    {
        std::cout << c << " ";
    }

    std::cout << std::endl;

    //Template will automatically resolve type. 
    auto result = tf<int,uint8_t>(11,55);
    std::cout << result << std::endl;
    std::cout << typeid(result).name() << std::endl;

    //Template can also be used to perform string additon.
    auto strResult = tf<std::string, std::string>("Hello ", "World!");
    std::cout << strResult << std::endl;
    std::cout << typeid(strResult).name() << std::endl;

    return 0;
}