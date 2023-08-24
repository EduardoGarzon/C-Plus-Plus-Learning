// Exemplifica a criação de uma classe simples

// Inclusão das bibliotecas
#include <iostream>
#include <string.h>
#include <string>

using namespace std;

// Definição da classe Pessoa
class Pessoa
{
private:
    int RG;
    int CPF;
    char Nome[31];
    char Endereco[41];
    char Telefone[13];

public:
    Pessoa();          // Construtor default definido pelo programador
    Pessoa(Pessoa &P); // Construtor de cópia
    int getRG();
    int getCPF();
    char *getNome();
    char *getEndereco();
    char *getTelefone();
    void setRG();
    void setCPF();
    void setNome();
    void setEndereco();
    void setTelefone();
};

// Declaração das funções da classe
Pessoa::Pessoa() // Construtor default
{
    cout << "\nExecutando construtor\n";
    RG = 0;
    CPF = 0;
    strcpy(Nome, "");
    strcpy(Endereco, "");
    strcpy(Telefone, "");
}

Pessoa::Pessoa(Pessoa &P) // Construtor de cópia
{
    RG = P.getRG();
    CPF = P.getCPF();
    strcpy(Nome, P.getNome());
    strcpy(Endereco, P.getEndereco());
    strcpy(Telefone, P.getTelefone());
}

int Pessoa::getRG()
{
    return (RG);
}

int Pessoa::getCPF()
{
    return (CPF);
}

char *Pessoa::getNome()
{
    return (Nome);
}

char *Pessoa::getEndereco()
{
    return (Endereco);
}

char *Pessoa::getTelefone()
{
    return (Telefone);
}

void Pessoa::setRG()
{
    cout << "Numero do RG?..>";
    cin >> RG;
}

void Pessoa::setCPF()
{
    cout << "Numero do CPF?.>";
    cin >> CPF;
}

void Pessoa::setNome()
{
    cin.get(); // limpa o buffer
    cout << "Nome?..........>";
    cin.get(Nome, 31);
}

void Pessoa::setEndereco()
{
    cin.get(); // limpa o buffer
    cout << "Endereço?......>";
    cin.get(Endereco, 41);
}
void Pessoa::setTelefone()
{
    cin.get(); // limpa o buffer
    cout << "Telefone?......>";
    cin.get(Telefone, 13);
}

// Programa principal
int main()
{
    const int MAX = 4; // define o tamanho da turma
    // Declaração das variáveis tipo Pessoa
    Pessoa Turma[MAX];

    // Utilizando os objetos
    for (int i = 0; i < MAX; i++)
    {
        cout << endl
             << "Entre com os dados da Pessoa " << i << ":\n";
        Turma[i].setRG();
        Turma[i].setCPF();
        Turma[i].setNome();
        Turma[i].setEndereco();
        Turma[i].setTelefone();
    }

    // Listando as pessoas da turma
    for (int i = 0; i < MAX; i++)
    {
        cout << endl
             << "Pessoa " << i << ": " << endl
             << "RG......: " << Turma[i].getRG() << endl
             << "CPF.....: " << Turma[i].getCPF() << endl
             << "Nome....: " << Turma[i].getNome() << endl
             << "Endereco: " << Turma[i].getEndereco() << endl
             << "Telefone: " << Turma[i].getTelefone() << endl
             << endl;
    }

    system("pause");
    
    return 0;
}
