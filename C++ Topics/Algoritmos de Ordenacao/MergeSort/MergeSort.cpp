/*
    MergeSort: Metodo dividir para conquistar.
    Divide o problema em pedaços menores,
    resolve cada pedaço e depois junta (merge) os resultados.
*/

#include <iostream>
#include <vector>

using namespace std;

/*
    Combina duas metades ordenadas da lista em uma única lista ordenada.
    Função merge recebe uma lista v e três inteiros left, mid e right,
    representando os índices da lista que correspondem às duas metades ordenadas.
*/
void merge(vector<int> &v, int left, int mid, int right)
{
    int i = left;    // Percorrer a primeira metade da lista.
    int j = mid + 1; // Percorrer a segunda metade da lista.
    
    /*
        A função cria um vetor temp que será usado para armazenar a
        lista ordenada resultante da combinação das duas metades.
    */
    vector<int> temp;

    // Percorre as duas metades da lista, comparando os elementos de cada metade.
    while (i <= mid && j <= right)
    {
        /*
            Se o elemento da primeira metade (v[i]) 
            for menor que o elemento da segunda metade (v[j]),
            o elemento da primeira metade é adicionado ao vetor temp, e i é incrementado.
            Caso contrário, o elemento da segunda metade 
            é adicionado ao vetor temp, e j é incrementado.
        */
        if (v[i] < v[j])
        {
            temp.push_back(v[i]);
            i++;
        }
        else
        {
            temp.push_back(v[j]);
            j++;
        }
    }

    /*
        loops que adicionam os elementos restantes de cada metade à lista temp, se houver.
        Esses loops são necessários porque as duas metades podem ter tamanhos diferentes.
    */
    while (i <= mid)
    {
        temp.push_back(v[i]);
        i++;
    }

    while (j <= right)
    {
        temp.push_back(v[j]);
        j++;
    }
    /*
        Loops que adicionam os elementos restantes de cada metade à lista temp, se houver.
        Esses loops são necessários porque as duas metades podem ter tamanhos diferentes.
    */
    for (int k = left; k <= right; k++)
    {
        v[k] = temp[k - left];
    }
}

/*
    A função mergesort é chamada recursivamente 
    para dividir a lista em duas metades e ordená-las.
    
    Recebe uma lista v e dois inteiros left e right,
    que representam os índices da lista que correspondem 
    ao início e ao fim do intervalo a ser ordenado.
*/
void mergesort(vector<int> &v, int left, int right)
{
    /*
        A função começa verificando se left é menor que right.
        Se left for igual a right, a lista já está ordenada e a função retorna nada (void).
        Caso contrário, a função calcula o índice mid como a média de left e right.
    */
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        /*
            A função chama recursivamente a função mergesort
            para ordenar a primeira metade da lista, 
            ou seja, o intervalo de left até mid.
        */
        mergesort(v, left, mid);
        /*
            A função chama recursivamente a função mergesort
            para ordenar a segunda metade da lista, 
            ou seja, o intervalo de mid + 1 até right.
        */
        mergesort(v, mid + 1, right);
        /*
            A função chama a função merge
            para combinar as duas metades ordenadas 
            da lista em uma única lista ordenada.
            A função retorna nada (void).
        */
        merge(v, left, mid, right);
    }
}

int main()
{
    vector<int> v = {64, 34, 25, 12, 22, 11, 90, 1, 5, 10, 20, 40, 0, -2, -5, -70, 100};
    mergesort(v, 0, v.size() - 1);

    for (int x : v)
    {
        cout << x << " ";
    }

    return 0;
}
