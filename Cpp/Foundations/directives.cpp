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

/* We can define constants -> Directives / Macros / Define are macros. 
   We can also do constant defs with Const.
   C -> only means variable can't be changed. 
   C++ -> Const has additional protection in place.
*/
