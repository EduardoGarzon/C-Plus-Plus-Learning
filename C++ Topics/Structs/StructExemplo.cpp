#include <iostream>

struct student
{
    std::string name;
    int age;
};

int main()
{
    /*
        struct = a struct that group related variables under one name.
                 Structs can contain many different data types.
                 Variables in a struct are known as "members".
                 Members can be access with . "Class Member Access Operator".
    */

    student student1;

    student1.name = "Luiz Eduardo";
    student1.age = 21;

    std::cout << student1.name << '\n';
    std::cout << student1.age << '\n';

    return 0;
}