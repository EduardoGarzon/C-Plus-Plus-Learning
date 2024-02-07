/*
    Ordenacao Oscilante ou cocktail sort: Melhoramento do algoritmo de bolha.

    Elementos fora de ordem na extremidade maior
    vão mais rapidamente para sua posição correta
    que elementos fora de ordem na extremidade menor.

    Implementa duas versões da bolha em um mesmo algoritmo,
    uma varrendo da esquerda para a direita e outra da direita para a esquerda.
*/

#include <iostream>
// #include <math.h>
using namespace std;

template <typename T>
void troca(T *anterior, T *atual)
{
    T temp = *atual;
    *atual = *anterior;
    *anterior = temp;
}

template <typename T>
void shakeSort(T dados[], T n)
{
    bool trocou;
    // Executa enquanto existir iteracoes sobre a lista, trocou = true.
    do
    {
        trocou = false;

        // Direita para esquerda.
        for (T i = (n - 1); i > 0; i--)
        {
            // anterior > atual?
            if (dados[i - 1] > dados[i])
            {
                troca(&dados[i - 1], &dados[i]);
                trocou = true;
            }
        }

        // Esquerda para direita.
        for (T i = 1; i < n; i++)
        {
            // anterior > atual?
            if (dados[i - 1] > dados[i])
            {
                troca(&dados[i - 1], &dados[i]);
                trocou = true;
            }
        }
    } while (trocou);
}

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90, 1, 5, 10, 20, 40, 0, -2, -5, -70, 100};
    int n = sizeof(arr) / sizeof(arr[0]);

    shakeSort(arr, n);

    cout << "Array ordenado: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
