#include <iostream>
#include <climits>

using namespace std;

// Classe para Lista Simples Encadeada
class IntSLLNode
{
public:
    int dado;         // Armazena o vértice de destino
    int peso;         // Armazena o peso da aresta
    IntSLLNode *next; // Ponteiro para o próximo nó

    // Construtor da Classe
    IntSLLNode(int el, int p, IntSLLNode *ptr = nullptr)
    {
        dado = el;
        peso = p;
        next = ptr;
    }
};

// Classe Grafo para Lista de Adjacência
class Grafo
{
private:
    int V;            // Número de vértices
    IntSLLNode **adj; // Array de ponteiros para nós dos vértices

public:
    Grafo(int V)
    {
        this->V = V;
        adj = new IntSLLNode *[V];

        for (int i = 0; i < V; ++i)
            adj[i] = nullptr;
    }

    void adicionarAresta(int v, int a, int peso)
    {
        IntSLLNode *novoNo = new IntSLLNode(a, peso);
        novoNo->next = adj[v];
        adj[v] = novoNo;
    }

    void mostrarGrafo()
    {
        for (int i = 0; i < V; ++i)
        {
            IntSLLNode *temp = adj[i];
            cout << "Vértice " << i + 1 << " tem conexão com: ";
            while (temp != nullptr)
            {
                cout << temp->dado + 1 << " (peso: " << temp->peso << "km) ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    int encontrarVerticeMinimo(int distancias[], bool visitados[])
    {
        int minimo = INT_MAX, minimo_index;

        for (int v = 0; v < V; v++)
        {
            if (visitados[v] == false && distancias[v] <= minimo)
            {
                minimo = distancias[v];
                minimo_index = v;
            }
        }

        return minimo_index;
    }

    void imprimirRota(int distancias[])
    {
        cout << "Menor rota de 1 para 5: " << distancias[4] << "km" << endl;
    }

    void dijkstra(int src)
    {
        int distancias[V];
        bool visitados[V];

        for (int i = 0; i < V; i++)
        {
            distancias[i] = INT_MAX;
            visitados[i] = false;
        }

        distancias[src - 1] = 0;

        for (int count = 0; count < V - 1; count++)
        {
            int u = encontrarVerticeMinimo(distancias, visitados);
            visitados[u] = true;

            IntSLLNode *temp = adj[u];
            while (temp != nullptr)
            {
                int v = temp->dado;
                int peso = temp->peso;
                if (!visitados[v] && distancias[u] != INT_MAX && distancias[u] + peso < distancias[v])
                {
                    distancias[v] = distancias[u] + peso;
                }
                temp = temp->next;
            }
        }

        imprimirRota(distancias);
    }
};

int main()
{
    Grafo grafo(5);

    grafo.adicionarAresta(0, 1, 48);
    grafo.adicionarAresta(0, 3, 33);
    grafo.adicionarAresta(1, 2, 52);
    grafo.adicionarAresta(2, 4, 108);
    grafo.adicionarAresta(3, 2, 16);

    grafo.dijkstra(1);

    return 0;
}
