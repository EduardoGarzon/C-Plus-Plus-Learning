#include <iostream>

class Human
{
private:
    std::string name;
    int age;

public:
    std::string getName()
    {
        return name;
    }

    int getAge()
    {
        return age;
    }

    void setName(std::string name)
    {
        this->name = name;
    }

    void setAge(int age)
    {
        this->age = age;
    }
};

int main()
{
    // Abstraction = hiding unnecessary data from outside a class.
    // getter = funciton that makes a private attribute READABLE.
    // setter = function that makes a private attribute WRITEABLE.

    Human human;

    human.setName("Eduardo");
    human.setAge(21);

    std::cout << human.getName() << '\n';
    std::cout << human.getAge() << '\n';

    return 0;
}