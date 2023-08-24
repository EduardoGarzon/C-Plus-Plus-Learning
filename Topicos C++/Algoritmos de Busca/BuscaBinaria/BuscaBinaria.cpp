/*
    Busca Binaria: método de divisão e conquista para acelerar o tempo médio de busca.
    Somente pode ser aplicado a conjuntos ordenados
    
    O primeiro elemento a ser testado é o elemento central do conjunto. 
    Se o elemento procurado for igual, retorna-se o valor da posição do elemento central, 
    caso contrário, verifica-se duas outras situações:
        a.  O elemento procurado é menor que o elemento central: 
            a busca deverá prosseguir na metade inferior ao elemento central
        b.  O elemento procurado é maior que o elemento central: 
            a busca deverá prosseguir na metade superior ao elemento central.
        c.  O procedimento deve ser chamado recursivamente para a metade apropriada.
*/

#include <iostream>
using namespace std;

// Algoritmo Busca Binária
template <typename Tdado, typename Tnum>
int binSearch(Tdado elem, Tdado dados[], Tnum n)
{
    Tnum lo = 0;
    Tnum hi = n - 1;
    Tnum i = 0;
    while (lo <= hi)
    {
        i = (lo + hi) / 2;
        if (dados[i] == elem)
            return i; // Achou
        if (elem < dados[i])
            hi = i - 1; // Pesquisa na metade esquerda
        else
            lo = i + 1; // Pesquisa na metade direita
    }
    return -1;
}

int main()
{
    int arr[] = {-8, -5, 1, 4, 14, 21, 23, 54, 67, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    int elemento = 4;
    int retorno = binSearch(elemento, arr, n);
    cout << "Retorno da Busca Binaria para o elemento " << elemento << ": " << retorno << endl;

    return 0;
}