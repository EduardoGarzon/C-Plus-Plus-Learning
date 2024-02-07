#include <iostream>
#include <ctime>

int main()
{
    int num, guess, tries;

    srand(time(NULL));
    num = (rand() % 100) + 1;

    std::cout << "********** NUMBER GUESSING GAME **********\n";

    do
    {
        std::cout << "Enter a guess between (1-100): ";
        std::cin >> guess;
        tries++;

        if (guess > num)
        {
            std::cout << "\nToo High!\n";
        }
        else if (guess < num)
        {
            std::cout << "\nToo Low!\n";
        }
        else
        {
            std::cout << "\nTHAT IS CORRECT!\n";
        }

        std::cout << std::endl;

    } while (guess != num);

    std::cout << "Number of tries: " << tries << '\n';

    return 0;
}