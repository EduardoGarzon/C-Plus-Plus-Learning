/*
    Passagem de argumentos pelo terminal utilizando argc e argv.
*/

#include <iostream>

using namespace std;

int main(int argc, const char *argv[])
{
    // argc -> Numeros de Argumentos
    // argv -> Argumentos
    cout << "Numero de argumentos: " << argc << endl;
    for (int i = 0; i < argc; i++)
    {
        cout << "Argumento " << i << ": " << argv[i] << endl;
    }

    return 0;
}