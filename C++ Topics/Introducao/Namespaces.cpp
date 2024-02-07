#include <iostream>

namespace first
{
    int x = 1;
}

namespace second
{
    int x = 2;
}

int main()
{
    /*
        Namespace = provides a solution for preventing name conflicts
                    in large projects. Each entity needs a unique name.
                    A namespace allows for identically named entities
                    as long as the namespaces are different.
    */

    int x = 0;

    std::cout << x << '\n';         // Displays 0.
    std::cout << first::x << '\n';  // Displays 1.
    std::cout << second::x << '\n'; // Display 2.

    // // Nao precisamos mais utilizar o prefixo.
    // using namespace first;
    // std::cout << x << '\n'; // Displays 1;

    // Utilizar using namespace std pode gerar diversos conflitos
    // por conta de suas diversas palavras reservadas.
    // Uma solucao segura é utilizar o using std::keyword
    // para as funcoes que iremos utilizar.
    using std::cout;
    cout << "Hello!\n";

    return 0;
}