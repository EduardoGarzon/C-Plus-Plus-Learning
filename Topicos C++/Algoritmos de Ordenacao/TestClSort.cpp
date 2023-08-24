// Programa TestClSort.cpp
// Testa os algoritmos de ordena��o como m�todos de classe
// Autor: Prof. Josu� Pereira de Castro

#include <iostream>
#include <cstdlib>
#include <climits>
using namespace std;

class Vetor {
	private:
    	int n;									// O n�mero de elementos do vetor;
    	int *V;									// A estrutura que armazena os elementos
    	void swap(int &a, int &b);				// M�todo auxiliar para troca
    	void realloc(); 						// m�todo auxiliar para realocar o vetor V.
		void merge(int low, int mid, int high); // algoritmo de recombina��o para MergeSort 
		int partition(int low, int high); 		// algoritmo de parti��o para o QuickSort
	
	public:
    	// Construtores e destruidores
    	Vetor();				// Construtor default
    	Vetor(int tam);			// Construtor com tamanho definido
    	Vetor(const Vetor &A);	// Construtor de c�pia
    	~Vetor();				// Destruidor
		
		// Outros m�todos
		int len();						// retorna o n�mero de elementos do vetor
    	void add(int valor);			// Adiciona mais uma posi��o ao final do vetor e 
				        				// lhe atribui "valor";
		int get(int i);	   				// obtem o valor armazenado na posi��o i do vetor
		void set(int i, int v);			// seta o valor v na posi��o i do vetor
		int operator[](int i) const; 	// sobrecarga do operador [] para leitura
		int &operator[](int i); 		// sobrecarga do operador [] para escrita
		void escreve();					// escreve o vetor

		// M�todos de ordena��o 
		void BubbleSort();					// ordena��o pelo algoritmo da bolha
		void ShakerSort();					// ordena��o pelo m�todo oscilante oscilante
		void InsertionSort();				// ordena��o pelo algoritmo de inser��o
		void SelectionSort();				// ordena��o pelo algoritmo de sele��o
		void ShellSort();					// ordena��o pelo algoritmo Shell
		void MergeSort(int low, int high); 	// ordena��o pelo algoritmo MergeSort
		void QuickSort(int low, int high); 	// ordena��o pelo algoritmo QuickSort
};

// Implementa��o dos m�todos da classe Vetor

Vetor::Vetor()
{
	// construtor default
	cout << "Construtor default construindo vetor...\n";
	n = 0;
	V = NULL;
	cout << "Vetor construido.\n";
}

Vetor::Vetor(int tam)
{
	cout << "Construtor inicializ�vel construindo vetor...\n";
	if (tam < 0)
	{
		cerr << "Erro: o n�mero de elementos n�o pode ser negativo.\n";
		cerr << "Ajustando n�mero de elementos para zero.\n";
		n = 0;
		V = NULL;
	}
	else
	{
		n = tam;
    	V = new int[n];
    	if (V == NULL)
    	{
			cerr << "Erro 1: N�o � poss�vel construir um vetor com tamanho\n ";
			cerr << n << ".";
	 		exit(1);
      	}
      	else
      	{
	 		for (int i = 0; i < n; i++)
	    	V[i] = 0;
      	}
   	}
   	cout << "Vetor constru�do\n";
}

Vetor::Vetor(const Vetor &A)
{
	cout << "Construtor de c�pia construindo Vetor...\n";
	this->n = A.n;
	V = new int[this->n];
	if (V == NULL)
	{
		cerr << "Erro 2: N�o � poss�vel criar a c�pia do vetor.";
    	exit(2);
	}
	for (int i = 0; i < this->n; i++)
	{
    	this->V[i] = A.V[i];
	}
	cout << "Vetor constru�do.";
}

Vetor::~Vetor()
{
	cout << "Destruindo Vetor...\n";
	delete[] V;
	cout << "Vetor destru�do\n";
}

