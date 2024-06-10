/*
    Funcao recursiva que recebe um numero n e retorna a N-esima palavra de Fibonacci.

    Onde:
    F(n) = b se n = 0;
           a se n = 1;
           f(n - 1) + f (n - 2) se n > 1
*/

#include <iostream>

std::string fibonacciWord(int n)
{
    if (n == 0)
    {
        return "b";
    }
    else if (n == 1)
    {
        return "a";
    }
    else if (n > 1)
    {
        return fibonacciWord(n - 1) + fibonacciWord(n - 2);
    }
}

int main()
{
    int n = 0;
    std::string word;

    std::cout << "Informe uma valor inteiro para n: ";
    std::cin >> n;

    word = fibonacciWord(n);

    std::cout << "Palavra Fibonacci: " << word << std::endl;

    system("pause");
    return 0;
}