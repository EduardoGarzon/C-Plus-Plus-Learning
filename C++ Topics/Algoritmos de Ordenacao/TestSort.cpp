// Programa TestSort.cpp
// Implementa algoritmos de ordenação como templates.

#include <iostream>
using namespace std;

template <class T>
void escreve(T V[], int n)
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

/*template <class T>
void swap(T &x, T &y)
{
	T aux = x;
	x = y;
	y = aux;
} */

template <class T>
int searchSeq(T elem, T dados[], int n)
{
	int i;
	for (i = 0; (i < n) && (dados[i] != elem); i++)
		;
	if (i == n) // Não achou.
		return -1;
	else
		return i;
}

template <class T>
void BubbleSort(T dados[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = n - 1; j > i; j--)
			if (dados[j] < dados[j - 1])
				swap(dados[j], dados[j - 1]);
}

template <class T>
void ShakerSort(T dados[], int n)
{
	bool troca;
	do
	{
		troca = false;
		for (int i = (n - 1); i > 0; i--)
		{
			if (dados[i - 1] > dados[i])
			{
				swap(dados[i - 1], dados[i]);
				troca = true;
			}
		}
		for (int i = 1; i < n; i++)
		{
			if (dados[i - 1] > dados[i])
			{
				swap(dados[i - 1], dados[i]);
				troca = true;
			}
		}
	} while (troca); // Continua até não haver mais trocas.
}

template <class T>
void InsertionSort(T dados[], int n)
{
	for (int i = 1; i < n; i++)
	{
		T aux = dados[i];
		int j = 0;
		for (j = i; (j > 0) && (aux < dados[j - 1]); j--)
			dados[j] = dados[j - 1];
		dados[j] = aux;
	}
}

template <class T>
void SelectionSort(T dados[], int n)
{
	for (int i = 0; i < (n - 1); i++)
	{
		// Encontra o menor elemento.
		int min = i;
		for (int j = i + 1; j < n; j++)
			if (dados[j] < dados[min])
				min = j;

		// Troca a posição atual com o menor elemento do vetor.
		T aux = dados[min];
		dados[min] = dados[i];
		dados[i] = aux;
	}
}

template <class T>
void ShellSort(T dados[], int n)
{
	const int MAXGAPS = 1; // Número de gaps.
	const int FACTOR = 1;  // Multiplicador para encontrar os gaps.
	int gaps[MAXGAPS];	   // Vetor com os gaps.

	// Preeenche o vetor com os gaps adequados.
	for (int i = 0; i < MAXGAPS; i++)
		gaps[MAXGAPS - (i + 1)] = (FACTOR * i) + 1;

	for (int k = 0; k < MAXGAPS; k++)
	{
		int gap = gaps[k];
		for (int i = gap; i < n; i++)
		{
			T x = dados[i];
			for (int j = (i - gap); (j >= 0) && (x < dados[j]); j -= gap)
			{
				dados[j + gap] = dados[j];
				dados[j] = x;
			}
		}
	}
}

int main()
{
	cout << "\n\t\t\tAlgoritmos de Ordenação\n\n";
	cout << "Quantos elementos deve ter o vetor? > ";
	int n = 0;
	cin >> n;
	cin.get();

	cout << "Alocando um vetor de tamanho " << n << " de inteiros aleatoriamente: \n";

	int *V = new int[n];

	for (int i = 0; i < n; i++)
	{
		V[i] = rand() % (11 * n);
		cout << ".";
	}

	cout << "\nVetor criado: \n";
	escreve(V, n);

	cout << "\n\nOrdenando o vetor com :\n";
	BubbleSort(V, n);

	cout << "Vetor ordenado: \n";
	escreve(V, n);

	cout << "\nTecle [ENTER]...";
	cin.get();

	delete[] V;

	cout << endl;
	cout << "\nAlocando um vetor de tamanho " << n << " de floats aleatoriamente: \n";

	float *V1 = new float[n];

	for (int i = 0; i < n; i++)
	{
		V1[i] = rand() % (11 * n);
		cout << ".";
	}

	cout << "\nVetor criado: \n";
	escreve(V1, n);

	cout << "\n\nOrdenando o vetor com :\n";
	BubbleSort(V1, n);

	cout << "Vetor ordenado: \n";
	escreve(V1, n);

	cout << "\nTecle [ENTER]...";
	cin.get();
	cout << "Testando a busca seqüencial\n";

	float a = rand() % (11 * n);

	cout << "Procurando por " << a << endl;

	int b = searchSeq(a, V1, n);

	if (b != -1)
	{
		cout << a << " está no vetor, na posição " << b << endl;
	}
	else
	{
		cout << a << " não está no vetor" << endl;
	}

	delete[] V1;

	cout << endl;

	return 0;
}
