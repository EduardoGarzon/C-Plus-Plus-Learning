#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct
{
    double x;
    double y;
    float fitness;
} Individuo;

Individuo pessoas[10];
int pop = 0;
int gen = 3;

float fitnessC()
{
    // calculo do fitness, funcao de otimizacao
    float fit = pow(pessoas[pop].x, 5) - 10 * pow(pessoas[pop].x, 3) + 30 * pessoas[pop].x - pow(pessoas[pop].y, 2) + 21 * pessoas[pop].y;
    return fit;
}

void iniciar_populacao()
{
    // inicia individuo com genes x e y aleatorios + calculo de fitness
    pessoas[pop].x = (rand() / (float)RAND_MAX * (-2.5 - 0)) + 0;
    pessoas[pop].y = (rand() / (float)RAND_MAX * (-2.5 - 0)) + 0;
    pessoas[pop].fitness = fitnessC();
}

void comparar() // ordena individuos pelo maior fitness
{
    int i, j;
    Individuo fit;
    for (i = 1; i < 10; i++) // avanca
    {
        fit = pessoas[i];
        for (j = i; (j > 0) && (fit.fitness < pessoas[j - 1].fitness); j--) // compara com os anteriores
        {
            pessoas[j] = pessoas[j - 1];
        }
        pessoas[j] = fit;
    }
}

int main(void)
{

    srand(time(NULL));

    for (int i = 0; i < gen; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            iniciar_populacao();
            comparar(); // ordenar fitness
            printf("gen: %d | x: %f| y: %f | fitness: %f\n", i, pessoas[j].x, pessoas[j].y, pessoas[j].fitness);
            pop++;
        }
        printf("\n");
        pop = 0; // zera para proxima populacao de 10 individuos
    }
    return 0;
}