/*
ShellSort: Insercao Melhorada
Divide a lista em subgrupos menores para ordenar
A cada iteracao os subgrupos sao reduzidos ate ordenar toda a lista
*/

#include <iostream>
using namespace std;

template <typename TDado, typename TNum>
void shellSort(TDado dados[], TNum n)
{
    int i, j, gap, k;
    char x, a[5] = {9, 5, 3, 2, 1};

    for (k = 0; k < 5; k++)
    {
        gap = a[k];
        for (int i = gap; i < n; i++)
        {
            x = dados[i];
            for (j = i - gap; x < dados[j] && j >= 0; j -= gap)
                dados[j + gap] = dados[j];
            dados[j + gap] = x;
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