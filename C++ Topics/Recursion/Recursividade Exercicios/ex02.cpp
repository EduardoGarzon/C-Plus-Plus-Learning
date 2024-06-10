/*
    2. Implemente uma função recursiva que, dados dois números inteiros x e n,
    calcula o valor de xn.
*/

#include <iostream>

int Potencia(int x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    else if (n == 1)
    {
        return x;
    }

    return x * Potencia(x, n - 1);
}

int main()
{
    int x, n, result;

    std::cout << "Informe a base: ";
    std::cin >> x;

    std::cout << "Informe o expoente: ";
    std::cin >> n;

    result = Potencia(x, n);
    std::cout << "Potencia: " << result << std::endl;

    system("pause");
    return 0;
}