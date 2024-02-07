/*
    Exemplifica entrada e saida em arquivos.
    esse exemplo de leitura de arquivo assume que
    o arquivo de entrada contém apenas valores numéricos,
    um em cada linha, e que o arquivo de saída conterá apenas um valor,
    que é a soma desses valores numéricos.
*/

#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    cout << "\nEste programa le um conjunto de inteiros armazenados em um"
         << " arquivo texto\ne imprime a sua soma em outro arquivo texto\n\n";

    cout << "Qual o nome do arquivo de entrada? > ";

    char InFile[256]; // Vari�vel para armazenar o nome do arquivo de entrada
    cin >> InFile;

    cout << "Qual o nome do arquivo de saida? > ";
    char OutFile[256];
    cin >> OutFile;

    ifstream in;
    ofstream out;

    in.open(InFile);
    out.open(OutFile);

    int num = 0;
    int soma = 0;

    // Faz a primeira leitura fora do laco para verificar
    // o fim de arquivo ja na primeira iteracao.
    in >> num;
    while (!in.eof()) // enquanto o final do arquivo de entrada não é alcançado
    {
        soma += num; // Se a leitura teve sucesso, calcula a soma
        in >> num;   // tenta nova leitura
    }

    out << soma;
    cout << "\nProcessamento concluido.\n";

    return 0;
}
