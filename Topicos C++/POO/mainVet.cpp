// Arquivo: mainVet
// Implementa: programa teste para a classe Vetor
// Autor: Prof. Josué Pereira de Castro

#include "Vetor.h"
#include "Matriz.h"
#include <iostream>
using namespace std;


int main()
{
	// Declaração de variáveis
	Vetor<int> A(2);
	Vetor<int> B(2);
    Vetor<int> C(2);
	A.fill(1); // Preenche com 1;
	B.fill(2); // Preenche com 2;		
	cout << "A = " << A << endl; // Escreve A
	cout << "B = " << B << endl; // Escreve B
    cout << "C = " << C << endl;
	A[0] = 3;
	A[1] = B[0];
	// A = B;
	if (A == B)
		cout << "A e B são iguais" << endl;
	else
		cout << "A e B são diferentes" << endl;
	cout << "A = " << A << endl;

	if (A != B)
		cout << "A e B são diferentes" << endl;
	else
		cout << "A e B são iguais" << endl;
	cout << "A = " << A << endl;
	cout << "Testando a soma com escalar: A = A + 5:" << endl;
	// A =  5 + A;
	A = A + 5;
	cout << "A = " << A << endl;

	cout << "Testando a soma de vetores: C = A + B" << endl;
	C = A + B;
	cout << "C = " << C << endl;

	cout << "Testando a subtração com escalar: A = A - 5:" << endl;
	 A =  5 - A;
	//A = A - 5;
	cout << "A = " << A << endl;

	cout << "Testando a soma de vetores: C = A - B" << endl;
	C = A - B;
	cout << "C = " << C << endl;

	// Criando um vetor de vetor

    cout << "Criando uma matriz como Vetor de Vetor\n";

	Vetor<Vetor<int>> D(3);   // Cria a matriz com 3 linhas

	for (int i = 0; i < 3; i++) // Aloca cada linha
		D[i] = Vetor<int>(3);

	for (int i = 0; i < 3; i++)  // Preenche a matriz
	{	
			D[i].fill(i);	
	}

	for (int i = 0; i < 3; i++)  // escreve a matriz
	{
        cout << D[i] << endl;
	}

	cout << endl;
   
	cout << "Criando Matriz 3x3:" << endl;
	Matriz<int> E(3, 3); // Cria a matriz E
	Matriz<int> F(3, 3); // Cria a matriz F
	Matriz<int> G(3, 3); // Cria a matriz G

	cout << "Lendo a matriz E: " << endl;
	cin >> E;
	cout << "escrevendo a matriz E: " << endl;
	cout << E << endl;
	cout << "Lendo a matriz F: " << endl;
	cin >> F;
	cout << "escrevendo a matriz F: " << endl;
	cout << F << endl;

	cout << "Soma de matrizes G = E + F:" << endl;
	G = E + F;
	cout << G << endl;

	cout << "multiplicação de matrizes G = E * F:" << endl;
	G = E * F;
	cout << G << endl;
}
