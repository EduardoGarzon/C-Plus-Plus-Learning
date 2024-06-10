/*
    Implementacao de uma Lista Duplamente Encadeada Orientada a Objetos
*/

#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
using namespace std;

// Declaracao da Classe Node
// Representa o nó
class IntDLLNode
{
public:
    // Constructor
    IntDLLNode()
    {
        prox = nullptr;
        anterior = nullptr;
    }
    // Constructor Sobrecarregado
    IntDLLNode(int el, IntDLLNode *ptrP = nullptr, IntDLLNode *ptrA = nullptr)
    {
        info = el;
        prox = ptrP;
        anterior = ptrA;
    }
    int info;             // Valor do nó
    IntDLLNode *prox;     // Ponteiro para o objeto da classe, próximo nó
    IntDLLNode *anterior; // Ponteiro para o objeto da classe, nó anterior
};

// Definicao da Classe Header
// Representa o Header da lista
class IntDLList
{
public:
    // Constructor
    IntDLList()
    {
        topo = resto = nullptr;
    }
    // Verifica se a lista esta vazia
    int isEmpty()
    {
        return topo == nullptr;
    }

    // Prototipos da Funcoes/Procedimentos da lista
    void addToTopo(int);
    void addToResto(int);
    void addOrdered(int);
    int deleteFromTopo();
    int deleteFromResto();
    int deleteNode(int);
    bool isInList(int) const;
    void printAll() const;

private:
    // Ponteiros para o inicio e o fim da lista
    IntDLLNode *topo, *resto;
};

// Procedimeto para inserir novo elemento no inicio da lista
// :: indica a definicao de uma função membro chamada addToTopo que pertence à classe IntDLList
void IntDLList::addToTopo(int el)
{
    // Cria novo nó
    // Chamada do Constructo Sobrecarregado
    // O novo nó aponta para o nó que estava no topo
    // Topo -> novo -> antigo -> NULL
    topo = new IntDLLNode(el, topo, nullptr);
    if (resto == nullptr)
    {
        resto = topo;
    }
}

// Procedimento para inserir novo elemento no final da lista
void IntDLList::addToResto(int el)
{
    // Verifica se a lista nao esta vazia
    if (resto != nullptr)
    {
        // Insere novo nó no final da lista
        resto->prox = new IntDLLNode(el, nullptr, resto);
        // Atualiza o resto
        resto = resto->prox;
    }
    else
    {
        // Insere novo e unico nó para topo e resto
        topo = resto = new IntDLLNode(el, nullptr, nullptr);
    }
}

// Procedimento para inserir um elemento ordenado na lista
void IntDLList::addOrdered(int el)
{
    // Verifica se lista vazia ou se o elemento é menor que o do inicio
    if (topo == nullptr || el < topo->info)
    {
        // Inserir no início da lista ou quando a lista está vazia.
        topo = new IntDLLNode(el, topo, nullptr);
        if (resto == nullptr)
        {
            resto = topo;
        }
    }
    else
    {
        IntDLLNode *tmp = topo;

        // Percorre a lista até encontrar a posição de inserção.
        while (tmp != nullptr && el >= tmp->info)
        {
            tmp = tmp->prox;
        }

        if (tmp)
        {
            // Insere o novo elemento entre anterior e tmp.
            IntDLLNode *novo_no = new IntDLLNode(el, tmp, tmp->anterior);
            tmp->anterior = novo_no;
            if (novo_no->anterior)
            {
                novo_no->anterior->prox = novo_no;
            }
            else
            {
                topo = novo_no; // Se for o novo topo
            }
        }
        else
        {
            // Insere novo elemento no final da lista
            resto->prox = new IntDLLNode(el, nullptr, resto);
            resto = resto->prox;
        }
    }
}

// Funcao para remover um elemento do inicio da lista
int IntDLList::deleteFromTopo()
{
    // Verifica se a lista esta vazia
    if (resto == nullptr && topo == nullptr)
    {
        cout << "Lista Vazia" << endl;
        return 0;
    }

    // Armazena o valor a ser removido
    int valorRemovido = topo->info;

    // Verifica se a lista tinha apenas um elemento
    if (topo == resto)
    {
        topo = resto = nullptr;
    }
    else
    {
        // Topo aponta para o proximo no
        topo = topo->prox;
        delete topo->anterior;
        topo->anterior = nullptr;
    }
    // Retorna o valor removido
    return valorRemovido;
}

