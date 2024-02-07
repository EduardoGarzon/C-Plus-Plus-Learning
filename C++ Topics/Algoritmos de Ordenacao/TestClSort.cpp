// Programa TestClSort.cpp.
// Testa os algoritmos de ordenacao como metodos de classe.

#include <iostream>
#include <cstdlib>
#include <climits>
using namespace std;

class Vetor
{
private:
	int n;									// O numero de elementos do vetor.
	int *V;									// A estrutura que armazena os elementos.
	void swap(int &a, int &b);				// Metodo auxiliar para troca.
	void realloc();							// Metodo auxiliar para realocar o vetor V.
	void merge(int low, int mid, int high); // Algoritmo de recombinacao para MergeSort.
	int partition(int low, int high);		// Algoritmo de particao para o QuickSort.

public:
	// Construtores e destruidores
	Vetor();			   // Construtor default.
	Vetor(int tam);		   // Construtor com tamanho definido.
	Vetor(const Vetor &A); // Construtor de copia.
	~Vetor();			   // Destruidor.

	// Outros metodos
	int len();					 // retorna o numero de elementos do vetor.
	void add(int valor);		 // Adiciona mais uma posicao ao final do vetor e
								 // Lhe atribui "valor".
	int get(int i);				 // Obtem o valor armazenado na posicao i do vetor.
	void set(int i, int v);		 // Seta o valor v na posicao i do vetor.
	int operator[](int i) const; // Sobrecarga do operador [] para leitura.
	int &operator[](int i);		 // Sobrecarga do operador [] para escrita.
	void escreve();				 // Escreve o vetor.

	// Metodos de ordenacao
	void BubbleSort();				   // Ordenacao pelo algoritmo da bolha.
	void ShakerSort();				   // Ordenacao pelo metodo oscilante oscilante.
	void InsertionSort();			   // Ordenacao pelo algoritmo de insercao.
	void SelectionSort();			   // Ordenacao pelo algoritmo de selecao.
	void ShellSort();				   // Ordenacao pelo algoritmo Shell.
	void MergeSort(int low, int high); // Ordenacao pelo algoritmo MergeSort.
	void QuickSort(int low, int high); // Ordenacao pelo algoritmo QuickSort.
};

// Implementacao dos metodos da classe Vetor

Vetor::Vetor()
{
	// Construtor default
	cout << "Construtor default construindo vetor...\n";
	n = 0;
	V = NULL;
	cout << "Vetor construido.\n";
}

Vetor::Vetor(int tam)
{
	cout << "Construtor inicializavel construindo vetor...\n";
	if (tam < 0)
	{
		cerr << "Erro: o numero de elementos nao pode ser negativo.\n";
		cerr << "Ajustando numero de elementos para zero.\n";
		n = 0;
		V = NULL;
	}
	else
	{
		n = tam;
		V = new int[n];
		if (V == NULL)
		{
			cerr << "Erro 1: Nao e possivel construir um vetor com tamanho\n ";
			cerr << n << ".";
			exit(1);
		}
		else
		{
			for (int i = 0; i < n; i++)
				V[i] = 0;
		}
	}
	cout << "Vetor construido\n";
}

Vetor::Vetor(const Vetor &A)
{
	cout << "Construtor de copia construindo Vetor...\n";
	this->n = A.n;
	V = new int[this->n];
	if (V == NULL)
	{
		cerr << "Erro 2: Nao e possivel criar a copia do vetor.";
		exit(2);
	}
	for (int i = 0; i < this->n; i++)
	{
		this->V[i] = A.V[i];
	}
	cout << "Vetor construido.";
}

Vetor::~Vetor()
{
	cout << "Destruindo Vetor...\n";
	delete[] V;
	cout << "Vetor destruido\n";
}

