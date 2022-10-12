//Iterators share many similarities to pointers.
//We can reference/dereference iterators and have
//them traverse our containers. In addition, we can 
//Also call on their values.

#include <iostream>
#include <vector> 

using namespace std;

int main() 
{
    vector<int> v1 = {1,2,3,4};
    //This is our iterator object. 
    //Similar to pointers. It must share same type
    //As the declared object. 
    //Type of iterator is bound to the type of the class.
    vector<int>::iterator it1;

    //Create iterator object to check start and end of the
    //vector.
    vector<int>::iterator ibegin = v1.begin();
    vector<int>::iterator iend = v1.end();

    for(it1 = ibegin; it1 < iend; ++it1)
    {
        cout << *it1 << " ";
    }

    return 0;

}