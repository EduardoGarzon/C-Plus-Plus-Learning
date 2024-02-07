#include <iostream>

int main()
{
    // Executa o bloco enquanto a condicao for verdadeira.
    // Executa -> Checagem -> Executa -> Checagem...

    int x = 0, y = 0;
    for (int i = 0; i < 2; i++)
    {
        std::cout << "For " << i << ":\n";
        while (x <= 2)
        {
            std::cout << "\tWhile " << x << ":\n";
            x++;
            do
            {
                std::cout << "\t\tDoWhile " << y << ".\n";
                y++;
            } while (y <= 2);
            y = 0;
        }
        x = 0;
    }

    return 0;
}