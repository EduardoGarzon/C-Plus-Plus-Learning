// Arquivo: Vetor.h
// Implementa: uma classe Vetor
// Autor: Prof. Josué Pereira de Castro
// Data: 13-07-2007

#include <iostream>
using namespace std;

template <class T>
class Vetor
{
   // Atributos privados
   private:
      int len; // armazena o comprimento
      T *vet;  // armazena os valores

   // métodos públicos
   public:
      Vetor(int size = 1); // construtor default inicializável
      Vetor(const Vetor<T> &V);  // construtor de cópia
      ~Vetor();		   // destruidor
      void fill(T valor);  // preenche o vetor com um valor especificado
      int length();  // retorna o tamanho do vetor

      // Operadores sobrecarregados
      
      // Atribuição
      Vetor<T> &operator =(const Vetor<T> &V); 

      // subscrito para leitura
      T operator [](int i) const;

      // Subscrito para escrita
      T &operator[](int i);

	  // operador de igualdade
      bool operator ==( const Vetor<T> &V ) const; 

	  // operador de diferença
      bool operator !=( const Vetor<T> &V ) const; 
      
      // Friends
      
      // entrada por console
      template <class Ta>
      friend istream &operator >>(istream &input, Vetor<Ta> &V);
      
      // Saída para console
      template <class Ta>
      friend ostream &operator <<(ostream &output, const Vetor<Ta> &V);

	  // Operador de soma com escalar à esquerda
	  template <class Ta>
      friend Vetor<Ta> operator +(Ta L, const Vetor<Ta> &R);

	  // Operador de soma com escalar à direita
	  template <class Ta>
      friend Vetor<Ta> operator +(const Vetor<Ta> &L, Ta R);

	  // Operador soma vetorial
	  template <class Ta>
      friend Vetor<Ta> operator +(const Vetor<Ta> &L, const Vetor<Ta> &R);

	  // Operador de subtração com escalar à esquerda
	  template <class Ta>
      friend Vetor<Ta> operator -(Ta L, const Vetor<Ta> &R);

	  // Operador de subtração com escalar à direita
	  template <class Ta>
      friend Vetor<Ta> operator -(const Vetor<Ta> &L, Ta R);

	  // Operador subtração vetorial
	  template <class Ta>
      friend Vetor<Ta> operator -(const Vetor<Ta> &L, const Vetor<Ta> &R);
};

//-------------------------------------------------------------------------
// Implementação dos métodos
//-------------------------------------------------------------------------

// Construtor default inicializável

template <class T>
Vetor<T>::Vetor(int size)
{
   //cout << "Executando construtor default inicializável\n";
   if (size < 0)
   {
      cout << "Erro: o vetor não pode ter tamanho negativo\n";
      exit(0);
   }
   else if (size == 0)
      this->vet = NULL;
   else
   {
      this->len = size;
      this->vet = new T[size];
      if (!this->vet)
      {
	 cout << "Erro: Memória não pode ser alocada.\n";
	 exit(0);
      }
   }
   return;
}

//-------------------------------------------------------------------------

// Construtor de Cópia

template <class T>
Vetor <T>::Vetor(const Vetor<T> &V)
{
   //cout << "Executando construtor de cópia.\n";
   this->len = V.len;
   this->vet = new T[this->len];
   if (!this->vet)
   {
      cout << "Erro: A Memória não pode ser alocada.\n";
      exit(0);
   }
   for (int i = 0; i < this->len; i++)
      this->vet[i] = V.vet[i];
   return;
}

//-------------------------------------------------------------------------

// Destruidor

template <class T>
Vetor<T>::~Vetor()
{
   //cout << "Executando destruidor.\n";
   if (this->vet)
      delete[] this->vet;
   return;
}

//-------------------------------------------------------------------------

// Método fill

template <class T>
void Vetor<T>::fill(T valor)
{
   for (int i = 0; i < this->len; i++)
      this->vet[i] = valor;
   return;
}

//-------------------------------------------------------------------------
// Método length
template <class T>
int Vetor<T>::length()
{
   return this->len;
}
//-------------------------------------------------------------------------

// Operador de atribuição
template <class T>
Vetor<T> &Vetor<T>::operator =(const Vetor<T> &V)
{
   // Testa a auto-atribuição
   if (this != &V)
   {
      // verifica se vet já está alocado
      if (this->vet)
	 delete[] vet;
      this->len = V.len;
      // realoca o vetor
      this->vet = new T[this->len];
      for (int i = 0; i < this->len; i++)
	 this->vet[i] = V.vet[i];
   }
   return (*this);
}

