/*
    1. QuickSort: dividir para conquistar
    2. Divide a lista em partes menores e as ordena separadamente.
    3.  O Quicksort seleciona um elemento da lista, chamado de pivô,
        e rearranja os elementos da lista de forma que todos os elementos menores
        que o pivô fiquem antes dele na lista,
        e todos os elementos maiores que o pivô fiquem depois dele na lista.
        O pivô então fica em sua posição final na lista ordenada.
        Esse processo é aplicado recursivamente para as sublistas formadas antes e depois do pivô,
        até que toda a lista esteja ordenada.
*/

#include <iostream>
#include <vector>

using namespace std;

/*
    A função partition é usada para rearranjar os elementos da lista em torno de um pivô
    e devolver sua posição final na lista ordenada.

    A função recebe uma lista v e dois inteiros low e high,
    que representam os índices da lista que correspondem ao início e ao fim do intervalo a ser ordenado.
*/
int partition(vector<int> &v, int low, int high)
{
    /*
        A função começa selecionando o pivô como o último elemento da lista (v[high]).
        Em seguida, inicializa uma variável i com o valor de low - 1.
        A variável i é usada para controlar a posição final do pivô na lista.
    */
    int pivot = v[high];
    int i = low - 1;

    /*
        Depois, a função entra em um loop que percorre a lista a partir de low até high-1.
        Se o elemento atual (v[j]) for menor que o pivô, a função incrementa i e troca os elementos v[i] e v[j].
        Isso garante que todos os elementos menores que o pivô fiquem à esquerda do índice i na lista.
    */
    for (int j = low; j < high; j++)
    {
        if (v[j] < pivot)
        {
            i++;
            swap(v[i], v[j]);
        }
    }

    /*
        Finalmente, a função troca o pivô (v[high]) com o elemento seguinte a i (v[i+1]).
        Isso garante que o pivô fique em sua posição final na lista ordenada.
        A função retorna a posição final do pivô na lista ordenada (i+1).
    */
    swap(v[i + 1], v[high]);
    return i + 1;
}

/*
    Ela recebe como parâmetros uma lista v, representada por um vetor,
    e dois inteiros low e high, que representam os índices da lista que correspondem
    ao início e ao fim do intervalo a ser ordenado.
*/
void quicksort(vector<int> &v, int low, int high)
{
    /*
        Primeiro, ela verifica se o intervalo a ser ordenado tem mais de um elemento,
        isto é, se low é menor que high.

        Se isso for verdade, a função chama a função partition para rearranjar a lista
        em torno de um pivô e devolver a posição final do pivô na lista ordenada.
    */
    if (low < high)
    {
        int p = partition(v, low, high);
        /*
            a função quicksort é chamada recursivamente para ordenar as sublistas formadas antes e depois do pivô.

            A primeira chamada ordena a lista que vai do início até
            a posição anterior ao pivô (quicksort(v, low, p-1)).

            A segunda chamada ordena a lista que vai da
            posição seguinte ao pivô até o fim (quicksort(v, p+1, high)).
        */
        quicksort(v, low, p - 1);
        quicksort(v, p + 1, high);
        /*
            O processo de ordenar as sublistas continua de forma recursiva
            até que todas as sublistas tenham apenas um elemento,
            o que significa que toda a lista está ordenada.

            Nesta implementação, o pivô é sempre escolhido como o último elemento da lista (v[high]).
        */
    }
}

int main()
{
    vector<int> v = {10, 80, 30, 90, 40, 50, 70};
    int n = v.size();

    quicksort(v, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}
