#include <iostream>
#include <vector> 
#include <string> 
#include <list>

using std::cout, std::endl;
using std::vector, std::list;

template <typename T> 
void printl(list<T> & l)
{
    if (l.empty()) return;
    for (T & i : l) cout << i << " ";
    std::cout << std::endl;
}

//Print simple message.
void message(const char * s) { std::cout << s << std::endl; }
void message(const char * s , const int n ) { std::cout << s << " : " << n << std::endl;}

int main()
{
    //Initalize list.
    list<int> l1 = {1,2,3,4,5,6,7,8,9,10};
    printl(l1);

    //Iterate through the list and insert at 5.
    list<int>::iterator it1 = l1.begin();
    while((*++it1 != 5) && (it1!=l1.end()));
    if (it1 != l1.end())
    {
        message("insert 112 before 5");
        l1.insert(it1,112);
    }

    printl(l1);

}