#include <iostream>

int main()
{
    // integer (whole number)
    int x;      // declaration
    x = 5;      // assignment
    int y = 10; // declaration + assignment

    // double (number including decimal)
    double price = 10.99;

    // char (single character)
    char grade = 'A';

    // boolean (true or false)
    bool student = true;

    // string (object that represents a sequence of text)
    std::string name = "Eduardo";

    std::cout << x << '\n';
    std::cout << y << '\n';
    std::cout << price << '\n';
    std::cout << grade << '\n';
    std::cout << student << '\n';
    std::cout << "Hello " << name << '\n';

    return 0;
}