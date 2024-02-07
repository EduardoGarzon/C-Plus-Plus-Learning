// demonstra struct e construtor.

#include <iostream>
#include <string>

using namespace std;

struct Human
{
    Human()
    {
        this->nome = "undefined";
        this->idade = 0;
        this->altura = 0.0;
        this->peso = 0.0;
    }

    Human(int i)
    {
        if (i == 1)
        {
            this->nome = "Human";
            this->idade = 21;
            this->altura = 1.75;
            this->peso = 80.0;
        }
    }

    string nome;
    int idade;
    float altura;
    float peso;
};

int main(int argc, const char *argv[])
{
    Human me;

    cout << "Human Constructor:\n";
    cout << "Nome: " << me.nome << endl;
    cout << "Idade: " << me.idade << endl;
    cout << "Altura: " << me.altura << endl;
    cout << "Peso: " << me.peso << "\n"
         << endl;

    Human me2(1);

    cout << "Human Padrao:\n";
    cout << "Nome: " << me2.nome << endl;
    cout << "Idade: " << me2.idade << endl;
    cout << "Altura: " << me2.altura << endl;
    cout << "Peso: " << me2.peso << "\n"
         << endl;

    me.nome = "Luiz";
    me.idade = 21;
    me.altura = 1.75;
    me.peso = 85.0;

    cout << "Human Defined:\n";
    cout << "Nome: " << me.nome << endl;
    cout << "Idade: " << me.idade << endl;
    cout << "Altura: " << me.altura << endl;
    cout << "Peso: " << me.peso << endl;

    return 0;
}