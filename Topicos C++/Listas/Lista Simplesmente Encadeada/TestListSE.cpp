// Programa ExLista1.cpp
// Implementa algoritmos sobre listas simplesmente encadeadas implementados
// como uma classe.
// Autor: Josué Pereira de Castro

// Inclusão das bibliotecas necessárias


#include<iostream>
using namespace std;

/******************************************
 * Declaração da classe Node              *
 ******************************************/
using namespace std;
 
template <class T>
class Node
{
   private:
      T dado;
      Node *proximo;
   public:
      // Métodos Pblicos
      Node(); // Construtor default
      Node(const T &x, Node *next); // Construtor inicializavel
      void print(); // imprime o valor do nó
      T getDado(); // retorna o valor do dado;
      void setDado(T i); // atribui o valor i ao nó atual
      Node *getProximo(); // retorna o ponteiro para o próximo nó
      void setProximo(Node *L); // seta o proximo nó
};

/********************************************
 * Implementação dos métodos da classe Node *
 ********************************************/
#include <iostream>

template <class T>
Node<T>::Node()
{
   // cria um nó nulo
   cout << "\nConstruindo um novo nó nulo ...\n";
   dado = NULL;
   proximo = NULL;
}

template <class T>
Node<T>::Node(const T &x, Node *next)
{
   // cria um nó com contedo i, inserindo na cabeça da lista L.
   dado = x;
   proximo = next;
}

template <class T>
void Node<T>::print()
{
   cout << dado;
}

template <class T>
T Node<T>::getDado()
{
   return dado;
}

template <class T>
void Node<T>::setDado(T i)
{
   dado = i;
}

template <class T>
Node<T> *Node<T>::getProximo()
{
   return proximo;
}

template <class T>
void Node<T>::setProximo (Node *L)
{
   proximo = L;
}

/**********************
 * Fim da Classe Node *
 **********************/

/********************************
 * Declaração da classe ListaSE *
 ********************************/
template <class T>
class ListaSE
{
   private:
      int len;         // mantém o comprimento da lista
      Node<T> *left;  // ponteiro para o início da lista
      Node<T> *right; // ponteiro para o fim da lista
     
   public:
      ListaSE();    // Construtor default
      ~ListaSE(); // Destruidor
     
      // Métodos Auxiliares
      bool isEmpty();    // retorna true se a lista está vazia
      Node<T>* isMember(T x);    // verifica se o elemento x é membro da lista
                         // e false caso contrário
      int length();    // retorna o comprimento da lista
      void print();  // Método para imprimir a lista formatada
      void insertLeft(T x);     // insere um elemento na esquerda da                                                  //lista
      void insertRight(T x);  // insere um elemento na direita da
                                         //lista
      T removeLeft();        // remove o dado no início da lista e retorna o
                                 // elemento removido
      T removeRight();    // remove o dado no fim da lista e retorna o
                                 // elemento removido

};

/***********************************************
 * Implementação dos métodos da Classe ListaSE *
 ***********************************************/
template <class T>
ListaSE<T>::ListaSE()
{
   cout << "\nConstruindo a lista...\n";
   len = 0;
   left = right = NULL;
    cout << "Lista construída.";
}

template <class T>
ListaSE<T>::~ListaSE()
{
   cout << "\nDestruindo a lista...\n";
   while (!isEmpty())
   {
      removeLeft();
   }
   cout << "\nLista Destruida.\n";
}

template <class T>
bool ListaSE<T>::isEmpty()
{
   return (len == 0);
}

template <class T>
Node<T>* ListaSE<T>::isMember(T x)
{
   Node<T> *aux = left;
   while ((aux != NULL) && (aux->getDado() != x))
      aux = aux->getProximo();
   return aux;
}

template <class T>
int ListaSE<T>::length()
{
   return len;
}

template<class T>
void ListaSE<T>::print()
{
   Node<T> *p;
   p = left;
   cout << "{";
   while (p!=NULL)
   {
      p->print();
      if (p->getProximo() != NULL)
         cout << ", ";
      p = p->getProximo();
   }
   cout << "}";
}

template <class T>
void ListaSE<T>::insertLeft(T x)
{
   left  = new Node<T>(x, left);
   if (left == NULL)
   {
      cout << "Erro 1: Não é possível inserir mais um nó na lista";
      exit(1);
   }
   else
   {
      len++;
      if (right == NULL)
         right = left;
        
   }
}

