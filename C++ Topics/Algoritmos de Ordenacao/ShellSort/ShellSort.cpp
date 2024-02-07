/*
    ShellSort: Insercao Melhorada.
    Divide a lista em subgrupos menores para ordenar.
    A cada iteracao os subgrupos sao reduzidos ate ordenar toda a lista.
*/

#include <iostream>
using namespace std;

/*
    Cada iteração do primeiro laço divide a matriz em subgrupos menores,
    cada iteração do segundo laço itera sobre cada subgrupo da matriz,
    cada iteração do terceiro laço realiza a inserção do elemento
    na posição correta dentro do subgrupo.
*/

void shellSort(int arr[], int n)
{
    // Divide a lista em grupos menores.
    // Gap define o tamanho do salto entre os elementos do subgrupo.
    // A cada iteracao gap e divido pela metade ate que
    // seja 1 indicando que a lista esta ordenada.
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        // Itera sobre cada subgrupo.
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i]; // Elemento atual
            int j;
            // Insercao do elemento dentro do subgrupo.
            // j == i == gap,
            // Se elemento anterior ao atual dentro do subgrupo for maior, troca.
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90, 1, 5, 10, 20, 40, 0, -2, -5, -70, 100};

    int n = sizeof(arr) / sizeof(arr[0]);

    shellSort(arr, n);

    cout << "Array ordenado: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}