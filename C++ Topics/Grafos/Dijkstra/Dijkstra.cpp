#include <iostream>
#include <climits>

using namespace std;

#define V 5

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

void dijkstra(int grafo[V][V], int origem)
{
    int distancias[V];
    bool visitados[V];

    for (int i = 0; i < V; i++)
    {
        distancias[i] = INT_MAX;
        visitados[i] = false;
    }

    distancias[origem - 1] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        int u = encontrarVerticeMinimo(distancias, visitados);
        visitados[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (!visitados[v] && grafo[u][v] && distancias[u] != INT_MAX && distancias[u] + grafo[u][v] < distancias[v])
            {
                distancias[v] = distancias[u] + grafo[u][v];
            }
        }
    }

    imprimirRota(distancias);
}

int main()
{
    int grafo[V][V] = {
        {0, 48, 0, 33, 0},
        {48, 0, 52, 0, 0},
        {0, 52, 0, 16, 108},
        {33, 0, 16, 0, 0},
        {0, 0, 108, 0, 0}};

    dijkstra(grafo, 1);

    return 0;
}
