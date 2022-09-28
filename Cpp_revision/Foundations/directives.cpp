//Include directive. - include known libs
#include <iostream>
#include <string> 

//Include C code. 
#include <cstdint> 

//MACROS -> Find and replace 
#define MAX_CAPACITY 10000
#define DEBUG

int main()
{
    uint32_t large = MAX_CAPACITY;
    uint8_t small = 10;

#ifdef DEBUG
    std::cout << "[ABOUT TO PERFORM ADDITON]" << std::endl;
#endif 

    large += small;

    std::cout << "The result is " << large << std::endl;
    return 0;
}
