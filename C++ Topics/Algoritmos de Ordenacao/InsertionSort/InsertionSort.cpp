/*
    Insertion Sort: Ordenacao por Insercao.
    Percorre a lista da esquerda para direita
    ordenando os elementos à esquerda.
    Semelhante a ordenacao de cartas de baralho.
    Pode ordenar de forma crescente ou decrescente.
*/

#include <iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
    int i, j, key;

    // Inicio ao ultimo.
    for (i = 1; i < n; i++)
    {
        key = arr[i]; // elemento atual
        j = i - 1;    // elemento anterior

        // Move os elementos maiores que a key para a frente.
        // Move da esquerda para a direita da key.
        // Enquanto houver elementos a esquerda e elementos maiores que a key:
        while (j >= 0 && arr[j] > key)
        {
            // Elemento atual = anterior (maior que key).
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        // Anterior = key, alinhando a esquerda o menor e a direita os maiores.
        arr[j + 1] = key;
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