void Vetor::realloc()
{
	if (n == 0) // N�o h� elementos no vetor;
	{
    	V = new int[++n];
    	if (V == NULL) // Aloca��o falhou
    	{
			cerr << "Erro 3: N�o � poss�vel redimensionar o vetor.";
        	exit(3);
    	}
	}
	else
	{
    	int *aux = new int[n];
    	if (aux == NULL)
    	{
        	cerr << "Erro 3: N�o � poss�vel redimensionar o vetor.";
        	exit(3);
    	}
    	for (int i = 0; i < (n); i++)
		aux[i] = V[i];
    	delete[] V;
    	V = new int [++n];
    	if (V == NULL)
    	{
        	cerr << "Erro 3: N�o � poss�vel redimensionar o vetor.";
        	exit(3);
    	}
    	for (int i = 0; i < (n - 1); i++)
			V[i] = aux[i];
    	
		V[n - 1] = 0;
    	delete[] aux;
	}
	return;
}

int Vetor::len()
{
	return this->n;
}

void Vetor::add(int valor)
{
   realloc();
   V[n-1] = valor;
   return;
}

int Vetor::get(int i)
{
   if ((i < 0) || (i > n))
   {
      cerr << "Erro: Tentativa de acesso fora dos limites do vetor.\n";
      return 0;
   }
   else
      return V[i];
}

void Vetor::set(int i, int v)
{
   if ((i < 0) || (i > n))
   {
      cerr << "Erro: Tentativa de acesso fora dos limites do vetor.\n";
      cerr << "Atribui��o abortada.\n";
      return;
   }
   else
   {
      V[i] = v;
   }
}

int Vetor::operator[](int i) const
{
   if ((i < 0) || (i >= n))
   {
      cerr << "\nErro: Tentativa de acesso fora dos limites do vetor.\n";
      exit(5);
   }
   return V[i];
}

int &Vetor::operator[](int i)
{
   if ((i < 0) || (i >= n))
   {
      cerr << "\nErro: Tentativa de acesso fora dos limites do vetor.\n";
      exit (5);
   }
   return V[i];
}

void Vetor::escreve()
{
	cout <<"[";
	for (int i = 0; i < n; i++)
	{
		cout << V[i];
    	if (i < n - 1)
		cout << ", ";
	}
	cout << "]";
}

void Vetor::swap(int &a, int &b)
{
	int c = a;
	a = b;
	b = c;
}

void Vetor::BubbleSort()
{
	for (int i = 0; i < n - 1; i++)
    	for(int j = n - 1; j > i; j--)
			if (V[j] < V[j - 1])
				swap(V[j], V[j - 1]);
}

void Vetor:: ShakerSort()
{
	bool troca;
	
	do
	{
    	troca = false;
    	for (int i = (n - 1); i > 0; i--)
    	{
			if(V[i - 1] > V[i])
			{
				swap(V[i - 1], V[i]);
				troca = true;
			}
    	}
    	for (int i = 1; i < n; i++)
    	{
			if (V[i - 1] > V[i])
			{
				swap(V[i - 1], V[i]);
				troca = true;
			}
    	}
	} while (troca); // continua at� n�o haver mais trocas
}

void Vetor::InsertionSort()
{
	for (int i = 1; i < n; i++)
	{
		int aux = V[i];
    	int j = 0;
			for (j = i; (j > 0) && (aux < V[j-1]); j--)
        		V[j] = V[j - 1];
			
		V[j] = aux;
	}
}

void Vetor::SelectionSort()
{
	for (int i = 0; i < (n - 1); i++)
	{
    	// Encontra o menor elemento
    	int min = i;
    	for (int j = i + 1; j < n; j++)
        	if (V[j] < V[min])
        		min = j;
    	// troca a posi��o atual com o menor elemento do vetor
    	int aux = V[min];
    	V[min] = V[i];
    	V[i] = aux;
   }
}

void Vetor::ShellSort()
{
	const int MAXGAPS = 5;	// N�mero de gaps
	// const int FACTOR = 3;		// Multiplicador para encontrar os gaps
	int gaps[MAXGAPS] = {7, 5, 3, 2, 1};	// vetor com os gaps

 //  // preeenche o vetor com os gaps adequados
 //  for (int i = 0; i < MAXGAPS; i++)
 //     gaps[MAXGAPS - (i + 1)] = (FACTOR * i) + 1;

	for (int k = 0; k < MAXGAPS; k++)
	{
    	int gap = gaps[k];
    	for (int i = gap; i < n; i++)
    	{
			int x = V[i];
	 		for (int j = (i - gap); (j >= 0) && (x < V[j]); j -= gap)
        	{
				V[j + gap] = V[j];
				V[j] = x;
			}
    	}
	}
}

