#include <iostream>
#include <string>

/* Type casting is useful for when we want to covert one 
data type to another. 

Basic syntax is : (type) variable
*/

float flt = -7.44f;
int32_t sgn;
uint32_t unsgn;

int main()
{
    //implicit type conversion. Since flt can't be converted to int
    //compiler will truncate the value to -7
    sgn = flt; 

    //unsigned is also implicit. Since -7 is not supported we will get
    //result of 2^32 (32 bit int) - 7 // 2's compliment.
    unsgn = sgn;

    std::cout 
    << "Float : " << flt 
    << " \nconverts to signed int : " << sgn 
    << " \nwhich converts to unit : " << unsgn 
    << std::endl;  

    //temp calculations
    int fahrenheit = 100;
    int celsius;

    //This is standard conversion
    //If we don't do a proper typecast here, what will happen
    //Is that 5/9 will be evaluated as an int, which will be rounded to 0
    celsius = ((float)5/9) * (fahrenheit-32); 

    std::cout << "Fahrenheit    : " << fahrenheit << std::endl;
    std::cout << "Celcius       : " << celsius << std::endl;

}