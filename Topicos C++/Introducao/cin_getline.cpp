// Demonstra comandos de entrada e saída Em C++ com cin, cout e getline

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string Nome;
    char nome[20];
    int idade;

    cout << "Hello World!\n";

    // Utiliza o objeto cout para dar saída no vídeo
    cout << "Qual o seu nome? \n";
    // getline(cin, Nome);      // Nome deve ser do tipo string
    // getline(cin, Nome, ';'); // Podemos usar o delimitador para marcar o fim da linha
    // cin >> Nome;             // cin não lê strings com espaços em branco
    // cin.get(nome, 20);

    fflush(stdin);
    // cin.get(); // limpa o buffer

    cout << "Olá " << Nome << "!\n";

    cout << "Qual sua idade?" << endl;
    cin >> idade;
    cout << "Você tem " << idade << " anos!" << endl;

    system("pause");

    return 0;
}