// Algoritmo de particao merge
void Vetor::merge(int low, int mid, int high)
{
	int n1 = mid - low + 1; 
	int n2 = high - mid;          
	int left[n1 + 1], right[n2 + 1];
	int i = 0, j = 0; // i e j locais � fun��o
	for (int i = 0; i < n1; i++) // i local ao la�o
		left[i] = this->V[low + i];
	for (int j = 0; j < n2; j++) // j local ao la�o
		right[j] = this->V[mid + 1 + j];
	left[n1] = INT_MAX;
	right[n2] = INT_MAX;
	
	for (int k = low; k <= high; k++)
		if (left[i] <= right[j])
			this->V[k] = left[i++];
		else
		{
			this->V[k] = right[j++];
		}
}

// algoritmo de ordenc�o mergesort
void Vetor::MergeSort(int low, int high)
{
	if (low < high)
	{
		int mid = (low + high) / 2;
		MergeSort(low, mid);
		MergeSort(mid + 1, high);
		merge(low, mid, high);
	}
}

// Algoritmo de parti��o para o QuickSort
int Vetor::partition(int low, int high)
{
	int pivot = this->V[low];
	int i = low - 1, j = high + 1;
	
	while (true)
	{
		do
		{
        	i++;
		} while (this->V[i] < pivot);
    	do
    	{
    		j--;
    	} while (this->V[j] > pivot);
		
    	if (i >= j)
    		return j;
		swap(this->V[i], this->V[j]);
	}
}

// Algoritmo de ordena��o QuickSort
void Vetor::QuickSort(int low, int high)
{
	if (low < high)
	{
    	int pi = partition(low, high);  
        QuickSort(low, pi);
        QuickSort(pi + 1, high);
    }
}

// Fun��o principal
int main()
{
   cout << "\n\n\n\t\tAlgoritmos de Ordena��o como M�todos de Classe\n\n\n";
   cout << "Quantos elementos deve ter o vetor? > ";
   int n = 0;
   cin >> n;
   cin.get();
   cout << "Criando um vetor de inteiros aleat�rio de tamanho " << n << ".\n";
   Vetor V(n);
   
   for (int i = 0; i < n; i++)
   {
      V[i] =  rand() % (11 * n);
      cout << ".";
   }	
   cout << "\nVetor criado: \n";
   
   /*************************
    * Ordena com BubbleSort *
    *************************/
	//V.escreve();
	//cout << endl;
	//cout << "Ordenando vetor com BubbleSort().\n";
	//V.BubbleSort();
	//V.escreve();
	//cout << endl;

	/*************************
    * Ordena com ShakerSort *
    *************************/
	//V.escreve();
	//cout << endl;
	//cout << "Ordenando vetor com ShakerSort().\n";
   	//V.ShakerSort();
	//V.escreve();
	//cout << endl;

	/***************************
    * Ordena com InsertionSort *
    ****************************/
	//V.escreve();
	//cout << endl;
	//cout << "Ordenando vetor com InsertionSort().\n";
   	//V.InsertionSort();
	//V.escreve();
	//cout << endl;

	/***************************
    * Ordena com SelectionSort *
    ****************************/
	//V.escreve();
	//cout << endl;
	//cout << "Ordenando vetor com SelectionSort().\n";
   	//V.SelectionSort();
	//V.escreve();
	//cout << endl;

	/*************************
    * Ordena com ShellSort   *
    *************************/
	//V.escreve();
	//cout << endl;
	//cout << "Ordenando vetor com ShellSort().\n";
   	//V.ShellSort();
	//V.escreve();
	//cout << endl;

	/*************************
    * Ordena com MergeSort   *
    *************************/
	//V.escreve();
	//cout << endl;
	//cout << "Ordenando vetor com MergeSort().\n";
   	//V.MergeSort(0, V.len()-1);
	//V.escreve();
	//cout << endl;

	/*************************
    * Ordena com QuickSort   *
    *************************/
	V.escreve();
	cout << endl;
	cout << "Ordenando vetor com QuickSort().\n";
   	V.QuickSort(0, V.len()-1);
	V.escreve();
	cout << endl;
}