// Funcao que deleta o ultimo elemento da lista
int IntDLList::deleteFromResto()
{
    // Verifica se a lista esta vazia
    if (resto == nullptr && topo == nullptr)
    {
        cout << "Lista Vazia" << endl;
        return 0;
    }

    // Verifica se a lista possui apenas um elemento
    if (topo == resto)
    {
        // Copia o valor a ser removido
        int valorRemovido = topo->info;
        // Libera o topo
        delete topo;
        // Atualiza topo e reto
        topo = resto = nullptr;
        // Retorna o valor removido
        return valorRemovido;
    }
    else
    {
        // Armazena o valor removido
        int valorRemovido = resto->info;
        // Nó temporário para o nó anterior ao último elemento
        IntDLLNode *tmp = resto->anterior;
        // Libera o último nó
        delete resto;
        // Atualiza o ponteiro 'prox' do nó anterior ao último elemento
        tmp->prox = nullptr;
        // Atualiza o ponteiro 'anterior' do novo último elemento
        resto = tmp;
        // Retorna o valor removido
        return valorRemovido;
    }
}

// Funcao para deletar qualquer elemento da lista
int IntDLList::deleteNode(int el)
{
    // Verifica se a lista está vazia
    if (topo == nullptr && resto == nullptr)
    {
        cout << "Lista Vazia" << endl;
        return 0;
    }

    // No temporário
    IntDLLNode *tmp = topo;
    // Armazena o valor a ser removido
    int valorRemovido = int(NULL);

    // Verifica se o elemento procurado é o primeiro
    if (el == tmp->info)
    {
        // Armazena o valor
        valorRemovido = topo->info;

        // Verifica se lista possui apenas um elemento
        if (topo == resto)
        {
            delete topo;
            topo = resto = nullptr;
        }
        else
        {
            topo = topo->prox;
            topo->anterior = nullptr;
            delete tmp;
        }
    }
    else
    {
        // Percorre a lista até o fim ou até encontrar o elemento
        while (tmp != nullptr && el != tmp->info)
        {
            tmp = tmp->prox;
        }

        // Verifica se o elemento foi encontrado
        if (tmp != nullptr)
        {
            valorRemovido = tmp->info;

            // Atualiza os ponteiros 'anterior' e 'prox' dos nós adjacentes
            tmp->anterior->prox = tmp->prox;
            if (tmp->prox)
            {
                tmp->prox->anterior = tmp->anterior;
            }
            else
            {
                // Se o nó removido era o último nó, atualize 'resto'
                resto = tmp->anterior;
            }

            // Libera o nó removido
            delete tmp;
        }
    }

    return valorRemovido;
}

// Procedimento para imprimir os elementos da lista
void IntDLList::printAll() const
{
    if (topo != nullptr && resto != nullptr)
    {
        // Percorre a lista ate o fim
        for (IntDLLNode *tmp = topo; tmp != nullptr; tmp = tmp->prox)
        {
            cout << tmp->info << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "Lista Vazia" << endl;
    }
}

// Funcao para ler valores de entrada
int readValue()
{
    int value = 0;
    cout << "Informe um valor: ";
    cin >> value;
    fflush(stdin);
    return value;
}

// Procedimento para interagir com a lista pelo menu de opcoes
void menu()
{
    int op = 0, value = 0;
    IntDLList myList;

    do
    {
        value = int(NULL);

        system("cls");

        cout << "[0] -> Sair" << endl;
        cout << "[1] -> Inserir Inicio" << endl;
        cout << "[2] -> Inserir Final" << endl;
        cout << "[3] -> Inserir Ordenado" << endl;
        cout << "[4] -> Remover Inicio" << endl;
        cout << "[5] -> Remover Final" << endl;
        cout << "[6] -> Remover Elemento" << endl;
        cout << "[7] -> Exibir Lista" << endl;
        cin >> op;
        fflush(stdin);

        system("cls");

        switch (op)
        {
        case 0:
            cout << "Encerrando Programa..." << endl;
            Sleep(5);
            break;
        case 1:
            value = readValue();
            myList.addToTopo(value);
            getchar();
            break;
        case 2:
            value = readValue();
            myList.addToResto(value);
            getchar();
            break;
        case 3:
            value = readValue();
            myList.addOrdered(value);
            getchar();
            break;
        case 4:
            value = myList.deleteFromTopo();
            if (value)
            {
                cout << "Valor removido do topo: " << value << endl;
            }
            getchar();
            break;
        case 5:
            value = myList.deleteFromResto();
            if (value)
            {
                cout << "Valor removido do resto: " << value << endl;
            }
            getchar();
            break;
        case 6:
            value = readValue();
            value = myList.deleteNode(value);
            if (value)
            {
                cout << "Valor removido: " << value << endl;
            }
            getchar();
            break;
        case 7:
            myList.printAll();
            getchar();
            break;
        default:
            cout << "Opcao Invalida Tente Novamente!" << endl;
            break;
        }
    } while (op != 0);
}

int main()
{
    menu();

    system("pause");
    return 0;
}
