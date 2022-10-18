#include <iostream>
#include <deque> 
#include <string> 
#include <queue>

using namespace std; 

template <typename T>
void reportdeq(T &d)
{
    size_t sz = d.size();
    cout << "Size : " << sz;
    if (sz) cout << " Front : " << d.front() << " Back : " << d.back();
    cout << endl;
}

template<typename T>
void reportque(T & q)
{
    size_t sz = q.size();
    cout << "Size : " <<sz;
    if (sz) cout << " Front : " << q.front() << " Back : " << q.back();
    cout << endl;
}

//deque => Double ended queue.
int main()
{
    //create deque. -> deque is optimized for pop and push from both
    //ends of the queue. 
    //queue is functionally the same however 
    deque<string> d1 = {"One","Two","Three"};
    reportdeq(d1);
    
    d1.push_back("InsertOne");
    d1.push_front("Insert Two");

    reportdeq(d1);
    
    //Queue is fifo impimentation. Push to front, pop from back.
    //Default underlying container is deque. 

    queue<string> q1;
    reportque(q1);

    q1.push("Four");
    reportque(q1);
    q1.pop();
    reportque(q1);
    
    //In addition there is a STACK which is last in 
    //First out container. Basically can be used for
    //Tracing functions etc. (Call Stack)
    
    //Function 3 -> Last entry (First to pop)
    //Function 2
    //Function 1 -> First entry (Last to pop)
}
