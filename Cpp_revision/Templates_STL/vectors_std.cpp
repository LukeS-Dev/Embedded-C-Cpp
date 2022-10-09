#include <iostream>
#include <vector> 
#include <string> 

using std::cout, std::endl;
using std::vector; 

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
    //Vectors are a part of the STL lib. 
    cout << "Vector initializer list" << endl;
    vector<int> v1 = {1,2,3,4,5,6,7,8,9,10}; //C++ 11 onwards. 
    printv(v1);
    
    //Most containers have member functions to do things like this.
    message("Size",(int) v1.size());
    message("front", v1.front());
    message("back",v1.back());

    v1.insert(v1.begin() + 5 , 42);
    printv(v1);

    //Pushback() - Pushes to back of vector
    //Popback() - Pops from back of vector
    //Empty() - Checks for empty vector
    //insert() - insert(vx.begin(), {1,2,3,4,5}) - Can insert multiple.
    //clear() - Empty whole vector. 
    
}