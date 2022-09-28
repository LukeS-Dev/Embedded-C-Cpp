#include <iostream> 
#include <string> 

using std::cout; using std::endl;

bool trueExpression = true;
bool falseExpression = false;

//Standard types such as Bool,Int,Float, double... ETC are supported

//Strings are not supported in c native
//However C++ stdlib supports this

//Pointers Special data type for memory addresses.
//Pointers are refs to variables
//Same pointer may be used to access many different variables sequentially

//C++ Reference for types -> Basic concepts -> Fundamental types.

int dec = 100;
int hex = 0x3A;
int bin = 0b1100;
int units = 23U;

float decimalFloat = 23.0f;

double doubleDefault = 1.5;

char nullChar = '\0';
char newLine = '\n';

//Auto typing
auto a = 8;
auto b = 1234567811111;
auto c = 3.142f;
auto d = 3.142;
auto e = true;
auto f = 'd';

int main()
{
    //Anything here is a local variable, the data outside are
    //Global variables.
    int test = 0;

    /* This is a multi-line commment
    decloration.    

    pointer : * Dereference
    pointer : & Returns the address
    pointer : -> Gives acces to members or structures of the pointer. 

    */
    cout << typeid(a).name() << endl;
    cout << typeid(b).name() << endl;
    cout << typeid(c).name() << endl;
    cout << typeid(d).name() << endl;
    cout << typeid(e).name() << endl;
    cout << typeid(f).name() << endl;
}
