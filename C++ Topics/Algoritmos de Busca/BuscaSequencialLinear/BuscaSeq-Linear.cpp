/*
    Busca Sequencial ou Linear.
    Varredura sequencial, elemento por elemento.
    Retorna a posicao do elemento ou -1 caso o elemento nao se encontre no conjunto.
*/

#include <iostream>
using namespace std;

// Algoritmo busca sequancial geral.
template <typename Tdado, typename Tnum>
Tnum seqSearch(Tdado elem, Tdado dados[], Tnum n)
{
    Tdado i;

    // Enquanto i for menor que o tamanho do array e
    // o elemento atual != elemento procurado.
    for (i = 0; (i < n) && (dados[i] != elem); i++)
        ;
    if (i == n) // Não achou.
        return -1;
    else
        return i; // Indice do elemento encontrado.
}

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    int elemento = 22;
    int retorno = seqSearch(elemento, arr, n);
    cout << "Retorno da Busca Sequencial para o elemento " << elemento << ": " << retorno << endl;

    return 0;
}