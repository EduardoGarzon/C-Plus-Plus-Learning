#include <iostream>

int main()
{
    // Ternary Operator (condition ? true : false) : replacement to and if/else statement.

    int grade = 75;

    grade >= 70 && grade <= 100 ? std::cout << "You pass!\n" : std::cout << "You fail!\n";

    grade % 2 ? std::cout << "ODD\n" : std::cout << "EVEN\n ";

    return 0;
}