/*
Insertion Sort: Ordenacao por Insercao
Percorre a lista da esquerda para direita ordenando os elementos à esquerda
Semelhante a ordenacao de cartas de baralho
pode ordenar de forma crescente ou decrescente
*/

#include <iostream>
using namespace std;

template <typename Tdado, typename Tnum>
void insertionSort(Tdado dados[], Tnum n)
{
    // inicio ao ultimo
    for (Tnum i = 1; i < n; i++)
    {
        Tdado aux = dados[i]; // elemento atual, segundo, menor
        Tnum j = 0;
        // enquanto existir elementos anteriores ao atual e
        // o atual for menor que os elementos anteriores:
        for (j = i; (j > 0) && (aux < dados[j - 1]); j--)
            dados[j] = dados[j - 1]; // atual recebe o anterior
        dados[j] = aux;              // coloca elemento menor na posicao correta
    }
}

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90, 1, 5, 10, 20, 40, 0, -2, -5, -70, 100};

    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);

    cout << "Array ordenado: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
