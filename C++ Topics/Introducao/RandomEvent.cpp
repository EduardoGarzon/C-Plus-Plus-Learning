#include <iostream>
#include <ctime>

int main()
{
    srand(time(0));
    int random = rand() % 5 + 1;

    switch (random)
    {
    case 1:
        std::cout << "You win R$50.00.\n";
        break;
    case 2:
        std::cout << "You win R$150.00.\n";
        break;
    case 3:
        std::cout << "You win R$250.00.\n";
        break;
    case 4:
        std::cout << "You win R$350.00.\n";
        break;
    case 5:
        std::cout << "You win R$450.00.\n";
        break;
    default:
        std::cout << "You win nothing.\n";
        break;
    }

    return 0;
}