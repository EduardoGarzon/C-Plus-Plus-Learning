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

    void Hello()
    {
        std::cout << "Hello!\n";
    }
};

class Student : public Human
{
private:
    char grade;

public:
    char getGrade()
    {
        return grade;
    }

    void setGrade(char grade)
    {
        this->grade = grade;
    }
};

int main()
{
    // inharitance = A class can recieve attributes and methods from another class.
    //               Children classes inherit from a Parent class.
    //               Helps to reuse similar code found within multiple classes.

    Student student;

    student.setName("Eduardo");
    student.setAge(21);

    student.setGrade('A');

    std::cout << student.getName() << '\n';
    std::cout << student.getAge() << '\n';
    std::cout << student.getGrade() << '\n';

    student.Hello();

    return 0;
}