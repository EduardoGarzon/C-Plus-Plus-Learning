#include <iostream>

enum Day
{
    sunday = 0,
    monday = 1,
    tuesday = 2,
    wednesday = 3,
    thursday = 4,
    friday = 5,
    saturday = 6
};

int main()
{
    /*
        enums = a user-defined data type that consists
                of paired named-integer constants.
                GREAT it you have a set of potential options.
    */

    Day today = sunday;
    Day anotherDay = saturday;

    if (today == sunday)
    {
        std::cout << "IT'S SUNDAY!\n";
    }

    if (anotherDay == 6)
    {
        std::cout << "IT'S SATURDAY\n";
    }

    return 0;
}