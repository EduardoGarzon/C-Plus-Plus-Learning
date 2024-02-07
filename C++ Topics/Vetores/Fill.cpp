#include <iostream>

int main()
{
    // fill() = Fills a rage of element with a specified value
    //          fill(begin, end, value);

    const int SIZE = 10;
    std::string foods[SIZE];

    // fill(foods, foods + SIZE, "pizza");
    // fill(foods + (SIZE/2), foods + SIZE, "hamburguer");

    fill(foods, foods + (SIZE / 3), "pizza");
    fill(foods + (SIZE / 3), foods + (SIZE / 3) * 2, "hamburguer");
    fill(foods + (SIZE / 3) * 2, foods + SIZE, "hotdogs");

    for (std::string food : foods)
    {
        std::cout << food << '\n';
    }

    return 0;
}