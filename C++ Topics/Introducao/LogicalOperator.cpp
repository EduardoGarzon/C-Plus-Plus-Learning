#include <iostream>

int main()
{
    int temp;

    std::cout << "Enter the temperature: ";
    std::cin >> temp;

    if (temp >= 20 && temp <= 30)
    {
        std::cout << "The temperature is good!\n";
    }
    else
    {
        std::cout << "The temperature is bad!\n";
    }

    if (temp <= 0 || temp > 30)
    {
        std::cout << "The temperature is bad!\n";
    }
    else
    {
        std::cout << "The temperature is good!\n";
    }

    if (!(temp > 30) && !(temp <= 0))
    {
        std::cout << "The temperature is good!\n";
    }
    else
    {
        std::cout << "The temperature is bad!\n";
    }

    return 0;
}