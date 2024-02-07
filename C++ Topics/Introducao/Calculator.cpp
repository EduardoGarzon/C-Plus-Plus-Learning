#include <iostream>

int main()
{
    char op;
    double num1;
    double num2;
    double result;

    std::cout << "********** CALCULATOR **********\n";

    std::cout << "Enter either (+ - * /): ";
    std::cin >> op;

    std::cout << "Enter num1 and num2: ";
    std::cin >> num1 >> num2;

    std::cout << "********************************\n";

    std::cout << "\n********************************\n";
    switch (op)
    {
    case '+':
        result = num1 + num2;
        std::cout << "Result of " << op << " between "
                  << num1 << " and " << num2 << " is " << result << '\n';
        break;
    case '-':
        result = num1 - num2;
        std::cout << "Result of " << op << " between "
                  << num1 << " and " << num2 << " is " << result << '\n';
        break;
    case '*':
        result = num1 * num2;
        std::cout << "Result of " << op << " between "
                  << num1 << " and " << num2 << " is " << result << '\n';
        break;
    case '/':
        result = num1 / num2;
        std::cout << "Result of " << op << " between "
                  << num1 << " and " << num2 << " is " << result << '\n';
        break;
    default:
        std::cout << "Invalid Operation!\n";
    }
    std::cout << "********************************\n";

    return 0;
}