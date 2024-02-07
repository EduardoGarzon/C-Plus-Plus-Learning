#include <iostream>

int global = 20;

void printLocal(int l);
void printGlobal();

int main()
{
    // local variables = declared inside a function or block {}.
    // global variables = declared outside of all funcitons.

    int local = 10, global = 30;
    printLocal(local);
    printGlobal();

    // Garante o uso da variavel global e nao a variavel
    // de mesmo nome dentro da funcao.
    std::cout << ::global << '\n'; 

    return 0;
}

void printLocal(int l)
{
    std::cout << l << '\n';
}

void printGlobal() {
    std::cout << global << '\n';
}
