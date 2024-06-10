/*
    Fatorial quadruplo de um numero n:
    (2n)!/n!
*/

#include <iostream>

unsigned long long fatorial(unsigned int n) {
    if (n == 0 || n == 1) {
        return 1; // O fatorial de 0 e 1 é 1
    } else {
        return n * fatorial(n - 1); // Chamada recursiva para calcular o fatorial
    }
}

unsigned long long fatorialQuadruplo(int n) {
    if (n == 0) {
        return 1; // O fatorial quadruplo de 0 é 1
    } else {
        return fatorial(2 * n) / fatorial(n); // Fatorial quadruplo usando a fórmula (2n)! / n!
    }
}


int main()
{
    int n = 0, fat = 0;

    std::cout << "Informe o valor de n: ";
    std::cin >> n;

    fat = fatorialQuadruplo(n);

    std::cout << "Fatorial Quadruplo: " << fat << std::endl;

    system("pause");
    return 0;
}