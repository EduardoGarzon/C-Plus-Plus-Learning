#include <iostream>

int main()
{
    // Executa o bloco enquanto a condicao for verdadeira.
    // Executa -> Checagem -> Executa -> Checagem...

    int number;

    do
    {
        std::cout << "Enter a positive number: ";
        std::cin >> number;
    } while (number < 0);

    std::cout << "The number is " << number << '\n';

    return 0;
}