#include <iostream>

int main()
{
    // Array = A data structure that can hold multiple values
    //         values are accessed by an index number
    //         "kind of like a variable that holds multiples values".

    std::string cars[] = {"Corvette", "Mustang", "Camry"};
    double prices[] = {5.00, 7.00, 9.99};

    // std::cout << cars; // Displays array's address

    std::cout << cars[0] << '\n';
    std::cout << cars[1] << '\n';
    std::cout << cars[2] << '\n';

    // Iterating over array's elements.
    // Calculando o tamanho automaticamente do array com sizeof
    // possibilita incluir ou deletar elementos do vetor
    // sem se preocupar em atualizar as iteracoes manualmente.
    for (int i = 0; i < (sizeof(prices)/sizeof(double)); i++)
    {
        std::cout << prices[i] << '\n';
    }

    return 0;
}