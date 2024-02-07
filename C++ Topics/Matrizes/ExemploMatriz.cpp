#include <iostream>

int main()
{
    // FORD, CHEVROLET, DODGE
    std::string cars[][3] = {{"Mustang", "Escape", "F-150"},
                             {"Corvette", "Equinox", "Silverado"},
                             {"Challenger", "Durango", "RAM 1500"}};

    int rows = sizeof(cars) / sizeof(cars[0]);
    int columns = sizeof(cars[0]) / sizeof(cars[0][0]);

    std::cout << cars[0][0] << "\n\n";

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            std::cout << cars[i][j] << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}