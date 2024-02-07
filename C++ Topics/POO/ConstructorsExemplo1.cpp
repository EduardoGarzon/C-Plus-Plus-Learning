#include <iostream>

class Student
{
public:
    std::string name;
    int age;

    // If the parameters are differet from the class atributes names,
    // you don't need to use 'this'.
    Student(std::string name, int age)
    {
        this->name = name;
        this->age = age;
    }

    Student()
    {
        name = "Default";
        age = 0;
    }
};

int main()
{
    // constructor = special method that is automatically called when
    //               is instantiated, useful for assigning values to
    //               attributes as arguments.

    Student student("Eduardo", 21);
    Student student2;

    std::cout << student.name << " " << student.age << '\n';
    std::cout << student2.name << " " << student2.age << '\n';

    return 0;
}