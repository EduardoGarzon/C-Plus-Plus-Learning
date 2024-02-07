#include <iostream>

int main()
{
    // break = break out of a loop.
    // continue = skip current iteration.

    int i;
    for (i = 0; i <= 10; i++)
    {
        if (i == 5)
        {
            continue;
        }

        if (i == 10)
        {
            break;
        }

        std::cout << i << '\n';
    }

    std::cout << "Value after loop: " << i << '\n';

    return 0;
}