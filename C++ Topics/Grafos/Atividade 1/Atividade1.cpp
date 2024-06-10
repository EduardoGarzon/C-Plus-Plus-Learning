#include <iostream>
#include <stdlib.h>
using namespace std;

// Funcao que classifica o estado conforme o id
string verificarID(int w)
{
    switch (w)
    {
    case 0:
        return "Maranhao";
        break;
    case 1:
        return "Piaui";
        break;
    case 2:
        return "Bahia";
        break;
    case 3:
        return "Ceara";
        break;
    case 4:
        return "Rio Grande do Norte";
        break;
    case 5:
        return "Paraiba";
        break;
    case 6:
        return "Pernambuco";
        break;
    case 7:
        return "Alagoas";
        break;
    case 8:
        return "Sergipe";
        break;
    default:
        return "Nao identificado";
        break;
    }
}

// Classe para Lista Simples Encadeada
class IntSLLNode
{
public:
    int id;           // Armazena o id do Estado
    string estado;    // Armazena o Estado
    IntSLLNode *next; // Ponteiro para o próximo nó

    // Construtor da Classe
    IntSLLNode(int num, string el, IntSLLNode *ptr = nullptr)
    {
        id = num;
        estado = el;
        next = ptr;
    }
};

// Classe Grafo para Lista de Adjacência
class Grafo
{
private:
    int V;            // Número de vértices
    IntSLLNode **adj; // Array de ponteiros para nós dos Estados

public:
    Grafo(int V);
    void adicionarAresta(int v, int a);
    void mostrarGrafo();

    // Função para verificar se um vértice está na lista de adjacência
    bool isInList(IntSLLNode *lista, int valor) const;

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
void Grafo::adicionarAresta(int v, int w)
{
    // Adiciona uma aresta de v para w
    if (!isInList(adj[v], w))
    {
        // Adiciona um novo nó à lista de adjacência do vértice v no grafo.
        string el = verificarID(w);
        IntSLLNode *newNode = new IntSLLNode(w, el, nullptr);
        newNode->next = adj[v];
        adj[v] = newNode;
    }
}

// Procedimento para exibir o Grafo
void Grafo::mostrarGrafo()
{
    for (int i = 0; i < V; i++)
    {
        string el = verificarID(i);
        cout << "Vertice " << i << " - " << el << ": ";
        IntSLLNode *current = adj[i];
        while (current)
        {
            cout << current->estado << "(" << current->id << ")"
                 << " ";
            current = current->next;
        }
        cout << endl;
    }
}

// Funcao que verifica se o vertice esta na lista
bool Grafo::isInList(IntSLLNode *lista, int valor) const
{
    IntSLLNode *current = lista;
    while (current)
    {
        if (current->id == valor)
        {
            return true;
        }
        current = current->next;
    }
    return false;
}

// Funcao que calcula a maior aresta do Grafo
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

        if (numArestas >= maiorAresta)
        {
            maiorAresta = numArestas;
            el = i;
        }
    }

    current = adj[el - 1];
    cout << current->estado << endl;
    return maiorAresta;
}

int main()
{
    int V = 9;      // Total de Estados
    Grafo grafo(V); // Instancia uma lista de Adjacencia

    // Maranhao(0)
    grafo.adicionarAresta(0, 1);

    // Piaui(1)
    grafo.adicionarAresta(1, 0);
    grafo.adicionarAresta(1, 2);
    grafo.adicionarAresta(1, 3);
    grafo.adicionarAresta(1, 6);

    // Bahia(2)
    grafo.adicionarAresta(2, 1);
    grafo.adicionarAresta(2, 6);
    grafo.adicionarAresta(2, 7);
    grafo.adicionarAresta(2, 8);

    // Ceara(3)
    grafo.adicionarAresta(3, 1);
    grafo.adicionarAresta(3, 4);
    grafo.adicionarAresta(3, 5);
    grafo.adicionarAresta(3, 6);

    // Rio Grande do Norte(4)
    grafo.adicionarAresta(4, 3);
    grafo.adicionarAresta(4, 5);

    // Paraiba(5)
    grafo.adicionarAresta(5, 3);
    grafo.adicionarAresta(5, 4);
    grafo.adicionarAresta(5, 6);

    // Pernambuco(6)
    grafo.adicionarAresta(6, 1);
    grafo.adicionarAresta(6, 2);
    grafo.adicionarAresta(6, 3);
    grafo.adicionarAresta(6, 5);
    grafo.adicionarAresta(6, 7);

    // Alagoas(7)
    grafo.adicionarAresta(7, 2);
    grafo.adicionarAresta(7, 6);
    grafo.adicionarAresta(7, 8);

    // Sergipe(8)
    grafo.adicionarAresta(8, 2);
    grafo.adicionarAresta(8, 7);

    // Plota lista de adjacencia
    grafo.mostrarGrafo();
    cout << endl;

    // Exibe estado com maior numero de fronteiras
    int M = grafo.maiorAresta();
    cout << "Maior Aresta: " << M << endl;

    system("pause");
    return 0;
}