/*
    6. Escreva uma função recursiva que calcule a soma dos dígitos de um número inteiro.
    Por exemplo, se a entrada for 123, a saída deverá ser 1+2+3 = 6.
*/

#include <iostream>

int somaDigitos(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return (n % 10) + somaDigitos(n / 10);
}

int main()
{
    int n = 0, somatorio = 0;

    std::cout << "Informe um numero inteiro: ";
    std::cin >> n;

    somatorio = somaDigitos(n);

    std::cout << "O somatorio dos digitos e: " << somatorio << std::endl;

    system("pause");
    return 0;
}