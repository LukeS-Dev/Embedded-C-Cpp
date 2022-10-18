#include <iostream>
#include <string> 
#include <cstring>

using std::cout; using std::endl;
using std::string;

/* Strings are not native to C. in C strings are an
array of characters. 

In c++ there is a std::String class though. It has a lot
of useful functions.
*/

const int STRLEN = 25;
char array_cstr[STRLEN] = "Hi";
char array_cstr_end[] = " There";

string std_string = "Hi" ;
string std_string_end = " There";

int main()
{
    //C string concat method. Pass array then length then what to add.
    //Generatlly we shouldn't use this in C++ code, but this can be used for
    //Backwards compatibility with existing C code.
    strcat_s(array_cstr,STRLEN,array_cstr_end);
    cout << array_cstr << " : C string implementation " << endl;

    //C++ implementation. This uses operator overload which allows us to
    //directly concat with the + sign.
    cout << std_string + std_string_end << " : Std::String C++ implementation "<< endl;

    return 0; 
}