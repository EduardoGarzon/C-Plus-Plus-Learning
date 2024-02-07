#include <iostream>
#include <ctime>

char getUserChoice();
char getComputerChoice();
void showChoice(char choice);
void chooseWinner(char player, char computer);

int main()
{
    char player;
    char computer;

    player = getUserChoice();
    std::cout << "Your choice: ";
    showChoice(player);

    computer = getComputerChoice();
    std::cout << "Computer`s choice: ";
    showChoice(computer);

    chooseWinner(player, computer);

    return 0;
}

char getUserChoice()
{
    char player;
    std::cout << "ROCK-PAPER-SCISSORS GAME\n";

    do
    {
        std::cout << "\nChoose one of the following\n";
        std::cout << "***************************\n";
        std::cout << "'r' for rock.\n";
        std::cout << "'p' for paper.\n";
        std::cout << "'s' for scissors.\n";
        std::cin >> player;
        std::cout << '\n';

    } while (player != 'r' && player != 'p' && player != 's');

    return player;
}

char getComputerChoice()
{
    srand(time(NULL));
    int num = rand() % 3 + 1;

    switch (num)
    {
    case 1:
        return 'r';
    case 2:
        return 'p';
    case 3:
        return 's';
    default:
        std::cout << "Invalid computer choice!\n";
        break;
    }

    return 0;
}

void showChoice(char choice)
{
    switch (choice)
    {
    case 'r':
        std::cout << "ROCK!\n";
        break;
    case 'p':
        std::cout << "PAPER!\n";
        break;
    case 's':
        std::cout << "SCISSORS!\n";
        break;
    default:
        std::cout << "Invalid choice!\n";
        break;
    }
}

void chooseWinner(char player, char computer)
{
    switch (player)
    {
    case 'r':
        if (computer == 'r')
        {
            std::cout << "IT'S A TIE!\n";
        }
        else if (computer == 'p')
        {
            std::cout << "YOU LOSE!\n";
        }
        else
        {
            std::cout << "YOU WIN!\n";
        }
        break;
    case 'p':
        if (computer == 'r')
        {
            std::cout << "YOU WIN!\n";
        }
        else if (computer == 'p')
        {
            std::cout << "IT'S A TIE\n";
        }
        else
        {
            std::cout << "YOU LOSE!\n";
        }
        break;
    case 's':
        if (computer == 'r')
        {
            std::cout << "YOU LOSE!\n";
        }
        else if (computer == 'p')
        {
            std::cout << "YOU WIN!\n";
        }
        else
        {
            std::cout << "IT'S A TIE!\n";
        }
        break;
    default:
        std::cout << "Invalid Game!\n";
        break;
    }
}