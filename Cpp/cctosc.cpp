#include <iostream> 
#include <string>

bool iscapital(char x);
std::string camelToSnake(std::string camel);

//return 1 if capital return 0 if not.
bool iscapital(char x)
{
       if (x >='A' && x <= 'Z')    return 1;
       else  return 0;
}

std::string camelToSnake(std::string camel)
{
    std::string snake;

    //Scan through individual characters. Append to end of the string.
    for(int i = 0; i< camel.size(); i++)
    {
        if (iscapital(camel[i]) == 0 || i == 0)
        {
            snake.push_back(camel[i]);
        } 
        else
        {
            snake.push_back('_');
            snake.push_back((char)tolower(camel[i]));
        }
    }

    return snake;
}

int sum(int a, int b)
{
    return a + b;
}


int main()
{
    std::string input;
    std::cout << "Enter a camel case string : " << std::endl;
    std::cin >> input; 
    std:: cout << "CC to SC " << camelToSnake(input) << std::endl;
    // std::cout << camelToSnake("HiThereCamelCaseToSnakeCase") << std::endl;
    // std::cout << camelToSnake("helloT!@#!@$@!#@!#!@#!!!PrintFinal") << std::endl;
    
}
