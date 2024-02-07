/*
    MergeSort: Metodo dividir para conquistar.
    Divide o problema em pedaços menores, resolve cada pedaço
    e depois junta (merge) os resultados.
*/

#include <iostream>
#include <vector>

using namespace std;

// Algoritmo de particao merge
template <typename Tdado, typename Tnum>
void merge(Tdado V[], Tnum low, Tnum mid, Tnum high)
{
    Tnum n1 = mid - low + 1;
    Tnum n2 = high - mid;
    Tdado left[n1 + 1], right[n2 + 1];
    Tnum i = 0, j = 0;

    for (Tnum i = 0; i < n1; i++)
        left[i] = V[low + i];

    for (Tnum j = 0; j < n2; j++)
        right[j] = V[mid + 1 + j];

    left[n1] = SHRT_MAX;
    right[n2] = SHRT_MAX;

    for (Tnum k = low; k <= high; k++)
        if (left[i] <= right[j])
            V[k] = left[i++];
        else
        {
            V[k] = right[j++];
        }
}

// Algoritmo de ordencão mergesort
template <typename Tdado, typename Tnum>
void mergeSort(Tdado V[], Tnum low, Tnum high)
{
    if (low < high)
    {
        Tnum mid = (low + high) / 2;
        mergeSort(V, low, mid);
        mergeSort(V, mid + 1, high);
        merge(V, low, mid, high);
    }
}

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90, 1, 5, 10, 20, 40, 0, -2, -5, -70, 100};

    int n = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, n - 1);

    cout << "Array ordenado: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
