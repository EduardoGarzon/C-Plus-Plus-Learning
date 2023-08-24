// Exemplifica a criação de uma classe simples

// Inclusão das bibliotecas
#include <iostream>
#include <string>
#include <string.h>

// declaração que permite que você acesse nomes do namespace std sem precisar digitar o prefixo std::
using namespace std;

// Definição da classe Pessoa
class Pessoa
{
    // membros privados, acessiveis somente por funcoes membro da mesma classe
private:
    // atributos: caracteristicas e dados
    int RG;
    int CPF;
    char Nome[31];
    char Endereco[41];
    char Telefone[13];
    // membros publicos, acessados por qualquer parte do codigo que acessa o objeto da classe
public:
    Pessoa();          // Construtor default definido pelo programador
    Pessoa(Pessoa &P); // Construtor de cópia

    // getters e setters são métodos usados para acessar e modificar atributos privados de uma classe.
    int getRG();
    int getCPF();
    // o uso de um ponteiro em um método getter permite que um objeto retorne um valor de dados dinâmico e flexível, em vez de um valor estático.
    char *getNome();
    char *getEndereco();
    char *getTelefone();

    void setRG();
    void setCPF();
    void setNome();
    void setEndereco();
    void setTelefone();
};

// Pessoa:: indica que a funcao é um membro da classe

// Declaração das funções da classe
Pessoa::Pessoa() // Construtor default
{
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

// metodos getters, acessar os dados

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

// metodos setters, modificar valores dos atributos

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
    cout << "Endereco?......>";
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
    // Declaração das variáveis tipo Pessoa
    Pessoa A, B;

    // Utilizando os objetos com setters
    cout << endl
         << "Entre com os dados da Pessoa A:\n";
    A.setRG();
    A.setCPF();
    A.setNome();
    A.setEndereco();
    A.setTelefone();

    cout << endl
         << "Entre com os dados da Pessoa B:\n";
    B.setRG();
    B.setCPF();
    B.setNome();
    B.setEndereco();
    B.setTelefone();

    // construtor cópia
    Pessoa C = B;

    // Utilizando os objetos com getters
    cout << endl
         << "Pessoa A: " << endl
         << "RG......: " << A.getRG() << endl
         << "CPF.....: " << A.getCPF() << endl
         << "Nome....: " << A.getNome() << endl
         << "Endereco: " << A.getEndereco() << endl
         << "Telefone: " << A.getTelefone() << endl
         << endl;

    cout << endl
         << "Pessoa B: " << endl
         << "RG......: " << B.getRG() << endl
         << "CPF.....: " << B.getCPF() << endl
         << "Nome....: " << B.getNome() << endl
         << "Endereco: " << B.getEndereco() << endl
         << "Telefone: " << B.getTelefone() << endl
         << endl;

    cout << endl
         << "Pessoa C: (copia de B)" << endl
         << "RG......: " << C.getRG() << endl
         << "CPF.....: " << C.getCPF() << endl
         << "Nome....: " << C.getNome() << endl
         << "Endereco: " << C.getEndereco() << endl
         << "Telefone: " << C.getTelefone() << endl
         << endl;

    system("pause");

    return 0;
}
