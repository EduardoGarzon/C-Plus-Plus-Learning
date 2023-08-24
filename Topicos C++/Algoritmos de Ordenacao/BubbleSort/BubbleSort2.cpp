#include <iostream>
using namespace std;

template <typename T>
void troca(T *atual, T *proximo)
{
    T temp = *atual;
    *atual = *proximo;
    *proximo = temp;
}

template <typename T>
void bubbleSort(T dados[], T n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = n - 1; j > i; j--)
            if (dados[j] < dados[j - 1])
                troca(&dados[j], &dados[j - 1]);
}

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90, 1, 5, 10, 20, 40, 0, -2, -5, -70, 100};
    int n = sizeof(arr) / sizeof(arr[0]);

    bubbleSort(arr, n);

    cout << "Array ordenado: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
