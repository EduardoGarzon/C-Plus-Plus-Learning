#include <iostream>

int main()
{
    int age;

    std::cout << "Enter you age: ";
    std::cin >> age;

    if (age >= 18)
    {
        std::cout << "Welcome to the site!\n";
    }
    else if (age < 18 && age > 0)
    {
        std::cout << "You are not allowed to be here!\n";
    }
    else
    {
        std::cout << "You haven't been born yet!\n";
    }

    return 0;
}