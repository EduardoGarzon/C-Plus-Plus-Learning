#include <iostream>

// T -> Thing, accepts onlu the same data types.
template <typename T>
T max(T x, T y)
{
    return (x > y) ? x : y;
}

// Accepts differents data types.
// The auto automatically return the type acording to the rule programed.
template <typename T, typename U>
auto min(T x, U y)
{
    return (x < y) ? x : y;
}

int main()
{
    /*
        function template = describes what a function looks like.
                            Can be used to generate as many overloaded
                            funcitons as needed, each using different data types.
    */

    // They are the same data type.
    std::cout << max(1, 2) << '\n';
    std::cout << max(2.5, 2.9) << '\n';
    std::cout << max("luiz", "Eduardo") << '\n';
    std::cout << max('a', 'b') << "\n\n";

    std::cout << min(1.1, 10) << '\n';
    std::cout << min(10, 5.1) << '\n';


    return 0;
}