#include <iostream>

// O protótipo da funcao evita erros na passagem de parametros.
void happyBirthDay(std::string name);

int main()
{
    // function = A block of reusable code.

    std::string name = "Luiz Eduardo";

    happyBirthDay(name);

    return 0;
}

void happyBirthDay(std::string name)
{
    std::cout << "HAPPY BITHDAY TO " + name + "!\n";
}
