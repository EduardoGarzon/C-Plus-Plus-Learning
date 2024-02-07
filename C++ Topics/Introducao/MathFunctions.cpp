#include <iostream>
#include <cmath>

int main()
{
    double a = 3.14;
    double b = 9.99;
    double x = 3;
    double y = 4;
    double z;

    // Valor max
    z = std::max(x, y);
    std::cout << z << '\n'; // Displays 4.

    // Valor min
    z = std::min(x, y);
    std::cout << z << '\n'; // Displays 3.

    // Potencia
    z = pow(2, 4);
    std::cout << z << '\n'; // Displays 16.

    // Raiz Quadrada
    z = sqrt(9);
    std::cout << z << '\n'; // Displays 3.

    // Valor Absoluto
    z = abs(-100);
    std::cout << z << '\n'; // Displays 100.

    // Arredondamento
    z = round(a);
    std::cout << z << '\n'; // Displays 3.

    // Arredondamento up
    z = ceil(a);
    std::cout << z << '\n'; // Displays 4.

    // Arredondamento down
    z = floor(b);
    std::cout << z << '\n'; // Displays 9.

    return 0;
}