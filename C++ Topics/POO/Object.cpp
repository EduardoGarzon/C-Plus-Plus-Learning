#include <iostream>

class Human
{
public:
    std::string name;
    std::string occupation;
    int age;

    void eat()
    {
        std::cout << "THIS PERSON IS EATING.\n";
    }

    void drink()
    {
        std::cout << "THIS PERSON IS DRINKING.\n";
    }
};

int main()
{
    /*
        object = A collection of attributes and methods.
                 They can have characteristics and could perform actions.
                 Can be used to mimic real world items (ex. Phone, Book, etc.).
                 Created from class which acts as a "blue-print"
    */

    Human human1;

    human1.name = "Eduardo";
    human1.occupation = "Scientist";
    human1.age = 60;

    std::cout << human1.name << '\n';
    std::cout << human1.occupation << '\n';
    std::cout << human1.age << '\n';

    human1.eat();
    human1.drink();

    return 0;
}