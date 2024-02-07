#include <iostream>

int main()
{
    // sizeof() = determinates the size in bytes of a:
    //            variable, data type, class, objects, etc.

    int age = 21;
    double price = 9.99;
    std::string name = "Eduardo";
    bool male = true;
    char YesorNo = 'Y';
    char grades[] = {'A', 'B', 'C', 'D', 'F'};

    std::cout << "int:\n";
    std::cout << sizeof(int) << " bytes\n";
    std::cout << sizeof(age) << " bytes\n\n";

    std::cout << "double:\n";
    std::cout << sizeof(double) << " bytes\n";
    std::cout << sizeof(price) << " bytes\n\n";

    std::cout << "string:\n";
    std::cout << sizeof(std::string) << " bytes\n";
    std::cout << sizeof(name) << " bytes\n\n";

    std::cout << "bool:\n";
    std::cout << sizeof(bool) << " bytes\n";
    std::cout << sizeof(male) << " bytes\n\n";

    std::cout << "char:\n";
    std::cout << sizeof(char) << " bytes\n";
    std::cout << sizeof(YesorNo) << " bytes\n\n";

    std::cout << "array of chars:\n";
    std::cout << sizeof(grades) << " bytes\n\n";

    // Useful to calculate the size of an array.
    std::cout << "each element in the array of chars:\n";
    std::cout << (sizeof(grades) / sizeof(char)) << " bytes\n";

    return 0;
}