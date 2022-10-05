#ifndef TEMPLATE_DEF_H
#define TEMPLATE_DEF_H

//template doens't know the specializations. Link step will fail
//Doesn't know how to put it together. We need to add all the
//Implementation to the header File.

//If we were to constuct a class using templates:

template <class T> 
class myClass 
{
private:
    static testVar = 10;
public: 
    T & printVar ();
    T & setVar (const T &);
    ~myClass(){}
}

template <class T> 
T & myClass<T>::printVar()
{
    std::cout << this->testVar <<std::endl;
} 

template <class T> 
T & myClass<T>::setVar(const T & input)
{
    this->testVar = input;
}


#endif