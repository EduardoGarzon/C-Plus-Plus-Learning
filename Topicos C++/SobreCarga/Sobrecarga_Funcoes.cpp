// Polimorfismo de Funcoes
// Exemplifica a sobrecarga de funções
// Implementacoes diferentes para funcoes conceitualmente iguais:
// int soma(int a, int b) e float soma(float a, float b)
// Em C essas funcoes teriam que ter nomes diferentes

#include <iostream>
using namespace std;

// Função soma sobrecarregada para somar dois inteiros retornando
// um inteiro
int soma(int a, int b)
{
    return (a + b);
}

// Função soma sobrecarregada para somar um inteiro e um float
// retornando um float
float soma(int a, float b)
{
    return (a + b);
}

// Função soma sobrecarregada para somar dois floats retornando
// um float
float soma(float a, float b)
{
    return (a + b);
}

// Função soma sobrecarregada para somar três inteiros
int soma(int a, int b, int c)
{
    return (a + b + c);
}

// Função soma sobrecarregada para somar três floats
float soma(float a, float b, float c)
{
    return (a + b + c);
}

int main()
{
    int aInt = 3;
    int bInt = 4;
    int cInt = 5;
    int sInt = 0;

    float aFloat = 5.6;
    float bFloat = 7.89;
    float cFloat = 8.910;
    float sFloat = 0.0;

    // Usando a função soma com inteiros
    sInt = soma(1, 2);
    cout << "Soma de dois inteiros: " << sInt << endl;
    sInt = soma(aInt, bInt);
    cout << "Soma de dois inteiros: " << sInt << endl;
    sInt = soma(aInt, bInt, cInt);
    cout << "Soma de três inteiros: " << sInt << endl;

    // Usando a função soma com um int e um float
    sFloat = soma(3, 4.5f);
    cout << "Soma de um int com um float: " << sFloat << endl;
    sFloat = soma(aInt, bFloat);
    cout << "Soma de um int com um float: " << sFloat << endl;

    // Usando a função soma com floats
    sFloat = soma(4.56f, 5.678f);
    cout << "Soma de dois floats: " << sFloat << endl;
    sFloat = soma(aFloat, bFloat);
    cout << "Soma de dois floats: " << sFloat << endl;
    sFloat = soma(aFloat, bFloat, cFloat);
    cout << "Soma de três floats: " << sFloat << endl;

    system("pause");
    
    return 0;
}
