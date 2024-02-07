#include <iostream>

int main()
{
    // dynamic memory = Memory that is allocated after the program
    //                  is already compiled & running.
    //                  Use the 'new' operator to allocate
    //                  memory in the heap rather than the stack.

    // Useful when we don't know how much memory
    // we will need. Makes our program more flexible,
    // especially when accepting user input.

    int *pNum = NULL; // null pointer created.
    pNum = new int;   // alocated an address for an int type.
    *pNum = 21;       // value.

    std::cout << "address: " << pNum << '\n';
    std::cout << "value: " << *pNum << '\n';

    delete pNum; // free memory.

    char *pGrades = NULL;
    int size;

    std::cout << "\n\n";
    std::cout << "Set the array size: ";
    std::cin >> size;

    for (int i = 0; i < size; i++)
    {
        pGrades[i] = i + 1;
    }

    for (int i = 0; i < size; i++)
    {
        std::cout << pGrades[i] << ' ';
    }

    pGrades = new char[size];

    delete[] pGrades;

    return 0;
}