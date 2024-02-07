#include <iostream>

int main()
{
    std::string name;

    std::cout << "Enter your name: ";
    std::getline(std::cin, name);
    std::cout << std::endl;

    // Retorna um valor boolean que indica se a string esta vazia ou nao.
    if (!name.empty())
    {
        // Retorna a quantidade de caracteres da string.
        if (name.length() <= 12)
        {
            std::cout << "Welcome " << name << ". "
                      << "Your name`s length is: "
                      << name.length() << '\n';

            // Retorna a primeira posicao do caractere informado.
            std::cout << name.find(' ') << '\n';

            // Apaga n caracteres a partir da posicao informada.
            name.erase(0, 3);
            std::cout << "Your name after the eraser: " << name << '\n';

            // Insere um caractere na posicao indicada.
            name.insert(0, "!");
            std::cout << "Your name after insertion is: "
                      << name << '\n';

            // Concatena valores ao final da string.
            name.append("@gmail.com");
            std::cout << "Your username is now: " << name << '\n';

            // Retorna o caractere do indice informado.
            std::cout << "Caracter returned by name's index: "
                      << name.at(0) << '\n';

            // Limpa a variavel.
            name.clear();
            std::cout << "Name value after de cleaning: " << name;
        }
        else
        {
            std::cout << "Your name can`t be over 12 caracteres!\n";
        }
    }
    else
    {
        std::cout << "Your name can`t be empty!\n";
    }

    return 0;
}