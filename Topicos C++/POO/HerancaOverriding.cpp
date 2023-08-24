// Exemplo de Substituicao ou Sobrescrita de metodos na heranca em C++
/*
classes derivadas modificam métodos que são herdados das classes bases
para introduzir alterações na sua forma de funcionamento,
sem no entanto alterar a sua interface
*/

// Bibliotecas
#include <string>
#include <iostream>
#include <string.h>

using namespace std;

// Decalara��o de classes

// A classe pessoa � a classe-base (ou classe m�e)
// da qual outra ser� derivada
class Pessoa
{
protected:
    int RG;
    int CPF;
    char Nome[31];
    char Endereco[41];
    char Telefone[13];

public:
    Pessoa();          // Construtor default definido pelo programador
    Pessoa(Pessoa &P); // Construtor de c�pia
    ~Pessoa();         // destrutor da classe Pessoa
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

class Aluno : public Pessoa // Heran�a
{
private:
    char Instituicao[31];
    char RA[11];
    char Curso[31];

public:
    Aluno();         // Construtor default para a classe aluno
    Aluno(Aluno &A); // Construtor de c�pia para a classe aluno
    ~Aluno();        // Destruidor da classe aluno
    char *getNome();
    char *getInstituicao();
    char *getRA();
    char *getCurso();
    void setInstituicao();
    void setRA();
    void setCurso();
};

// Declara��o das fun��es da classe Pessoa
Pessoa::Pessoa() // Construtor default
{
    cout << "\nConstrutor default inicializando um objeto do tipo Pessoa ...\n";
    RG = 0;
    CPF = 0;
    strcpy(Nome, "");
    strcpy(Endereco, "");
    strcpy(Telefone, "");
    cout << "\nInicializacao concluida!\n";
}

Pessoa::Pessoa(Pessoa &P) // Construtor de c�pia
{
    cout << "\nConstrutor de copia inicializando um objeto do tipo pessoa...\n";
    RG = P.getRG();
    CPF = P.getCPF();
    strcpy(Nome, P.getNome());
    strcpy(Endereco, P.getEndereco());
    strcpy(Telefone, P.getTelefone());
    cout << "\nInicializacao concluida!\n";
}

Pessoa::~Pessoa() // Destruidor da classe pessoa
{
    cout << "\nObjeto do tipo Pessoa destruido! \n";
}

// getters setters Pessoa
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
    cout << "Numero do RG?\t> ";
    cin >> RG;
}

void Pessoa::setCPF()
{
    cout << "Numero do CPF?\t> ";
    cin >> CPF;
}

void Pessoa::setNome()
{
    cin.get(); // limpa o buffer
    cout << "Nome?\t\t> ";
    cin.get(Nome, 30);
}

void Pessoa::setEndereco()
{
    cin.get(); // limpa o buffer
    cout << "Endereco?\t> ";
    cin.get(Endereco, 40);
}

void Pessoa::setTelefone()
{
    cin.get(); // limpa o buffer
    cout << "Telefone?\t> ";
    cin.get(Telefone, 12);
}

Aluno::Aluno()
{ // defini��o do construtor default para a classe aluno;
    // O construtor default da classe base � chamado implicitamente
    cout << "Construtor default da classe aluno inicializando um objeto "
         << "do tipo aluno...\n";
    strcpy(Instituicao, "");
    strcpy(RA, "");
    strcpy(Curso, "");
    cout << "\nInicializacao concluida!\n";
}

Aluno::~Aluno()
{
    cout << "\nObjeto do tipo aluno destruido!\n";
}

// A função Overriding deve combinar em tipo de retorno, 
// nome e lista de parâmetros com a função antecessora na classe base.
// O método getNome() retorna um ponteiro para um char (char*) que contém o nome do aluno.
char *Aluno::getNome()
{ // sobrescrevendo o m�todo da classe base
    cout << "\nDentro do metodo sobrescrito getNome da classe Aluno\n";
    return (Nome);
}

char *Aluno::getInstituicao()
{
    return Instituicao;
}

char *Aluno::getRA()
{
    return RA;
}

char *Aluno::getCurso()
{
    return Curso;
}

void Aluno::setInstituicao()
{
    cin.get(); // limpa o buffer
    cout << "Instituicao?\t> ";
    cin.get(Instituicao, 30);
}

void Aluno::setRA()
{
    cin.get(); // limpa o buffer
    cout << "RA?\t\t> ";
    cin.get(RA, 10);
}

void Aluno::setCurso()
{
    cin.get(); // limpa o buffer
    cout << "Curso?\t\t> ";
    cin.get(Curso, 30);
}

int main()
{
    const int N = 2;
    Aluno turma[N]; // declara um vetor de N alunos
    cout << "\nLendo os dados dos alunos da turma: \n";
    for (int i = 0; i < N; i++)
    {
        cout << "\nDados para o aluno " << i << ":\n";
        turma[i].setRG();
        turma[i].setCPF();
        turma[i].setNome();
        turma[i].setEndereco();
        turma[i].setTelefone();
        turma[i].setInstituicao();
        turma[i].setRA();
        turma[i].setCurso();
    }
    cout << "\nEscrevendo os dados lidos: \n";
    for (int i = 0; i < N; i++)
    {
        cout << "\nDados para o aluno " << i << ":\n";
        cout << "RG\t\t: " << turma[i].getRG() << endl;
        cout << "CPF\t\t: " << turma[i].getCPF() << endl;
        cout << "Nome\t\t: " << turma[i].getNome() << endl;
        cout << "Endereço\t: " << turma[i].getEndereco() << endl;
        cout << "Telefone\t: " << turma[i].getTelefone() << endl;
        cout << "Instituicao\t: " << turma[i].getInstituicao() << endl;
        cout << "RA\t\t: " << turma[i].getRA() << endl;
        cout << "Curso\t\t: " << turma[i].getCurso() << endl;
    }
    cout << endl;
}
