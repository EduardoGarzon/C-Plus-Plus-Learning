#include <iostream>
#include <stdlib.h>

// Classe para Lista Simples Encadeada
class IntSLLNode
{
public:
    int dado;         // Armazena o Estado
    IntSLLNode *next; // Ponteiro para o próximo nó

    // Construtor da Classe
    IntSLLNode(int el, IntSLLNode *ptr = nullptr)
    {
        dado = el;
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

    void DFS(int start);                 // Método para busca em profundidade
    void DFSUtil(int v, bool visited[]); // Método auxiliar para DFS
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
        IntSLLNode *newNode = new IntSLLNode(w, nullptr);
        newNode->next = adj[v];
        adj[v] = newNode;
    }
}

// Procedimento para exibir o Grafo
void Grafo::mostrarGrafo()
{
    for (int i = 0; i < V; i++)
    {
        IntSLLNode *current = adj[i];
        std::cout << "Vertice " << i << ": ";
        while (current)
        {
            std::cout << current->dado << " -> ";
            current = current->next;
        }
        std::cout << std::endl;
    }
}

// Funcao que verifica se o vertice esta na lista
bool Grafo::isInList(IntSLLNode *lista, int valor) const
{
    IntSLLNode *current = lista;
    while (current)
    {
        if (current->dado == valor)
        {
            return true;
        }
        current = current->next;
    }
    return false;
}

// Procedimento para iniciar a busca em profundidade a partir de um vértice específico
void Grafo::DFS(int start)
{
    bool *visited = new bool[V]; // Array para marcar os vértices visitados
    for (int i = 0; i < V; i++)
    {
        visited[i] = false; // Inicializa todos os vértices como não visitados
    }

    DFSUtil(start, visited); // Chama a função auxiliar para a DFS a partir do vértice inicial
}

// Procedimento recursivo para percorrer o grafo
void Grafo::DFSUtil(int v, bool visited[])
{
    visited[v] = true;     // Marca o vértice atual como visitado
    std::cout << v << " "; // Imprime o vértice atual

    // Itera sobre todos os vértices adjacentes ao vértice atual
    for (IntSLLNode *i = adj[v]; i != nullptr; i = i->next)
    {
        if (!visited[i->dado])
        {
            DFSUtil(i->dado, visited); // Chama recursivamente para o vértice adjacente não visitado
        }
    }
}

int main()
{
    int V = 5;      // Total de Estados
    Grafo grafo(V); // Instancia uma lista de Adjacencia

    grafo.adicionarAresta(0, 1);
    grafo.adicionarAresta(1, 3);
    grafo.adicionarAresta(1, 2);
    grafo.adicionarAresta(2, 4);
    grafo.adicionarAresta(3, 0);
    grafo.adicionarAresta(3, 4);
    grafo.adicionarAresta(4, 1);

    // Mostra o grafo
    grafo.mostrarGrafo();

    std::cout << "Busca em Profundidade a partir do vertice 0: \n";
    grafo.DFS(0); // Executa a busca em profundidade a partir do vértice 0

    system("pause");
    return 0;
}