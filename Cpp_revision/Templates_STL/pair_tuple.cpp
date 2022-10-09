#include <iostream>
#include <vector> 
#include <string> 
#include <utility>
#include <tuple>

using namespace std;

void testpairs();
void testTuples();

template<typename T> 
void print3tuple(T t) 
{
    auto tsz = tuple_size<decltype(t)>::value;
    if(tsz != 3) return;
    {
        cout << get<0>(t) << " : " << get<1>(t) << " : " << get<2>(t) <<endl;
    }
}

/*PAIRS*/
template <typename T1, typename T2> 
void printpair(pair<T1,T2> & p)
{
    std::cout << p.first << " : " << p.second << std::endl;
}

//Print simple message.
void message(const char * s) { std::cout << s << std::endl; }
void message(const char * s , const int n ) { std::cout << s << " : " << n << std::endl;}

int main()
{
    //Pairs!
    //testpairs();

    //Tuple!
    testTuples();

}

void testTuples()
{
    tuple<string,int,int> t1 = {"Ages", 22,33};
    print3tuple(t1);
}

void testpairs()
{
    pair<string,int> p1 = {"Age", 10};
    printpair(p1);
    
    pair<string,string> p2("Name", "Jake");
    printpair(p2);

    pair<string,int> p3 = std::make_pair("Cost", 100);
    printpair(p3);

}