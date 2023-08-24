/***************************************
 * Definição da classe Pessoa
 ***************************************/
#include <iostream>
#include <cstring>
using namespace std;

class Pessoa{
    private:
        int RG;
        int CPF;
        char Nome[31];
        char Endereco[41];
        char Telefone[13];
        
        public:
            Pessoa(); // Construtor default definido pelo programador
            Pessoa(const Pessoa &P); // construtor de cópia
            int getRG();
            int getCPF();
            char* getNome();
            char* getEndereco();
            char* getTelefone();
            void setRG();
            void setCPF();
            void setNome();
            void setEndereco();
            void setTelefone();
            friend ostream &operator <<(ostream &output, Pessoa &P);
            friend bool operator == (Pessoa P1, Pessoa P2);
            friend bool operator != (Pessoa P1, Pessoa P2);
};

// Declaração das funções da classe

// Construtor default
Pessoa::Pessoa() 
{
    RG = 0;
    CPF = 0;
    strcpy(Nome, "");
    strcpy(Endereco, "");
    strcpy(Telefone, "");
}

//Construtor de cópia
Pessoa::Pessoa(const Pessoa &P)
{
   RG = P.RG;
   CPF = P.CPF;
   strcpy(Nome, P.Nome);
   strcpy(Endereco, P.Endereco);
   strcpy(Telefone, P.Telefone);
}

int Pessoa::getRG() {
    return(RG);
}

int Pessoa::getCPF() {
    return(CPF);
}

char* Pessoa::getNome() {
    return(Nome);
}

char* Pessoa::getEndereco() {
    return(Endereco);
}

char* Pessoa::getTelefone() {
    return(Telefone);
}

void Pessoa::setRG() {
    cout << "Numero do RG?..>" ;
    cin >> RG;
}

void Pessoa::setCPF() {
    cout <<"Numero do CPF?.>";
    cin >> CPF;
}

void Pessoa::setNome() {
    cin.get(); // limpa o buffer
    cout << "Nome?..........>";
    cin.get(Nome, 31);
}

void Pessoa::setEndereco() {
    cin.get(); // limpa o buffer
    cout << "Endereço?......>";
    cin.get(Endereco, 41);
}
void Pessoa::setTelefone() {
    cin.get(); // limpa o buffer
    cout << "Telefone?......>";
    cin.get(Telefone, 13);
}

ostream &operator <<(ostream &output, Pessoa &P) {
    output << endl;
    output << "RG:\t\t" << P.getRG() << endl;
    output << "CPF:\t\t" << P.getCPF() << endl;
    output << "Nome:\t\t" << P.getNome() << endl;
    output << "Endereço:\t" << P.getEndereco() << endl;
    output << "Telefone:\t" << P.getTelefone() << endl;
    return output;
}

bool operator ==(Pessoa P1, Pessoa P2) {
    // Realiza a comparação entre dois objetos pessoa utilizando o atributo "nome" como chave.
    return strcmp(P1.getNome(), P2.getNome()) == 0;
}

bool operator != (Pessoa P1, Pessoa P2) {
    return !(P1 == P2);
}


template <class T>
class Node2 {
    private:
        T dado;         // dado armazenado no nó
        Node2 *previo;	// ponteiro para o nó anterior
        Node2 *proximo;	// ponteiro para o próximo nó
        
        public:
            Node2();	// construtor default
            Node2(Node2 *prev, const T &x, Node2 *next);    // construtor 
                                                            // inicializável
            void print();	// imprime o valor do nó
            T getDado();	// retorna o valor do dado;
            void setDado(T i);	// atribui o valor i ao nó atual;
            Node2 *getProximo(); // retorna o ponteiro para o próximo elemento;
            void setProximo(Node2 *L);	// seta o próximo nó
            Node2 *getPrevio();	// retorna o ponteiro do nó anterior;
            void setPrevio(Node2 *L);		// seta o valor do nó anterior;
};

/*********************************************
 * Implementação dos métodos da classe Node2 *
 *********************************************/

template <class T>
Node2<T>::Node2() {
    cout << "\nConstruindo um nó nulo...\n";
    dado = NULL;
    previo = NULL;
    proximo = NULL;
    cout << "\nNó Construido.\n";
}

template <class T>
Node2<T>::Node2(Node2 *prev, const T &x, Node2 *next) {
    cout << "\nConstruindo um nó inicializado...\n";
    dado = x;
    proximo = next;
    previo = prev;
    cout << "\nNó construído.\n";
}

