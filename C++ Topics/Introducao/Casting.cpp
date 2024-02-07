/*
    Conversores de tipos (casting).
*/

#include <iostream>

int main(int argc, const char *argv[])
{
    // type conversion: conversion a value of one data type to another.
    //                  Implicit = automatic.
    //                  Explicit = Precede value with new data type (int).

    int A = 10, B;
    double C = 20.55, D;

    // Casting em C
    B = (int)C;
    std::cout << B << '\n'; // Displays 20.

    // Casting em C++, forma de funcao
    D = int(C);
    std::cout << D << '\n'; // Displays 20.

    B = double(C);
    std::cout << B << '\n'; // Displays 20.

    D = double(A);
    std::cout << D << '\n'; // Displays 10

    std::cout << (char) 100 << '\n'; // Displays ASCII d.

    return 0;
}