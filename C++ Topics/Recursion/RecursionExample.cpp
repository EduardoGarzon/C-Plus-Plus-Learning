#include <iostream>

void walk(int steps);

int main()
{
    /*
        recursion = a programing technique where a function
                    invokes itself from within
                    break a complex concept into a repeatable single step.

        (iterative vs recursive)

        advatages = less code and is cleaner
                    useful for sorting and searching algorithms.

        disadvantages = uses more memory and is slower.
    */

    walk(10);

    return 0;
}

// iterative form.
// void walk(int steps)
// {
//     for (int i = 0; i < steps; i++)
//     {
//         std::cout << "You take a step!\n";
//     }
// }

void walk(int steps)
{
    if (steps > 0)
    {
        std::cout << "You take a step!\n";
        walk(steps - 1);
    }
}