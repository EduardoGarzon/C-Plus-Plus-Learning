/*
    3. Usando recursividade, calcule a soma de todos os valores de um vetor de tamanho
    definido pelo usuário de reais.
*/

#include <iostream>

void insertValues(float vet[])
{
    float v = 0;

    std::cout << "Informe os valores: " << std::endl;
    for (int i = 0; i < 3; i++)
    {
        std::cin >> v;
        vet[i] = v;
    }
}

float somaVet(float vet[], int i)
{
    if (i == 3)
    {
        return vet[i];
    }
    else
    {
        return vet[i] + somaVet(vet, i + 1);
    }
}

int main()
{
    int i = 0;
    float soma = 0;
    float vet[3];

    insertValues(vet);
    soma = somaVet(vet, i);

    std::cout << "Soma dos valores reais do vetor: " << soma << std::endl;

    system("pause");
    return 0;
}