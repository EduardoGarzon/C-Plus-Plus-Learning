/*
    Programar em C um algoritmo recursivo que permita fazer à multiplicação a russa de 2
    entradas.
*/

#include <iostream>

int MultipRussaRec(int v1, int v2)
{
    if (v1 == 0 || v2 == 0)
    {
        return 0;
    }
    else if (v1 == 1)
    {
        return v2;
    }
    else if (v2 == 1)
    {
        return v1;
    }
    else if (v1 % 2 == 1)
    {
        return v2 + MultipRussaRec(v1 / 2, v2 * 2);
    }
    else
    {
        return MultipRussaRec(v1 / 2, v2 * 2);
    }
}

int main()
{
    int v1 = 0, v2 = 0, result = 0;

    std::cout << "Informe os valores de v1 e v2: ";
    std::cin >> v1 >> v2;

    result = MultipRussaRec(v1, v2);

    std::cout << "Resultado: " << result << std::endl;

    system("pause");
    return 0;
}