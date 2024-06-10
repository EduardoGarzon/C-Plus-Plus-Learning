/*
    5. Escreva uma função recursiva que calcule o número de grupos distintos com k pessoas
    que podem ser formados a partir de um conjunto de n pessoas.

    A definição abaixo da função Comb(n,k) define as regras:
    Comb(n, k) = n se k = 1
                 1 se k = n
                 Comb(n - 1, k - 1) + Comb(n - 1, k) se 1 < k < n
*/

#include <iostream>

int formGroups(int n, int k)
{
    if (k == 1)
    {
        return n;
    }
    else if (k == n)
    {
        return 1;
    }
    else if ((k > 1) && (k < n))
    {
        return formGroups(n - 1, k - 1) + formGroups(n - 1, k);
    }
}

int main()
{
    int n = 0, k = 0, groups;

    std::cout << "Informe o numero de pessoas por grupo: " << std::endl;
    std::cin >> k;

    std::cout << "Informe o numero de pessoas: " << std::endl;
    std::cin >> n;

    groups = formGroups(n, k);

    std::cout << "Grupos distintos formados: " << groups << std::endl;

    system("pause");
    return 0;
}