void Vetor::realloc()
{
	if (n == 0) // Nao ha elementos no vetor;
	{
		V = new int[++n];
		if (V == NULL) // Alocacao falhou
		{
			cerr << "Erro 3: Nao e possivel redimensionar o vetor.";
			exit(3);
		}
	}
	else
	{
		int *aux = new int[n];
		if (aux == NULL)
		{
			cerr << "Erro 3: Nao e possivel redimensionar o vetor.";
			exit(3);
		}
		for (int i = 0; i < (n); i++)
			aux[i] = V[i];
		delete[] V;
		V = new int[++n];
		if (V == NULL)
		{
			cerr << "Erro 3: Nao e possivel redimensionar o vetor.";
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
	V[n - 1] = valor;
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
		cerr << "Atribuicao abortada.\n";
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
		exit(5);
	}
	return V[i];
}

void Vetor::escreve()
{
	cout << "[";
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
		for (int j = n - 1; j > i; j--)
			if (V[j] < V[j - 1])
				swap(V[j], V[j - 1]);
}

void Vetor::ShakerSort()
{
	bool troca;

	do
	{
		troca = false;
		for (int i = (n - 1); i > 0; i--)
		{
			if (V[i - 1] > V[i])
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
	} while (troca); // Continua ate nao haver mais trocas
}

void Vetor::InsertionSort()
{
	for (int i = 1; i < n; i++)
	{
		int aux = V[i];
		int j = 0;
		for (j = i; (j > 0) && (aux < V[j - 1]); j--)
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
	const int MAXGAPS = 5; // Numero de gaps
	// const int FACTOR = 3;		// Multiplicador para encontrar os gaps
	int gaps[MAXGAPS] = {7, 5, 3, 2, 1}; // Vetor com os gaps

	//  // Preeenche o vetor com os gaps adequados
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
	int i = 0, j = 0; // i e j locais a funcao

	for (int i = 0; i < n1; i++) // i local ao laco
		left[i] = this->V[low + i];

	for (int j = 0; j < n2; j++) // j local ao laco
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

// Algoritmo de ordencao mergesort
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

// Algoritmo de particao para o QuickSort
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

// Algoritmo de ordenacao QuickSort
void Vetor::QuickSort(int low, int high)
{
	if (low < high)
	{
		int pi = partition(low, high);
		QuickSort(low, pi);
		QuickSort(pi + 1, high);
	}
}

// Funcao principal
int main()
{
	cout << "\n\n\n\t\tAlgoritmos de Ordenacao como Metodos de Classe\n\n\n";

	cout << "Quantos elementos deve ter o vetor? > ";
	int n = 0;
	cin >> n;
	cin.get();

	cout << "Criando um vetor de inteiros aleat�rio de tamanho " << n << ".\n";

	Vetor V(n);

	for (int i = 0; i < n; i++)
	{
		V[i] = rand() % (11 * n);
		cout << ".";
	}
	cout << "\nVetor criado: \n";

	/*************************
	 * Ordena com BubbleSort *
	 *************************/
	// V.escreve();
	// cout << endl;
	// cout << "Ordenando vetor com BubbleSort().\n";
	// V.BubbleSort();
	// V.escreve();
	// cout << endl;

	/*************************
	 * Ordena com ShakerSort *
	 *************************/
	// V.escreve();
	// cout << endl;
	// cout << "Ordenando vetor com ShakerSort().\n";
	// V.ShakerSort();
	// V.escreve();
	// cout << endl;

	/***************************
	 * Ordena com InsertionSort *
	 ****************************/
	// V.escreve();
	// cout << endl;
	// cout << "Ordenando vetor com InsertionSort().\n";
	// V.InsertionSort();
	// V.escreve();
	// cout << endl;

	/***************************
	 * Ordena com SelectionSort *
	 ****************************/
	// V.escreve();
	// cout << endl;
	// cout << "Ordenando vetor com SelectionSort().\n";
	// V.SelectionSort();
	// V.escreve();
	// cout << endl;

	/*************************
	 * Ordena com ShellSort   *
	 *************************/
	// V.escreve();
	// cout << endl;
	// cout << "Ordenando vetor com ShellSort().\n";
	// V.ShellSort();
	// V.escreve();
	// cout << endl;

	/*************************
	 * Ordena com MergeSort   *
	 *************************/
	// V.escreve();
	// cout << endl;
	// cout << "Ordenando vetor com MergeSort().\n";
	// V.MergeSort(0, V.len()-1);
	// V.escreve();
	// cout << endl;

	/*************************
	 * Ordena com QuickSort   *
	 *************************/
	V.escreve();

	cout << endl;
	cout << "Ordenando vetor com QuickSort().\n";

	V.QuickSort(0, V.len() - 1);

	V.escreve();
	cout << endl;

	return 0;
}
