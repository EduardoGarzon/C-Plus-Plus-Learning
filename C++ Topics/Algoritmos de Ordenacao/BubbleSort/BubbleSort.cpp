/*
    Ordenacao Bolha.
    Ordenacao por trocas.
    Examina sistematicamente elementos adjacentes de um conjunto e
    troca suas posicoes se for necessario.
    Compara cada elemento da lista com o elemento seguinte.
    O processo se repete ate que toda a lista esteja ordenada.
*/

#include <iostream>
#include <math.h>
using namespace std;

void bubbleSort(int arr[], int n)
{
    int i, j;

    // Percorre a lista para cada elemento,
    // exceto o ultimo que ja estara no lugar certo apos a ultima iteracao.
    for (i = 0; i < n - 1; i++)
    {
        // Percorre cada elemento que ainda nao esta na posicao correta.
        // Compara o elemento atual com o proximo e troca se necessario
        // percorre ate o penultimo elemento.
        for (j = 0; j < n - i - 1; j++)
        {
            // Se o elemento atual for maior que o proximo, troca.
            if (arr[j] > arr[j + 1])
            {
                // Troca os elementos de posição.
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};

    // Calcula tamanho do array.
    // sizeof(arr) == 28 bytes (4 bytes por elemento int * 7 elementos int).
    // sizeof(arr[0]) == um unico elemento int de 4 bytes.
    // 28 / 4 == tamanho 7.
    int n = sizeof(arr) / sizeof(arr[0]);

    int C = (0.5) * ((pow(n, 2)) - n);  // Comparacoes pior, medio e melhor caso.
    int T = (0.75) * ((pow(n, 2)) - n); // Trocas para medio casos.
    int T2 = (1.5) * ((pow(n, 2)) - n); // Trocas para pior casos.

    bubbleSort(arr, n);

    cout << "Array ordenado: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
    cout << "Numero de comparacoes pior, medio, melhor casos: " << C << endl;
    cout << "Trocas medio casos: " << T << endl;
    cout << "Trocas pior casos: " << T2 << endl;
    
    return 0;
}
