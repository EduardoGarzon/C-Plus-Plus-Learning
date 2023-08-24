#include <iostream>
#include <algorithm>

void ajustarHeap(int vet[], int tamanho, int raiz)
{
    int maior = raiz;
    int esquerda = 2 * raiz + 1;
    int direita = 2 * raiz + 2;

    if (esquerda < tamanho && vet[esquerda] > vet[maior])
        maior = esquerda;

    if (direita < tamanho && vet[direita] > vet[maior])
        maior = direita;

    if (maior != raiz)
    {
        std::swap(vet[raiz], vet[maior]);
        ajustarHeap(vet, tamanho, maior);
    }
}

void HeapSort(int vet[], int tamanho)
{
    for (int i = tamanho / 2 - 1; i >= 0; i--)
        ajustarHeap(vet, tamanho, i);

    for (int i = tamanho - 1; i > 0; i--)
    {
        std::swap(vet[0], vet[i]);
        ajustarHeap(vet, i, 0);
    }
}

int removerMaximo(int vet[], int &tamanho)
{
    if (tamanho == 0)
    {
        std::cerr << "Erro: Vetor vazio\n";
        return -1; // Retorna um valor inválido em caso de erro
    }

    int maximo = vet[0];
    vet[0] = vet[tamanho - 1];
    tamanho--;

    ajustarHeap(vet, tamanho, 0);

    return maximo;
}

int main()
{
    int tamanho;

    std::cout << "Informe o tamanho do vetor: ";
    std::cin >> tamanho;

    int *vetor = new int[tamanho];

    std::cout << "Informe os elementos do vetor:\n";
    for (int i = 0; i < tamanho; i++)
    {
        std::cin >> vetor[i];
    }

    HeapSort(vetor, tamanho);

    std::cout << "Vetor ordenado:\n";
    for (int i = 0; i < tamanho; i++)
    {
        std::cout << vetor[i] << " ";
    }
    std::cout << "\n";

    int maximo = removerMaximo(vetor, tamanho);
    std::cout << "Valor removido: " << maximo << "\n";

    std::cout << "Vetor apos remocao:\n";
    for (int i = 0; i < tamanho; i++)
    {
        std::cout << vetor[i] << " ";
    }
    std::cout << "\n";

    HeapSort(vetor, tamanho);
    std::cout << "Vetor ordenado:\n";
    for (int i = 0; i < tamanho; i++)
    {
        std::cout << vetor[i] << " ";
    }
    std::cout << "\n";
    
    delete[] vetor;

    return 0;
}
