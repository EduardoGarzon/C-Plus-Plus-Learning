/*
    Boas vindas ao usuario
*/

#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char *argv[])
{
    string nome = "";
    char nome2[] = {"Luiz Eduardo"};

    cout << "Ola, qual seu nome?\n";
    cin >> nome;

    cout << "Tipo string:" << endl;
    cout << "Boas vindas " + nome << endl;
    cout << "Boas vindas " << nome << endl;
    // printf("Boas vindas %s\n", nome);       // Nao funciona

    printf("\n");

    cout << "Vetor char:" << endl;
    // cout << "Boas vindas " + nome2 << endl; // Nao funciona
    cout << "Boas vindas " << nome2 << endl;
    printf("Boas vindas %s\n", nome2);

    system("pause");

    return 0;
}