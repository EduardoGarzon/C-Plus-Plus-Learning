#include <iostream>
using namespace std;

template <typename T>
void troca(T *V, T *J)
{
    T temp = *V;
    *V = *J;
    *J = temp;
}

// Algoritmo de partição para o quickSort
template <typename Tdado, typename Tnum>
int partition(Tdado V[], Tnum low, Tnum high)
{
    Tnum pivot = V[low];
    Tnum i = low - 1, j = high + 1;
    while (true)
    {
        do
        {
            i++;
        } while (V[i] < pivot);
        do
        {
            j--;
        } while (V[j] > pivot);
        if (i >= j)
            return j;
        troca(&V[i], &V[j]);
    }
}

// Algoritmo quickSort
template <typename Tdado, typename Tnum>
void quickSort(Tdado V[], Tnum low, Tnum high)
{
    if (low < high)
    {
        int pi = partition(V, low, high);
        quickSort(V, low, pi);
        quickSort(V, pi + 1, high);
    }
}

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90, 1, 5, 10, 20, 40, 0, -2, -5, -70, 100};

    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    cout << "Array ordenado: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
