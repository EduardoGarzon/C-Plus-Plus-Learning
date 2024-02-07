// Compara chamadas por valor e chamadas por referência

#include <iostream>

using namespace std;

int SquareByValue(int a) // a é passado por valor para esta função
{
    // alteracao apenas dentro da funcao, nao altera o argumento original
    return (a *= a); // O argumento passado não é modificado,
}

void SquareByReference(int &cRef) // O argumento é passado por referência
{
    // altera o argumento sem precisar de um return
    cRef *= cRef; // O argumento foi modificado!
    cout << "Dentro de SquareByReference: cRef = " << cRef << endl;
}

int main()
{
    int x = 2;
    int z = 4;

    cout << "x = " << x << " antes de SquareByValue.\n";
    cout << "Valor retornado por SquareByValue: " << SquareByValue(x) << endl;
    cout << "x = " << x << " depois de SquareByValue.\n"
         << endl;

    cout << "z = " << z << " antes de SquareByReference" << endl;
    SquareByReference(z);
    cout << "z = " << z << " depois de SquareByReference" << endl;

    return 0;
}
