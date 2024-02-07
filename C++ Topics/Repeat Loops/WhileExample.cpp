#include <iostream>

int main()
{
    // Enquanto algo for verdadeiro repita o processo.
    // Checagem -> Executa -> Checagem -> Executa...

    std::string name;

    while (name.empty())
    {
        std::cout << "Enter your name: ";
        std::getline(std::cin, name);
    }

    std::cout << "Hello " << name << '\n';

    return 0;
}