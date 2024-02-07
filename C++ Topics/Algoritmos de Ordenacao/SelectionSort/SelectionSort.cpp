/*
    SelectionSort ou Ordenacao por selecao.
    Selecionar o menor item e coloca-lo na primeira posicao
    ate que reste um unico elemento.
*/
#include <iostream>
using namespace std;

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    // Percorre a lista de elementos
    // do inicio ate o penultimo.
    for (i = 0; i < n - 1; i++)
    {
        // Encontra o menor elemento restante.
        min_idx = i; // Indice do menor elemento.
        // j = proximo.
        for (j = i + 1; j < n; j++)
            // proximo < atual
            if (arr[j] < arr[min_idx])
                min_idx = j;

        // Coloca o menor elemento no início da lista.
        swap(arr[min_idx], arr[i]);
    }
}

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90, 1, 5, 10, 20, 40, 0, -2, -5, -70, 100};
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, n);

    cout << "Array ordenado: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}
