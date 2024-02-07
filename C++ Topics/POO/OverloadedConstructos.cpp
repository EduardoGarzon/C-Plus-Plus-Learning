#include <iostream>

class Student
{
public:
    std::string name;
    int age;
    std::string gender;

    // Default.
    Student()
    {
        name = "Unsigned";
        age = 0;
        gender = "Unsigned";
    }

    // If the parameters are differet from the class atributes names,
    // you don't need to use 'this'.
    Student(std::string name, int age)
    {
        this->name = name;
        this->age = age;
    }

    Student(std::string name, int age, std::string gender)
    {
        this->name = name;
        this->age = age;
        this->gender = gender;
    }
};

int main()
{
    // overloaded constructor = multiple constructos w/ same name but different
    //                          parameters, allows for varying arguments when
    //                          instantiating an object.

    Student student("Eduardo", 21);
    Student student2;
    Student student3("Eduardo", 21, "Male");

    std::cout << student.name << " " << student.age << '\n';
    std::cout << student2.name << " " << student2.age << '\n';
    std::cout << student3.name << " " << student3.age << " " << student3.gender << '\n';

    return 0;
}