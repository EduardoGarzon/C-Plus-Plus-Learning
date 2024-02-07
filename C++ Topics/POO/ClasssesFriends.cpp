// Exemplifica classes friends de outras classes.
// Classe que pode ter acesso aos dados membros de outra classe.

#include <iostream>
#include <string>
#include <string.h>

using namespace std;

// Definições de classes

class Impressora
{
private:
    char nome[21];

public:
    // construtor inline
    inline Impressora();

    // a classe Computador é friend da classe Impressora
    // a classe Computador tem acesso a classe Impressora
    friend class Computador;
};

class Computador
{
private:
    unsigned totalImpressoras;
    char micro[21];   // nome do computador
    Impressora *LPT1; // ponteiro para objeto do tipo Impressora
public:
    
    // função construtora inline
    Computador(char nome[], unsigned total)
    {
        strcpy(micro, nome); // atribui o nome do computador
        
        // Aloca as impressoras
        totalImpressoras = total;
        LPT1 = new Impressora[totalImpressoras];
    }
    
    // função destruidora inline
    ~Computador()
    {
        delete[] LPT1; // desaloca as impressoras
    }
    
    void mostrar();
};

// Declaração dos métodos para a classe computador
void Computador::mostrar()
{
    cout << endl
         << "Computador: ";
    
    cout << micro;
    
    for (int i = 0; i < totalImpressoras; i++)
        cout << "\nImpressora: " << LPT1[i].nome;
    cout << endl;
}

// Declaração dos métodos para a classe Impressora
Impressora::Impressora()
{
    cin.get();
    cout << "Impressora: ";
    cin.get(nome, 20);
}

// função principal
int main()
{
    char micro[21];     // nome do computador
    unsigned total = 0; // total de impressoras que estao nesse computador

    // leitura do nome do computador
    cout << endl
         << "Computador: ";
    cin.get(micro, 20);

    // leitura do total de impressoras
    cout << "Total de impressoras: ";
    cin >> total;

    // instancia da classe Computador
    Computador PC(micro, total);

    cout << endl
         << "\nEquipamentos Disponiveis:\n";
    PC.mostrar();

    return 0;
}
