// Demontra o uso de argumentos default

#include <iostream>

void showValues(int left = 1, int middle = 1, int right = 1)
{
    printf("left: %d, middle: %d, right: %d\n", left, middle, right);
}

int main()
{
    showValues();        // Retorna os parametros default
    showValues(2, 4, 6); // Retorna os valores inseridos
    showValues(10);      // Apenas o primeiro parametro é modificado, os demais default
    showValues(20, 30);  // Apenas o primeiro e o segundo parametro sao modificados.
    // Nao é possivel definir apenas o primeiro e o ultimo parametro

    return 0;
}