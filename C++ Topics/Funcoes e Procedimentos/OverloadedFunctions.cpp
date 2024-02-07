#include <iostream>

void bakePizza(std::string ingrediente1);
void bakePizza(std::string ingrediente1, std::string ingrediente2);
void bakePizza(std::string ingrediente1, std::string ingrediente2, std::string ingrediente3);

int main()
{
    bakePizza("Tomato");
    bakePizza("Tomato", "Onions");
    bakePizza("Tomato", "Onions", "Bacon");

    return 0;
}

void bakePizza(std::string ingrediente1)
{
    std::cout << "Here is your pizza with " << ingrediente1 << "!\n";
}

void bakePizza(std::string ingrediente1, std::string ingrediente2)
{
    std::cout << "Here is your pizza with " << ingrediente1 << " and " << ingrediente2 << "!\n";
}

void bakePizza(std::string ingrediente1, std::string ingrediente2, std::string ingrediente3)
{
    std::cout << "Here is your pizza with " << ingrediente1 << ", " << ingrediente2
              << " and " << ingrediente3 << "!\n";
}
