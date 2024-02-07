#include <iostream>

void printInfo(std::string name, int age);

int main()
{
    // const parameter = parameter that is effectively read-only
    //                   code is more secure & conveys intent
    //                   useful for references and pointers.

    std::string name = "Luiz";
    int age = 21;

    printInfo(name, age);

    return 0;
}

void printInfo(const std::string name, const int age)
{
    // name = ""; // Displays Error
    // age = 0;   // Displays Error
    std::cout << name << '\n';
    std::cout << age << '\n';
}