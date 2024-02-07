#include <iostream>

int main()
{
    // Executa um bloco em uma quantidade especifica de tempo.
    // A primeira execucao nao ocorre incremento.
    // Executa -> Incrementa e Avalia -> Executa -> Incrementa e Avalia...

    int i;
    for (i = 0; i <= 10; i++)
    {
        std::cout << i << '\n';
    }

    std::cout << "Value after loop: " << i << '\n';

    return 0;
}