template <class T>
void Node2<T>::print() {
    cout << dado;
}

template <class T>
T Node2<T>::getDado() {
    return dado;
}

template <class T>
void Node2<T>::setDado(T i) {
    dado = i;
}

template <class T>
Node2<T> *Node2<T>::getProximo() {
    return proximo;
}

template <class T>
void Node2<T>::setProximo(Node2 *L) {
    proximo = L;
}

template <class T>
Node2<T> *Node2<T>::getPrevio() {
    return previo;
}

template <class T>
void Node2<T>::setPrevio(Node2 *L) {
    previo = L;
}


/********************************
 * Declaração da classe ListaDE *
 ********************************/

template <class T>
class ListaDE {
    private:
        int len;		// mantém o comprimento da lista;
        Node2<T> *left;		// ponteiro para o inicio da lista;
        Node2<T> *right;	// ponteiro para o fim da lista;
        public:
            ListaDE();		// construtor default;
            ~ListaDE();		// destruidor;
            bool isEmpty();	// Verifica se a lista está vazia;
            bool isMember(T x);	// Verifica se um elemento faz parte da lista;
            int length();		// retorna o comprimento da lista;
            void print(int d);		// imprime a lista formatada.
                                        // O parâmetro d indica a direção:
                                        // 0 = normal, 1 = reversa
            void insertLeft(T x); // insere o elemento x na frente da lista;
            void insertRight(T x);	// insere um elemento no fim da lista;
            T removeLeft();	// remove o elemento no inicio da lista;
            T removeRight();	// remove o elemento no fim da lista;
};

/***********************************************
 * Implementação dos métodos da classe ListaDE *
 ***********************************************/

template <class T>
ListaDE<T>::ListaDE() {
    cout << "\nConstruindo a lista...\n";
    len = 0;
    left = right = NULL;
    cout << "Lista construída.";
}

template <class T>
ListaDE<T>::~ListaDE() {
    cout << "\nDestruindo a lista...\n";
    while(!isEmpty())
        removeLeft();
    cout << "\nLista Destruida.\n";
}

template <class T>
bool ListaDE<T>::isEmpty() {
    return (len == 0);
}

template <class T>
bool ListaDE<T>::isMember(T x) {
    Node2<T> *aux = left;
    while ((aux != NULL) && (aux->getDado() != x))
        aux = aux->getProximo();
    if (aux == NULL)
        return false;
    else
        return true;
}

template <class T>
int ListaDE<T>::length() {
    return len;
}

template <class T>
void ListaDE<T>::print(int d) {
    if (d == 0) // imprime em ordem normal
    {
        Node2<T> *p = left;
        cout << "{";
        while (p != NULL) {
            p->print();
            if (p->getProximo() != NULL)
                cout << ", ";
            p = p->getProximo();
        }
        cout << "}";
    }
    else	// imprime em ordem reversa
    {
        Node2<T> *p = right;
        cout << "{";
        while (p != NULL) {
            p->print();
            if (p->getPrevio() != NULL)
                cout << ", ";
            p = p->getPrevio();
        }
        cout << "}";
    }
}

template <class T>
void ListaDE<T>::insertLeft(T x) {
    if (left != NULL) {
        // já tem alguém na lista
        Node2<T> *aux = left;
        left = new Node2<T>(NULL, x, left);
        if (left == NULL) {
            cout << "\nErro 1: Memória insuficiente.\n";
            exit(1);
        }
        aux->setPrevio(left);
        if (right == NULL)
            right = left;
    }
    else
        // A lista está vazia
        left = right = new Node2<T>( NULL, x, NULL);
    len++;
}

template <class T>
void ListaDE<T>::insertRight(T x) {
    if (right != NULL) {
        Node2<T> *aux = new Node2<T>(right, x, NULL);
        if (aux == NULL) {
            cout << "\nErro 2: Memória Insuficiente.\n";
            exit(2);
        }
        right->setProximo(aux);
        right = right->getProximo();
    }
    else
        left = right = new Node2<T>( NULL, x, NULL);
    len++;
}

template <class T>
T ListaDE<T>::removeLeft() {
    T r = left->getDado();
    Node2<T> *tmp = left;
    if (left == right)
        left = right = NULL;
    else {
        left = left->getProximo();
        left->setPrevio(NULL);
    }
    delete tmp;
    len--;
    return r;
}

