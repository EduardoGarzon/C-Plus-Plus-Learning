// Exemplo de heranca em C++

// Bibliotecas
#include <iostream>
#include <string.h>
using namespace std;

// Decalaracao de classes

// A classe pessoa a classe-base (ou classe mae) da qual outra sera derivada
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
    Pessoa(Pessoa &P); // Construtor de copia
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

// class nomeClass : Modificador nomeClassBase
// Modificador especifica a relação de acesso que a classe base terá com a classe derivada
class Aluno : public Pessoa // Definicao de Heranca, classe derivada
{
private:
    char Instituicao[31];
    char RA[11];
    char Curso[31];

public:
    Aluno();         // Construtor default para a classe aluno
    Aluno(Aluno &A); // Construtor de copia para a classe aluno
    ~Aluno();        // Destruidor da classe aluno
    
    char *getInstituicao();
    char *getRA();
    char *getCurso();
   
    void setInstituicao();
    void setRA();
    void setCurso();
};

// Declaracao das funcoes da classe Pessoa
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

Pessoa::Pessoa(Pessoa &P) // Construtor de copia
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

// metodos getters e setters Classe Pessoa

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
{ 
    // definicao do construtor default para a classe aluno;
    // O construtor default da classe base e chamado implicitamente;
    cout << "Construtor default da classe aluno inicializando um objeto do tipo aluno...\n";
    
    strcpy(Instituicao, "");
    strcpy(RA, "");
    strcpy(Curso, "");
    
    cout << "\nInicializacao concluida!\n";
}

// As classes derivadas não herdam os construtores e destruidores das superclasses.
// Caso nada seja especificado pelo programador, 
// o construtor da classe derivada realiza uma chamada implícita 
// ao construtor default da superclasse.
Aluno::~Aluno()
{
    cout << "\nObjeto do tipo aluno destruido!\n";
}

// Metodos getters e setters classe Aluno

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
    const int N = 3;
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
        cout << "Endereco\t: " << turma[i].getEndereco() << endl;
        cout << "Telefone\t: " << turma[i].getTelefone() << endl;
        cout << "Instituicao\t: " << turma[i].getInstituicao() << endl;
        cout << "RA\t\t: " << turma[i].getRA() << endl;
        cout << "Curso\t\t: " << turma[i].getCurso() << endl;
    }
    cout << endl;

    return 0;
}