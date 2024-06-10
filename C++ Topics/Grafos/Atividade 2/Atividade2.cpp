#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

// Classe para Lista Simples Encadeada
class IntSLLNode
{
public:
    string User;      // Armazena o nome de usuario
    IntSLLNode *next; // Ponteiro para o próximo nó

    // Construtor da Classe
    IntSLLNode(string name, IntSLLNode *ptr = nullptr)
    {
        User = name;
        next = ptr;
    }
};

// Classe Grafo para Lista de Adjacência
class Grafo
{
private:
    int V;            // Número de vértices
    IntSLLNode **adj; // Array de ponteiros para nós das amizades dos usuarios

public:
    Grafo(int V);
    void adicionarAresta(int v, string f);
    void mostrarGrafo();

    // Função para verificar se um vértice está na lista de adjacência
    bool isInList(IntSLLNode *lista, string u) const;
    // Funcao para sugerir amizades com base nos amigos atuais
    void sugerirAmizade(int v, int sugestao);
    // Funcao para mostra usuario com mais amigos
    int maiorAresta();
};

// Construtor da classe Grafo
Grafo::Grafo(int V)
{
    this->V = V;               // Recebe o total de vértices
    adj = new IntSLLNode *[V]; // Aloca dinamicamente um array de ponteiros para IntSLLNode
    for (int i = 0; i < V; i++)
    {
        adj[i] = nullptr; // Inicializando lista de adjacência vazia
    }
}

// Procedimento para inserir no Grafo Direcionado
void Grafo::adicionarAresta(int v, string f)
{
    if (!isInList(adj[v], f))
    {
        // Adiciona um novo nó à lista de adjacência do vértice v no grafo.
        IntSLLNode *newNode = new IntSLLNode(f, nullptr);
        newNode->next = adj[v];
        adj[v] = newNode;
    }
}

// Funcao para identificar nome de usuario
string identificarUsuario(int u)
{
    switch (u)
    {
    case 0:
        return "Luiz";
        break;
    case 1:
        return "Carlos";
        break;
    case 2:
        return "Pedro";
        break;
    case 3:
        return "Duda";
        break;
    case 4:
        return "Helo";
        break;
    case 5:
        return "Maicon";
        break;
    case 6:
        return "Nando";
        break;
    default:
        return "Usuario Nao identificado";
        break;
    }
}

// Procedimento para exibir o Grafo
void Grafo::mostrarGrafo()
{
    for (int i = 0; i < V; i++)
    {
        IntSLLNode *current = adj[i];
        string u = identificarUsuario(i);
        cout << "Vertice(" << u << "): ";
        while (current)
        {
            cout << current->User << ", ";
            current = current->next;
        }
        cout << endl;
    }
}

// Funcao que verifica se o vertice esta na lista
bool Grafo::isInList(IntSLLNode *lista, string u) const
{
    IntSLLNode *current = lista;
    while (current)
    {
        if (current->User == u)
        {
            return true;
        }
        current = current->next;
    }
    return false;
}

// Funcao que calcula a maior aresta do Grafo ou usuarios com mais amigos
int Grafo::maiorAresta()
{
    int maiorAresta = 0, el = 0;
    IntSLLNode *current;
    for (int i = 0; i < V; i++)
    {
        int numArestas = 0;
        current = adj[i];
        while (current)
        {
            numArestas++;
            current = current->next;
        }

        if (numArestas > maiorAresta)
        {
            maiorAresta = numArestas;
            el = i;
        }
    }

    string u = identificarUsuario(el);
    cout << "Usuario com mais amigos: " << u << endl;
    return maiorAresta;
}

void Grafo::sugerirAmizade(int usuario, int sugestao)
{
    IntSLLNode *user2 = adj[sugestao];
    string u = identificarUsuario(sugestao);
    string w = identificarUsuario(usuario);
    cout << "Amizades Sugeridas de " << u << " para " << w << ": " << endl;

    while (user2)
    {
        // Verifica se o amigo em user2 não é o próprio usuário
        if (user2->User != w)
        {
            IntSLLNode *user = adj[usuario];
            int flag = 0;

            while (user)
            {
                if (user2->User == user->User)
                {
                    flag = 1;
                    break;
                }
                user = user->next;
            }

            if (flag == 0)
            {
                cout << user2->User << ", ";
            }
        }

        user2 = user2->next;
    }
    cout << endl;
}

int main()
{
    int V = 7;
    Grafo grafo(7);

    // Usuario 1 - LUIZ
    grafo.adicionarAresta(0, "Pedro");
    grafo.adicionarAresta(0, "Carlos");
    grafo.adicionarAresta(0, "Maicon");

    // Usuario 2 - CARLOS
    grafo.adicionarAresta(1, "Pedro");
    grafo.adicionarAresta(1, "Luiz");

    // Usuario 3 - PEDRO
    grafo.adicionarAresta(2, "Duda");
    grafo.adicionarAresta(2, "Carlos");
    grafo.adicionarAresta(2, "Luiz");

    // Usuario 4 - DUDA
    grafo.adicionarAresta(3, "Helo");
    grafo.adicionarAresta(3, "Pedro");
    grafo.adicionarAresta(3, "Maicon");

    // Usuario 5 - HELO
    grafo.adicionarAresta(4, "Duda");
    grafo.adicionarAresta(4, "Maicon");
    grafo.adicionarAresta(4, "Nando");

    // Usuario 6 - MAICON
    grafo.adicionarAresta(5, "Ruan");
    grafo.adicionarAresta(5, "Duda");
    grafo.adicionarAresta(5, "Luiz");
    grafo.adicionarAresta(5, "Helo");

    // Usuario 7 - NANDO
    grafo.adicionarAresta(6, "Berti");
    grafo.adicionarAresta(6, "Jose");
    grafo.adicionarAresta(6, "Cristian");
    grafo.adicionarAresta(6, "Maria");
    grafo.adicionarAresta(6, "Paula");
    grafo.adicionarAresta(6, "Helo");

    grafo.mostrarGrafo();
    cout << endl;

    int Total = grafo.maiorAresta();
    cout << "Total de amigos: " << Total << endl
         << endl;

    grafo.sugerirAmizade(4, 6);
    cout << endl;

    system("pause");
    return 0;
}