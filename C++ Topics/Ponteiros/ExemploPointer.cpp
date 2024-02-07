#include <iostream>

int main()
{
    // pointers = variable that stores a memory address of
    //            another variable, sometimes it's easier to work
    //            with an address.

    // & address-of operator
    // * dereference operator

    std::string name = "Luiz";
    std::string freePizzas[3] = {"Pizza1", "Pizza2", "Pizza3"};

    std::string *pName = &name;

    // // The & is not necessary because the array is alredy a pointer.
    // std::string *pFreePizzas = &freePizzas;

    std::string *pFreePizzas = freePizzas;

    std::cout << pName << '\n';  // Address storaged.
    std::cout << *pName << '\n'; // Value of the address storage.

    std::cout << pFreePizzas << '\n';  // Address storaged.
    std::cout << *pFreePizzas << '\n'; // Value of the address storage.

    return 0;
}