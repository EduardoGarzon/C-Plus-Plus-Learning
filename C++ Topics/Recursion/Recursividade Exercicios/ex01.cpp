/*
    1. Crie uma função recursiva que receba um número inteiro positivo N
    e calcule o somatório dos números de 1 a N.
*/

#include <iostream>

int Somatorio(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        return n + Somatorio(n - 1);
    }
}

int main()
{
    int n, result;

    std::cout << "Informe um numero: ";
    std::cin >> n;

    result = Somatorio(n);
    std::cout << "Somatorio: " << result << std::endl;

    system("pause");
    return 0;
}