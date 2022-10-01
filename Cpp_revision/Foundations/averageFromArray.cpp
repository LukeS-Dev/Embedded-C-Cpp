#include <iostream> 
#include <string> 

const int MAX_ARRAY_LEN = 5;

float average(int input[MAX_ARRAY_LEN]);


int main()
{
    int numbers[MAX_ARRAY_LEN] = {1,7,8,2};
    std::cout << average(numbers) << std::endl;
}


float average(int input[MAX_ARRAY_LEN])
{
    float total = 0.0f;
    float average = 0.0f;

    for(int i=0; i < MAX_ARRAY_LEN; i++) 
    {
        std::cout << input[i] << std::endl;
        total = total + input[i];
    }

    average = total/(float)MAX_ARRAY_LEN;
    return average;
}