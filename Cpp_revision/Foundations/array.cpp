#include <iostream> 

using std::cout; using std::endl;

int globalInt[5];

int main()
{
    globalInt[0] = 0;
    globalInt[1] = 1;
    globalInt[2] = 2;
    globalInt[3] = 3;
    globalInt[4] = 4;
    globalInt[5] = 5;

    for(int i = 0; i < sizeof(globalInt)/sizeof(int); i++)
    {
        cout << globalInt[i] << endl;
    }
    return 0;

}