#include <iostream>
#include <vector> 
#include <string> 

template <typename T> 
void printv(vector<T> & v)
{
    if (v.empty()) return;
    for (T & i : v) cout << i << " ";
    std::cout << std::endl;
}

//Print simple message.
void message(const char * s) { std::cout << s << std::endl; }
void message(const char * s , const int n ) { std::cout << s << " : " << n << std::endl;}

int main()
{
    
}