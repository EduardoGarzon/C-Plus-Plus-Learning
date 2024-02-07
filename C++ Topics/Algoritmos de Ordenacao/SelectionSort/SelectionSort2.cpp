/*
    SelectionSort ou Ordenacao por selecao.
    selecionar o menor item e coloca-lo na primeira posicao
    ate que reste um unico elemento
*/
#include <iostream>
using namespace std;

template <typename Tnum>
void troca(Tnum *menor, Tnum *atual)
{
    Tnum temp = *atual;
    *atual = *menor;
    *menor = temp;
}

template <typename Tdado, typename Tnum>
void selectionSort(Tdado dados[], Tnum n)
{
    // Inicio ate o penultimo elemento
    for (Tnum i = 0; i < (n - 1); i++)
    {
        // Encontra o menor elemento
        Tnum min = i; // Indice do elemento atual
        // Proximo ate penultimo
        for (Tnum j = i + 1; j < n; j++)
            // proximo < atual?
            if (dados[j] < dados[min])
                min = j;
        // Troca a posição atual com o menor elemento do vetor
        troca(&dados[min], &dados[i]);
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
