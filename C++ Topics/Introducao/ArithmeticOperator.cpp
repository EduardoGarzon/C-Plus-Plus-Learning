#include <iostream>

int main()
{
    /*
        Arithmetic Operators = return the result of a specific
                               arithmetic operation (+ - * /).

        Ordem das operacoes: 1. Parenteses.
                             2. Multiplicacao e Divisao.
                             3. Adicao e Subtracao.
    */

    int students = 20;

    // SOMA -----------------------------------------------------------

    // students += 1;
    // students++;
    students = students + 1;
    std::cout << students << '\n';

    // SUBTRACAO -------------------------------------------------------

    // students -= 1;
    // students--;
    students = students - 1;
    std::cout << students << '\n';

    // MULTIPLICACAO ----------------------------------------------------

    // students *= 2;
    students = students * 2;
    std::cout << students << '\n';

    // DIVISAO ----------------------------------------------------------
    // Retorna somente a parte inteira para int.
    // Retorna todo o valor da divisao para double.

    // students /= 2;
    students = students / 2;
    std::cout << students << '\n';

    // RESTO DA DIVISAO --------------------------------------------------
    double otherStudents = 20;
    int remainder = (int)otherStudents % 3;
    std::cout << remainder << '\n';

    return 0;
}