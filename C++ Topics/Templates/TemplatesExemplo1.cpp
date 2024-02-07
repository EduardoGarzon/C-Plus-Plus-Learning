/*
    Programa exemplo de templates (ou gabaritos) de função.

    Forma compacta para funcoes sobrecarregadas que realizam
    a mesma funcao sobre um mesmo conjunto de dados que
    podem aparecer com tipos diferentes.

    A funcao é declarada com um tipo de dado "em aberto"
    que é substituido em tempo de compilacao pelo tipo
    adequado ao contexto.
*/

#include <iostream>
using namespace std;

// Definição do template para a função soma.
// A função soma qualquer tipo de número.
// A funcao retorna o resultado com o mesmo tipo da primeira variável passada como parâmetro.
template <class T1, class T2> // ou template <typename T1, typename T2>
T1 soma(T1 v1, T2 v2)
{
    return T1(v1 + v2);
}

int main()
{
    // Usando o template com inteiros
    int int1, int2;
    cout << "Digite dois valores inteiros separados por espaco: ";
    cin >> int1 >> int2;
    cout << "A soma dos valores e: " << soma(int1, int2) << endl;

    // Usando o template com floats
    float float1, float2;
    cout << "Digite dois valores reais separados por espaco: ";
    cin >> float1 >> float2;
    cout << "A soma dos valores e: " << soma(float1, float2) << endl;

    // Usando o template com float e int
    cout << "Digite um inteiro e um float separados por espaco: ";
    cin >> int1 >> float1;
    // Retorna um inteiro
    cout << "A soma dos valores (resultado int) e: " << soma(int1, float1) << endl;
    // Retorna um float
    cout << "A soma dos valores (resultado float) e: " << soma(float1, int1) << endl;

    return 0;
}
