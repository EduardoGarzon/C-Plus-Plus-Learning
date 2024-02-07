#include <iostream>

int main()
{
    // Null value = a special value that means something has no value.
    //              When a pointer is holding a null value,
    //              that pointer is not pointing at anything (null pointer).

    // nullptr = keyword represents a null pointer literal.

    // nullptrs are helpful when determinig if an address
    // was successfuly assigned to a pointer.

    int *pointer = nullptr;
    int x = 123;

    pointer = &x;

    if (pointer == nullptr)
    {
        std::cout << "Address was not assigned!\n";
    }
    else
    {
        std::cout << "Address was assigned!\n";
        std::cout << *pointer << '\n';
    }

    return 0;
}