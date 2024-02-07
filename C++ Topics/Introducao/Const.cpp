#include <iostream>

int main()
{
    // const nao permite alteracao do valor da variável.
    // É uma boa prática nomear em maiúscula variaveis const.
    const double PI = 3.14159;
    // PI = 4.1234 // Gera erro.
    double radius = 10;
    double circumference = 2 * PI * radius;

    std::cout << circumference << "cm\n";

    return 0;
}