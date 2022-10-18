#include <iostream> 
#include <array>
#include <string> 

using namespace std;

template<typename T, size_t N> 
void printa(array<T,N> &a)
{
    for(T &i : a) cout << i << " ";
    cout << endl;
}

void message(const char *s) { cout << s << endl;}
template<typename T> 
void message(const char * s, const T & v) { cout << s << ": " << v << endl;}

//STL array is a wrapper around C array.
//STL array has a fixed size. 
//STL array size can not change after it is intialized
int main()
{
    message("Initializer list");
    array<int, 5> a1 = {1,2,3,4,5};
    printa(a1);

    array<string,5> a2;
    a2 = {"One","Two","Three"};
    printa(a2);

    cout << a1.size() <<endl;
    cout << a2.size() <<endl;

}