template <class T>
T ListaDE<T>::removeRight() {
    T r = right->getDado();
    if (left == right) {
        delete left;
        left = right = NULL;
    }
    else {
        Node2<T> *tmp = right->getPrevio();
        delete right;
        right = tmp;
        right->setProximo(NULL);
    }
    len--;
    return r;
}


// Programa TL2
// Uma implementação orientada à objetos de listas encadeadas
// Autor: Prof. Josué Pereira de Castro
// data: 02/05/2005

void clrscr() {
    for (int i = 0; i < 25; i++)
        cout << endl;
}


int main() {
    bool continua = true;
    ListaDE<Pessoa> *LPessoa = new ListaDE<Pessoa>;
    
    while(continua) {
        clrscr();
        cout << "\t\tPrograma para manipulação de listas duplamente encadeadas";
        cout << "\n\n";
        cout << "\n\t\t\tMenu principal\n\n";
        cout << "\n\t\t\t[0] Sair";
        cout << "\n\t\t\t[1] Ver Lista em ordem normal";
        cout << "\n\t\t\t[2] Ver lista em ordem inversa";
        cout << "\n\t\t\t[3] Inserir elemento à esquerda";
        cout << "\n\t\t\t[4] Inserir elemento à direita";
        cout << "\n\t\t\t[5] Remover elemento à esquerda";
        cout << "\n\t\t\t[6] Remover elemento à direita";
        cout << "\n\t\t\t[7] Verificar se um elemento faz parte da lista";
        cout << "\n\n\n\n\n\n\n\n\n\n\n";
        cout << "digite a sua opção > ";
        char opcao = 0;
        cin >> opcao;
        switch(opcao) {
            case '0': {
                continua = false;
                break;
            }
            case '1': {
                clrscr();
                cout << "Lista em ordem normal: ";
                LPessoa->print(0);
                cout << endl;
                cout << "Comprimento atual: " << LPessoa->length() << " Elementos.";
                cout << "\nTecle Enter para voltar ao menu...\n";
                getchar();
                getchar();
                break;
            }
            case '2': {
                clrscr();
                cout << "Lista em ordem reversa: ";
                LPessoa->print(1);
                cout << endl;
                cout << "Comprimento atual: " << LPessoa->length() << " Elementos.";
                cout << "\nTecle Enter para voltar ao menu...\n";
                getchar();
                getchar();
                break;
            }
            case '3': {
                clrscr();
                Pessoa x;
                x.setRG();
                x.setCPF();
                x.setNome();
                x.setEndereco();
                x.setTelefone();
                LPessoa->insertLeft(x);
                cout << "\nElemento inserido\n";
                cout << "\nTecle Enter\n";
                getchar();
                getchar();
                break;
            }
            case '4': {
                clrscr();
                Pessoa x;
                x.setRG();
                x.setCPF();
                x.setNome();
                x.setEndereco();
                x.setTelefone();
                LPessoa->insertRight(x);
                cout << "\nElemento inserido\n";
                cout << "\nTecle Enter\n";
                getchar();
                getchar();
                break;
            }
            case '5': {
                clrscr();
                cout << "Removendo o elemento " << LPessoa->removeLeft().getNome() << endl;
                cout << "Elemento removido.";
                cout << "\nTecle Enter\n";
                getchar();
                getchar();
                break;
            }
            case '6': {
                clrscr();
                cout << "Removendo o elemento " << LPessoa->removeRight().getNome() << endl;
                cout << "Elemento removido.";
                cout << "\nTecle Enter\n";
                getchar();
                getchar();
                break;
            }
            case '7': {
                clrscr();
                Pessoa x;
                cout << "Buscar Pessoa na lista" << endl;
                x.setNome();
                if (!LPessoa->isEmpty())
                    if (LPessoa->isMember(x))
                        cout << x.getNome() << " está na lista.\n\n";
                    else
                        cout << x.getNome() << " não está na lista\n\n";
                else
                    cout << "Lista está vazia.";
                cout << "\nTecle Enter...\n";
                getchar();
                getchar();
                break;
                
            }
            default: {
                cout << "Opção inválida. Tecle enter para continuar...";
                getchar();
                getchar();
            }
        }
    }
    delete LPessoa;
    return 0;
}
