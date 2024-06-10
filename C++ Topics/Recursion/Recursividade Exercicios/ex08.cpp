/*
    Faça uma função recursiva que receba um número N e retorne o N-ésimo termo das
    sequências de Tribonacci e Padovan (uma função recursiva para cada).

    Os primeiros números de uma sequência Tribonacci são: 1, 1, 2, 4, 7, 13, 24, 44, 81, 149,
    274, 504.

    Alguns valores da sequência são: 1, 1, 1, 2, 2, 3, 4, 5, 7, 9, 12, 16, 21, 28...
*/

#include <iostream>

int TribonacciRecursivo(int n)
{
    if (n == 0 || n == 1)
    {
        return 0;
    }
    else if (n == 2)
    {
        return 1;
    }
    else
    {
        return TribonacciRecursivo(n - 1) + TribonacciRecursivo(n - 2) + TribonacciRecursivo(n - 3);
    }
}

int PadovanRecursivo(int n)
{
    if (n == 0 || n == 1 || n == 2)
    {
        return 1;
    }
    else
    {
        return PadovanRecursivo(n - 2) + PadovanRecursivo(n - 3);
    }
}

int main()
{
    int n = 0, result = 0;

    std::cout << "Informe o valor de n: ";
    std::cin >> n;
    std::cout << std::endl;

    result = TribonacciRecursivo(n);
    std::cout << "Sequência Tribonacci: " << result << std::endl;

    result = PadovanRecursivo(n);
    std::cout << "Sequência Padovan: " << result << std::endl;

    system("pause");
    return 0;
}