template <class T>
void ListaSE<T>::insertRight(T x)
{
   if (right != NULL)
   {
      Node<T> *aux = new Node<T>(x, NULL);
      if (aux == NULL)
      {
         cout << "Erro 2: Não é possível inserir mais um nó na lista";
         exit(1);
      }
      right->setProximo(aux);
      right = right->getProximo();
   }
   else
      left = right = new Node<T>(x, NULL);
   len++;
}

template <class T>
T ListaSE<T>::removeLeft()
{
   T r = left->getDado();
   Node<T> *tmp = left;
   if (left == right)
      left = right = NULL;
   else
      left = left->getProximo();
   delete tmp;
   len--;
   return r;   
}

template <class T>
T ListaSE<T>::removeRight()
{
   T r = right->getDado();
   if (left == right)
   {
      delete left;
      left = right = NULL;
   }
   else
   {
      Node<T> *tmp;
      tmp = left;
      while(tmp->getProximo() != right)
         tmp = tmp->getProximo();
      delete right;
      right = tmp;
      right->setProximo(NULL);
   }   
   len--;
   return r;
}

/*************************
 * Fim da classe ListaSE *
 *************************/

void clrscr() {
    for (int i = 0; i < 25; i++)
        cout << endl;
}

int main() {
    ListaSE <int> L;
    while (true) {
        clrscr();
        cout << "\t\tPrograma para Manipulação de Listas\n\n\n\n";
        cout << "\n\t\t\tMenu principal\n\n";
        cout << "\n\t\t\t[0] Sair";
        cout << "\n\t\t\t[1] Ver lista";
        cout << "\n\t\t\t[2] Inserir elemento à esquerda";
        cout << "\n\t\t\t[3] Inserir elemento à direita";
        cout << "\n\t\t\t[4] Remover elemento à esquerda";
        cout << "\n\t\t\t[5] Remover elemento à direita";
        cout << "\n\t\t\t[6] Verificar se um elemento faz parte da lista";
        cout << "\n\n\n\n\n\n\n\n";
        cout << "Digite a sua Opção > ";
        char opcao = '\0';
        cin >> opcao;
        switch (opcao) {
            case '0': {
                return(0);
                break;
            }
            case '1': {
                clrscr();
                cout << "Lista: ";
                L.print();
                cout << endl;
                cout << "Comprimento da lista: " << L.length()
                << " elementos.\n";
                cout << "\nTecle enter para voltar ao menu...\n";
                getchar();
                getchar();
                break;
            }
            case '2': {
                clrscr();
                cout << "Digite um inteiro >> ";
                int x = 0;
                cin >> x;
                L.insertLeft(x);
                cout << "Elemento inserido!\n";
                cout << "Tecle enter\n";
                getchar();
                getchar();
                break;
            }
            case '3': {
                clrscr();
                cout << "Digite um inteiro >> ";
                int x = 0;
                cin >> x;
                L.insertRight(x);
                cout << "Elemento inserido!\n";
                cout << "Tecle Enter\n";
                getchar();
                getchar();
                break;
            }
            case '4': {
                clrscr();
                cout << "\nRemovendo elemento à esquerda da lista\n";
                if (!L.isEmpty())
                    cout << "\nRemovendo elemento " << L.removeLeft()
                    << " da lista";
                else
                    cout << "\nLista está vazia.\n";
                cout << "\nTecle Enter...\n";
                getchar();
                getchar();
                break;
            }
            case '5': {
                clrscr();
                cout << "\nRemovendo elemento à direita da lista\n";
                if (!L.isEmpty())
                    cout << "\nRemovendo elemento " << L.removeRight()
                    << " da lista";
                else
                    cout << "\nLista está vazia.\n";
                cout << "\nTecle Enter...\n";
                getchar();
                getchar();
                break;
            }
            case '6': {
                clrscr();
                int x = 0;
                cout << "Digite um inteiro: ";
                cin >> x;
                if (!L.isEmpty())
                    if (L.isMember(x))
                        cout << x << " está na lista.\n\n";
                    else
                        cout << x << " não está na lista\n\n";
                else
                    cout << "Lista está vazia.";
                cout << "\nTecle Enter...\n";
                getchar();
                getchar();
                break;
            }
            default: {
                clrscr();
                cout << "Opção inválida!\n tecle enter...";
                getchar();
                getchar();
            }
        }
    }
}
