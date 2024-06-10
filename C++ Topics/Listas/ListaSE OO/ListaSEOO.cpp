/*
    Implementacao de uma Lista Simples Encadeada Orientada a Objetos
*/

#include <iostream>
using namespace std;

// Declaracao da Classe Node
// Representa o nó
class IntSLLNode
{
public:
    // Constructor
    IntSLLNode()
    {
        prox = nullptr;
    }
    // Constructor Sobrecarregado
    IntSLLNode(int el, IntSLLNode *ptr = nullptr)
    {
        info = el;
        prox = ptr;
    }
    int info;         // Valor do nó
    IntSLLNode *prox; // Ponteiro para o objeto da classe, próximo nó
};

// Definicao da Classe Header
// Representa o Header da lista
class IntSLList
{
public:
    // Constructor
    IntSLList()
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
    IntSLLNode *topo, *resto;
};

// Procedimeto para inserir novo elemento no inicio da lista
// :: indica a definicao de uma função membro chamada addToTopo que pertence à classe IntSLList
void IntSLList::addToTopo(int el)
{
    // Cria novo nó
    // Chamada do Constructo Sobrecarregado
    // O novo nó aponta para o nó que estava no topo
    // Topo -> novo -> antigo -> NULL
    topo = new IntSLLNode(el, topo);
    if (resto == nullptr)
    {
        resto = topo;
    }
}

// Procedimento para inserir novo elemento no final da lista
void IntSLList::addToResto(int el)
{
    // Verifica se a lista nao esta vazia
    if (resto != nullptr)
    {
        // Insere novo nó no final da lista
        resto->prox = new IntSLLNode(el);
        // Atualiza o resto
        resto = resto->prox;
    }
    else
    {
        // Insere novo e unico nó para topo e resto
        topo = resto = new IntSLLNode(el);
    }
}

// Procedimento para inserir um elemento ordenado na lista
void IntSLList::addOrdered(int el)
{
    // Verifica se lista vazia ou se o elemento é menor que o do inicio
    if (topo == nullptr || el < topo->info)
    {
        // Inserir no início da lista ou quando a lista está vazia.
        topo = new IntSLLNode(el, topo);
        if (resto == nullptr)
        {
            resto = topo;
        }
    }
    else
    {
        IntSLLNode *tmp = topo;
        IntSLLNode *anterior = nullptr;

        // Percorre a lista até encontrar a posição de inserção.
        while (tmp != nullptr && el >= tmp->info)
        {
            anterior = tmp;
            tmp = tmp->prox;
        }

        // Insere o novo elemento entre anterior e tmp.
        if (tmp)
        {
            anterior->prox = new IntSLLNode(el, tmp);
        }
        else
        {
            // Insere novo elemento no final
            resto->prox = new IntSLLNode(el, nullptr);
            resto = resto->prox;
        }
    }
}

// Funcao para remover um elemento do inicio da lista
int IntSLList::deleteFromTopo()
{
    // Verifica se a lista esta vazia
    if (resto == nullptr && topo == nullptr)
    {
        cout << "Lista Vazia" << endl;
        return 0;
    }

    // No temporario
    IntSLLNode *tmp = topo;
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
    }
    // libera nó temporario que continha o valor a ser removido
    delete tmp;
    // Retorna o valor removido
    return valorRemovido;
}

// Funcao que deleta o ultimo elemento da lista
int IntSLList::deleteFromResto()
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
        // Nó temporario para percorrer a lista ate seu penultimo elemento
        IntSLLNode *tmp;
        // Armazena o ultimo elemento
        int valorRemovido = resto->info;
        // Percorre a lista ate seu penultimo elemento
        for (tmp = topo; tmp->prox != resto; tmp = tmp->prox)
        {
        }
        // Libera o ultimo no
        delete resto;
        // Atualiza o resto para o penultimo elemetno
        resto = tmp;
        // Atualiza o proximo do resto
        resto->prox = nullptr;
        // Retorna o valor removido
        return valorRemovido;
    }
}

// Funcao para remover qualquer elemento da lista
int IntSLList::deleteNode(int el)
{
    // Verifica se a lista esta vazia
    if (topo == nullptr && resto == nullptr)
    {
        cout << "Lista Vazia" << endl;
        return 0;
    }

    // No temporario
    IntSLLNode *tmp = topo;
    // Armazena o valor a ser removido
    int valorRemovido = topo->info;

    // Verifica se o elemento procurado é o primeiro
    if (el == tmp->info)
    {
        // Verifica se lista possui apenas um elemento
        if (topo == resto)
        {
            topo = resto = nullptr;
            delete tmp;
            return valorRemovido;
        }
        else
        {
            topo = topo->prox;
            delete tmp;
            return valorRemovido;
        }
    }
    else
    {
        // Percorre a lista ate o fim ou ate achar o elemento
        IntSLLNode *anterior = nullptr;
        while (el != tmp->info && tmp)
        {
            anterior = tmp;
            tmp = tmp->prox;
        }

        // Verifica se é o elemento procurado
        if (tmp && el == tmp->info)
        {
            anterior->prox = tmp->prox;
            // Atualiza resto caso seja o ultimo elemento
            if (!tmp->prox)
            {
                resto = anterior;
            }
            valorRemovido = tmp->info;
            delete tmp;
            return valorRemovido;
        }
    }

    // Retorna 0 caso elemento nao encontrado
    return 0;
}

// Procedimento para imprimir os elementos da lista
void IntSLList::printAll() const
{
    // Percorre a lista ate o fim
    for (IntSLLNode *tmp = topo; tmp != nullptr; tmp = tmp->prox)
    {
        cout << tmp->info << " ";
    }
    cout << endl;
}

int main()
{

    IntSLList myList; // Cria uma lista encadeada vazia

    return 0;
}
