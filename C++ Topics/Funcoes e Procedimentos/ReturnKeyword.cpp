#include <iostream>

double square(double lenght);
double cube(double lenght);

int main()
{
    // return = return a value back to the spot
    //          where you called the encompassing funciton.

    double lenght = 5.0;
    double area = square(lenght);
    double volume = cube(lenght);

    std::cout << "The area is: " << area << 'cm^2\n';
    std::cout << "The cube is: " << volume << 'cm^3\n';

    return 0;
}

double square(double lenght)
{
    return lenght * lenght;
}

double cube(double lenght)
{
    return lenght * lenght * lenght;
}