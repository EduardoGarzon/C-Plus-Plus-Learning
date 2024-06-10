/*
    A sequência de Padovan é uma sequência de naturais P(n) definida pelos valores iniciais:
        P(0) = P(1) = P(2) = 1
    e a seguinte relação recursiva:
        P(n) = P(n - 2) + P(n - 3) se n > 2

    Alguns valores da sequência são: 1, 1, 1, 2, 2, 3, 4, 5, 7, 9, 12, 16, 21, 28...

    Faça uma função recursiva que receba um número N e retorne o N-ésimo termo da sequência de
    Padovan.
*/

#include <iostream>

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

    result = PadovanRecursivo(n);
    std::cout << n << "esimo termo da sequencia Padovan: " << result << std::endl;

    system("pause");
    return 0;
}