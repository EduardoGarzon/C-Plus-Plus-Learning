#include <iostream>
#include <ctime>

int main()
{
    // pseudo-random = NOT truly random (but close);

    srand(time(NULL));

    // Intervalo de 1 ate 10.
    int num = (rand() % 10) - 1;

    std::cout << "Random Number: " << num << '\n';

    return 0;
}