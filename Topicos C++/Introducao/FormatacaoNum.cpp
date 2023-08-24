// Demonstra a formatação de números em ponto flutuante
// Funções setf() da biblioteca iostream para formatar a saída do programa.
// Função precision() define o número de casas decimais de um número de ponto flutuante.

#include <iostream>
using namespace std;

int main()
{
    float a = 0;
    float b = 0;
    float c = 0;

    // Estabelece o padrão de exibição como fixo com ponto exibido.
    // O número de casas decimais exibido será sempre o mesmo,
    // independentemente do valor do número.
    cout.setf(ios::fixed);

    // Define que o ponto decimal deve ser sempre exibido,
    // mesmo se o número tiver zero casas decimais.
    cout.setf(ios::showpoint);

    cout << "Entre com o valor de A: ";
    cin >> a;
    cout << "Entre com o valor de B: ";
    cin >> b;
    c = a / b;

    // Número de casas decimais a serem exibidas
    cout.precision(1);
    cout << "O valor de C = A/B com uma casa decimal é: " << c << endl;
    cout.precision(2);
    cout << "O valor de C = A/B com duas casas decimais é: " << c << endl;
    cout.precision(3);
    cout << "O valor de C = A/B com três casas decimais é: " << c << endl;

    system("pause");

    return 0;
}