#include <iostream>

// Boa prática utilizar _t para referenciar o typedef.
typedef std::string name_t;

// Alternativa mais utilizada
using age_t = int;

int main()
{
    /*
        typedef = reserved keyword used to create an additional name
                  (alias) for another data type.
                  New identifies for an existing type.
                  Helps with readability and reduces typos.
                  Use when there is a clear benefit.
                  Replaced with 'using' (work better w/ templates).
    */

    // Ao inves de utilizar std::string utilizamos o alias.
    name_t name = "Luiz Eduardo";

    age_t age = 21;

    std::cout << name << std::endl;
    std::cout << age << std::endl;

    return 0;
}