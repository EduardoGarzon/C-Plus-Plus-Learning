// Exemplifica o uso de funções friends que são membros de outras classes
// Funcoes definidas em outras classes que tem acesso aos 
// membros privados e protegidos da classe onde sao declaradas como friends, 
// assim podemos implementar operacoes entre as classes
// Caixa ----> Friend ---> Funcionario

#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

// Defini��es de classes
class Funcionario; // prot�tipo da classe

class Caixa
{
private:
    double disponivel;
    double folha;

public:
    Caixa();
    void fechamento(Funcionario *empregados, unsigned total);
};

class Funcionario
{
private:
    char nome[41];
    double salario;

public:
    Funcionario();
    // Declara uma função fechamento como uma amiga (friend) da classe Caixa.
    // A função fechamento é considerada um membro da classe Caixa e pode acessar membros privados da classe.
    // Caixa tem acesso a Funcionario
    friend void Caixa::fechamento(Funcionario *empregados, unsigned total);
};

// Declara��o dos m�todos da classe Funcionario
Funcionario::Funcionario()
{
    cin.get();
    cout << "\tNome\t:";
    cin.get(nome, 40);
    cout << "\tSalario\t: ";
    cin >> salario;
    cout << endl;
}

// Declara��o dos m�todos da classe Caixa
Caixa::Caixa()
{
    cout << "\tDisponivel em caixa\t:";
    cin >> disponivel;
    folha = 0;
}

// Operacoes com ambas as classes
void Caixa::fechamento(Funcionario *empregados, unsigned total)
{
    for (int i = 0; i < total; i++)
        folha += empregados[i].salario;
    cout << endl
         << "\nResultados da empresa:\n"
         << endl
         << "\n\tDisponivel\t: " << disponivel
         << "\n\tFolha\t\t: " << folha
         << "\n\tSaldo\t\t: " << (disponivel - folha) << endl;
}

// Declara��o das vari�veis globais
char empresa[51];
unsigned total;

// Defini��o de fun��es n�o-membros de classe
Funcionario *entrada()
{
    cout << endl
         << "\nDados da Empresa \n\tNome da Empresa: ";
    cin.get();
    cin.get(empresa, 50);
    cout << "Total de funcionarios: ";
    cin >> total;
    Funcionario *empregados = new Funcionario[total]; // aloca os funcionários
    return empregados;
}

// Fun��o principal
int main()
{
    Funcionario *empregados = entrada();
    Caixa firma;
    firma.fechamento(empregados, total);
    cout << "\n\n\n";
    delete[] empregados; // desaloca os funcionarios

    system("pause");

    return 0;
}
