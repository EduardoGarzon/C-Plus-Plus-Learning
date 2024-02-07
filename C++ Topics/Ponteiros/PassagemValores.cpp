#include <iostream>

void swap(std::string &x, std::string &y);

int main()
{
    std::string x = "Kool-Aid";
    std::string y = "Water";
    std::string temp;

    // // Troca de valores por passagem de VALOR
    // temp = x;
    // x = y;
    // y = temp;

    swap(x, y);

    std::cout << &x << '\n';
    std::cout << &y << '\n';

    std::cout << x << '\n';
    std::cout << y << '\n';

    return 0;
}

// Passagem por referencia, recebe o endereco das variaveis,
// assim ao inves de trabalhar com uma copia local, agora
// modifica realmente as variaveis.
void swap(std::string &x, std::string &y)
{
    std::string temp;
    temp = x;
    x = y;
    y = temp;

    std::cout << &x << '\n';
    std::cout << &y << '\n';
}