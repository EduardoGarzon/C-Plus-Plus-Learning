/*
Ordenacao Oscilante ou cocktail sort: Melhoramento do algoritmo de bolha

elementos fora de ordem na extremidade maior vão mais rapidamente para sua posição correta
que elementos fora de ordem na extremidade menor.

Implementa duas versões da bolha em um mesmo algoritmo,
uma varrendo da esquerda para a direita e outra da direita para a esquerda.
*/

#include <iostream>
using namespace std;

void shakeSort(int arr[], int n)
{
    bool swapped = true; // indica se houve troca durante a ultima passagem pela lista
    // faixa de elementos que ainda nao foram ordenados
    int start = 0;   // inicio
    int end = n - 1; // penultimo

    while (swapped)
    {
        // reseta a flag swapped ao inicio de cada passagem pela lista
        swapped = false;

        // movimenta o maior elemento para a direita
        // da esquerda para a direita
        for (int i = start; i < end; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        end--;

        // Movimenta o menor elemento para a esquerda
        // da diretia para a esquerda
        for (int i = end; i > start; i--)
        {
            if (arr[i] < arr[i - 1])
            {
                swap(arr[i], arr[i - 1]);
                swapped = true;
            }
        }
        start++;
    }
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
