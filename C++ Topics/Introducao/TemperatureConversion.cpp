#include <iostream>

int main()
{
    double temp;
    char unit;

    std::cout << "********** Temperature Conversion **********\n";
    std::cout << "F = Fahrenheit\n";
    std::cout << "C = Celsius\n";
    std::cout << "********************************************\n\n";

    std::cout << "Type value and unit (ex:40 C): ";
    std::cin >> temp >> unit;

    std::cout << "\n********************************************\n";

    if (unit == 'F' || unit == 'f')
    {
        std::cout << temp << " Fahrenheit is: "
                  << ((temp - 32) / 1.8) << " Celsius\n";
    }
    else if (unit == 'C' || unit == 'c')
    {
        std::cout << temp << " Celsius is: "
                  << ((1.8 * temp) + 32.0) << " Fahrenheit\n";
    }
    else
    {
        std::cout << "Invalid input!\n";
    }

    std::cout << "********************************************\n";

    return 0;
}