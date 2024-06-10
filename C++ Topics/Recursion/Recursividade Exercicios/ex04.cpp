/*
    A multiplicação de dois números inteiros pode ser feita através de somas sucessivas.
    Proponha um algoritmo recursivo Multip_Rec(n1,n2) que calcule a multiplicação de dois
    inteiros.
*/

#include <iostream>

void readValues(int *v1, int *v2)
{
    std::cout << "Informe o valor de v1 e v2: ";
    std::cin >> *v1 >> *v2;
}

int Multip_Rec(int v1, int v2) {
    // Casos base: quando um dos valores é 0 ou 1, a multiplicação é imediata
    if (v1 == 0 || v2 == 0) {
        return 0;
    } else if (v1 == 1) {
        return v2;
    } else if (v2 == 1) {
        return v1;
    }

    // Caso geral: dividir a multiplicação em partes menores através da recursão
    return v1 + Multip_Rec(v1, v2 - 1);
}

int main()
{
    int v1 = 0, v2 = 0, result = 0;

    readValues(&v1, &v2);
    result = Multip_Rec(v1, v2);

    std::cout << "O resultado da multiplicacao e: " << result << std::endl;

    system("pause");
    return 0;
}