//-------------------------------------------------------------------------

template <class T>
T Vetor<T>::operator[](int i) const
{
   // Testa as dimensões
   if ((i < 0) || (i >= this->len))
   {
      cout << "Erro: tentativa de acesso fora dos limites do vetor.\n";
      exit (0);
   }
   return this->vet[i];
}

//-------------------------------------------------------------------------

template <class T>
T &Vetor<T>::operator[](int i)
{
   // Testa as dimensões
   if ((i < 0) || (i >= this->len))
   {
      cout << "Erro: tentativa de acesso fora dos limites do vetor\n";
      exit(0);
   }
   return (this->vet[i]);
}

//-------------------------------------------------------------------------
template <class T>
bool Vetor<T>::operator ==( const Vetor<T> &V ) const
{
   if ( this->len != V.len )
      return false; // arrays com diferentes números de elementos
   for ( int i = 0; i < this->len; i++ )
      if ( this->vet[ i ] != V.vet[ i ] )
         return false; // o conteúdo do Array não é igual
   return true; // Arrays são iguais
} 

//-------------------------------------------------------------------------
template <class T>
bool Vetor<T>::operator !=( const Vetor<T> &V ) const
{
   return !(*this == V); // Arrays são iguais
} 
//-------------------------------------------------------------------------

// Operador >>
template <class Ta>
istream &operator >>(istream &input, Vetor<Ta> &V)
{
   for (int i = 0; i < V.len; i++)
   {
      cout << "vet[" << i << "]: ";
      input >> V.vet[i];
   }
   return input;
}

//-------------------------------------------------------------------------

// operador <<
template <class Ta>
ostream &operator <<(ostream &output, const Vetor<Ta> &V)
{
   output << "[";
   for (int i = 0; i < V.len; i++)
   {
      if (i > 0)
	 output << ", ";
      output << V.vet[i];
   }
   output << "]";
   return output;
}

//-------------------------------------------------------------------------
// Operador de soma com escalar à esquerda
template <class Ta>
Vetor<Ta> operator +(Ta L, const Vetor<Ta> &R)
{
	Vetor<Ta> aux(R.len);
	for (int i = 0; i < R.len; i++)
		aux.vet[i] = L + R.vet[i];
	return aux;
}

//-------------------------------------------------------------------------
// Operador de soma com escalar à direita
template <class Ta>
Vetor<Ta> operator +(const Vetor<Ta> &L, Ta R)
{
	Vetor<Ta> aux(L.len);
	for (int i = 0; i < L.len; i++)
		aux.vet[i] = R + L.vet[i];
	return aux;
}

//-------------------------------------------------------------------------

// Operador de soma de vetores
template <class Ta>
Vetor<Ta> operator +(const Vetor<Ta> &L, const Vetor<Ta> &R)
{
	// Testa as dimensões
	if (L.len != R.len) 
	{
    	cout << "Erro: Dimensões são diferentes. Nao e possivel somar os vetores.\n";
    	exit(0);
	}
	// dimensões ok
	Vetor<Ta> S(L.len);
	for (int i = 0; i < L.len; i++)
		S.vet[i] = L.vet[i] + R.vet[i];
	return S;
}

//-------------------------------------------------------------------------
// Operador de subtração com escalar à esquerda
template <class Ta>
Vetor<Ta> operator -(Ta L, const Vetor<Ta> &R)
{
	Vetor<Ta> aux(R.len);
	for (int i = 0; i < R.len; i++)
		aux.vet[i] = L - R.vet[i];
	return aux;
}

//-------------------------------------------------------------------------
// Operador de soma com escalar à direita
template <class Ta>
Vetor<Ta> operator -(const Vetor<Ta> &L, Ta R)
{
	Vetor<Ta> aux(L.len);
	for (int i = 0; i < L.len; i++)
		aux.vet[i] = L.vet[i] - R;
	return aux;
}

//-------------------------------------------------------------------------

// Operador de soma de vetores
template <class Ta>
Vetor<Ta> operator -(const Vetor<Ta> &L, const Vetor<Ta> &R)
{
	// Testa as dimensões
	if (L.len != R.len) 
	{
    	cout << "Erro: Dimensões são diferentes. Nao e possivel somar os vetores.\n";
    	exit(0);
	}
	// dimensões ok
	Vetor<Ta> S(L.len);
	for (int i = 0; i < L.len; i++)
		S.vet[i] = L.vet[i] - R.vet[i];
	return S;
}
