#include <iostream> 
#include <vector> 
#include <string>
#include <functional>
#include <algorithm>

void lambdaSum();
void vectorTransform();

template<typename T>
void printV(std::vector<T> inputVect)
{
    for(auto value : inputVect)
    {
        std::cout << value << " " << std::endl;
    }
    std::cout << std::endl;
}

int main()
{
    //lambdaSum();
    vectorTransform();

    return 0;
}


void lambdaSum()
{
    auto sum = []() {return 1 + 2;};
    std::cout << sum();

    std::cout << std::endl;

    auto sumInput = [](int a, int b) {return a + b;};
    std::cout << sumInput(20,30);
}

void vectorTransform()
{
    std::vector<std::string> stringVector = {"One","Two","Three","Four","Five","Six"};

    std::vector<size_t> strSize(0,stringVector.size());
    printV(stringVector);

    strSize = std::transform(
        stringVector.begin(),
        stringVector.end(),
        strSize.begin(),
        [](std::string & input) {return input.size();});

    //printV(strSize);
    
}