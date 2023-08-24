/*
Alocação dinâmica em C++ feita com os operadores new e delete.

Exemplo em C:
    double *ptr;
    ptr = (double*)malloc(sizeof(double));

Exemplo em C++:
    double *ptr;
    ptr = new double;
*/

#include <iostream>
using namespace std;

int main()
{
   // Aloca um único número, um ponteiro para um inteiro
   int *num;
   num = new int;
	if (num == NULL)
	{
		cout << "Erro: Não foi possível alocar a variável 'num'\n";
		exit(1);
	}
   
   // Lê o número
   cout << "entre com um valor inteiro: ";
   cin >> *num;
   
   // Alocando um vetor de tamanho *num, um ponteiro para um vetor int de tamanho num
   cout << "Alocando um vetor dinâmico de tamanho " << *num <<"...\n";
   int *vet = new int[*num];
   
   // Testa se alocação foi bem sucedida
   if (vet == NULL)
   {
      cout << "Erro: Não foi possível alocar um vetor de tamanho " << *num;
      exit(1);
   }
   
   // Lê o vetor
   for (int i = 0; i < *num; i++)
   {
      cout << "Elemento " << i << "? ";
      cin >> vet[i];
   }
   
   // Escreve o vetor
   for (int i = 0; i < *num; i++)
   {
      cout.width(ios::right);
      cout.setf(ios::fixed);
      cout.width(2);
      cout << "vet[" << i << "] = " <<  vet[i] << endl;
   }

   // Alocando uma matriz de ordem *num
   cout << "Alocando uma matriz de ordem " << *num << "... \n";
   
   // Alocando as linhas
   int **mat;
   mat = new int*[*num];
   
   // Testa se alocação foi bem sucedida
   if (mat == NULL)
   {
      cout << "Erro: Não foi possível alocar uma matriz " << *num 
			<< " por " << *num;
      exit(1);
   }
   // Alocando colunas
   for (int i = 0; i < *num; i++)
   {
      mat[i] = new int[*num];
      
      // testa se alocação foi bem sucedida
      if (mat[i] == NULL)
      {
         cout << "Erro na alocação da matriz!";
         exit(1);
      }
   }
      
   // lendo a matriz
   for (int i = 0; i < *num; i++)
      for (int j = 0; j < *num; j++)
      {
         cout << "Elemento [" << i << "," << j << "]? > ";
         cin >> mat[i][j];
      }
      
   cout << endl;
   cout.width(ios::right);
   cout.setf(ios::fixed);
   cout.width(3);
   //escrevendo os elementos
   for (int i = 0; i < *num; i++)
   {
      for (int j = 0; j < *num; j++)
      {
         cout <<   mat[i][j] << " ";
      }
      cout << endl;
   }

   // deletando as variáveis alocadas dinamicamente
   cout << "Deletando variáveis alocadas...";
   delete[] vet;
   for (int i = 0; i < *num; i++)
      delete[] mat[i];
   delete num;
   delete[] mat;
   cout<< endl << "Execução encerrada!" << endl;

   system("pause");

   return 0;
}
