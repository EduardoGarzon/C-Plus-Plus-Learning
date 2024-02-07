#include <iostream>

struct car
{
    std::string model;
    int year;
    std::string color;
};

void printCar(car &car);

int main()
{
    car cars[2];

    cars[0].model = "Mustang";
    cars[0].year = 2024;
    cars[0].color = "Blue";

    cars[1].model = "Corvette";
    cars[1].year = 2024;
    cars[1].color = "Red";

    // printCar(cars[0]); // pass by value, receives a copy.
    printCar(cars[1]); // pass the reference.

    return 0;
}

void printCar(car &car)
{
    std::cout << car.model << " | " << car.year << " | " << car.color << '\n';
}