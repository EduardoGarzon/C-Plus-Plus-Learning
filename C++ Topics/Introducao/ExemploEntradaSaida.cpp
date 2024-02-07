// Demonstra comandos de entrada e saída Em C++ com cin, cout e getline.

#include <iostream>
#include <string>

int main()
{
    std::string name;

    // Utiliza o objeto cout para dar saída no vídeo.
    std::cout << "Qual o seu primeiro nome? : ";
    std::cin >> name; // cin não lê strings com espaços em branco.
    std::cin.get();   // Limpa o buffer.

    std::cout << std::endl;
    std::cout << "Hello " << name << "!\n\n";

    std::cout << "Qual o seu nome completo? : ";
    std::getline(std::cin >> std::ws, name); // ws desconsidera white spaces e \n

    // Podemos usar o delimitador para marcar o fim da linha
    // std::getline(std::cin, name, ';');
    // std::cin.get(nome, 20);

    std::cout << std::endl;
    std::cout << "Hello again " << name << "!\n\n";

    return 0;
}
