#include <iostream>

int main()
{
    // foreach loop = loop that eases the travesal over an
    //                iterable data set.

    double prices[] = {1.1, 2.1, 3.1, 4.1, 5.1};

    // A variavel price recebe os elementos do array prices.
    // O tamanho do array é calculado automaticamente.
    for (double price : prices)
    {
        std::cout << price << '\n';
    }

    return 0;
}