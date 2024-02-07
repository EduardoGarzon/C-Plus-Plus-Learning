/*
    Implementacao de uma Arvore Heap - HeapSort
*/

#include <iostream>
#include <cstring>   // memset
#include <algorithm> // swap
#include <random>    // random_device

using namespace std;

// Procedimento para montar o vetor Heap
void Heap(int vet[], int i)
{
    // Verifica se é a raiz
    if (i == 0)
    {
        return;
    }

    int pai = 0; // Armazena o pai

    if (i % 2 == 0)
    {
        pai = (i / 2) - 1; // pai par (filho direito)
    }
    else
    {
        pai = i / 2; // pai impar (filho esquerdo)
    }

    // Realiza a troca se o pai for menor
    if (vet[pai] < vet[i])
    {
        swap(vet[pai], vet[i]);
        Heap(vet, pai);
    }

    return;
}

// Procedimento para inserir elementos no vetor
void inserir(int vet[], int tamanho)
{
    int dado = 0;

    for (int i = 0; i < tamanho; i++)
    {
        cout << "Informe o numero: ";
        cin >> dado;
        vet[i] = dado;

        Heap(vet, i);
    }

    cout << "\n";
}

// Procedimento para inserir valores aleatorios
void inserirAleatorio(int vet[], int tamanho)
{
    // objeto da classe random_device para gerar 
    // uma semente inicial verdadeiramente aleatória.
    random_device rd;

    // Gerador de números aleatórios usando a semente gerada pelo random_device.
    mt19937 gen(rd());

    // Distribuição uniforme que gera números inteiros no intervalo [0, 100].
    uniform_int_distribution<> dis(0, 100);
    
    for (int i = 0; i < tamanho; i++)
    {
        int num = dis(gen);
        vet[i] = num;
        Heap(vet, i);
    }
}

// Procedimento para impressao do vetor
void imprimir(int vet[], int tamanho)
{
    int i = 0;
    for (i = 0; i < tamanho; i++)
    {
        cout << vet[i] << " ";
    }
    cout << "\n";
}

// Procedimento para ordenacao
void HeapSort(int vet[], int tamanho)
{
    // Para i de n-1 ate 1 faca:
    for (int i = tamanho - 1; i >= 1; i--)
    {
        swap(vet[i], vet[0]); // Troca-se o elemento da raiz com o ultimo elemento

        for (int j = 0; j <= i - 1; j++) // Refaz a Heap para todas as posicoes n - 1
        {
            Heap(vet, j);
        }
    }
}

int main()
{
    int op = 0, retorno = 0, tamanho = 0;
    bool chave = false;

    do
    {
        cout << "Informe o tamanho do vetor: ";
        cin >> tamanho;
    } while (tamanho == 0);

    int *vet = new int[tamanho];
    memset(vet, 0, sizeof(int) * tamanho);

    chave = true;

    do
    {
        cout << "\n";
        cout << "0 - Sair\n";
        cout << "1 - Inserir\n";
        cout << "2 - Inserir Aleatório\n";
        cout << "3 - Imprimir Heap\n";
        cout << "4 - HeapSort\n";
        cout << "5 - Remover\n";
        
        cin >> op;
        cout << "\n";
        
        switch (op)
        {
        case 1:
            if (chave)
            {
                inserir(vet, tamanho);
                chave = false;
            }
            else
            {
                cout << "Vetor Preenchido!\n";
            }
            break;
        case 2:
            if (chave)
            {
                inserirAleatorio(vet, tamanho);
                chave = false;
            }
            else
            {
                cout << "Vetor Preenchido!\n";
            }
            break;
        case 3:
            if (tamanho != 0)
            {
                imprimir(vet, tamanho);
            }
            else
            {
                cout << "Vetor Vazio!\n";
            }
            break;
        case 4:
            if (!chave)
            {
                HeapSort(vet, tamanho);
            }
            else
            {
                cout << "Vetor Vazio!\n";
            }
            break;
        case 5:
            break;
        case 0:
            exit(0);
            break;
        default:
            cout << "Opcao Invalida!\n";
            break;
        }
    } while (op != 0);

    delete[] vet;

    return 0;
}