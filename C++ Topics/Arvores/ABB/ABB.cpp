/**
 * @file ABB.cpp
 * @author Luiz Eduardo Garzon.
 * @brief Árvore Binária Balanceada Estaticamente.
 * @version 0.1
 * @date 2024-02-16
 *
 * @copyright Copyright (c) 2024
 */

#if defined(_WIN32) || defined(_WIN64)
#define limpar_tela "cls"
#else
#define limpar_tela "clear"
#endif

#include <iostream>
#include <cmath>

// ---------- LISTA SIMPLES ENCADEDA PARA BALANCEAMENTO DA ARVORE ----------

// Classe NoLista.
class NoLista
{
private:
    NoLista *dir;
    int dadoNo;

public:
    // Construtor default.
    NoLista()
    {
        dir = nullptr;
        dadoNo = 0;
    }

    // Construtor Parametrizado.
    NoLista(NoLista *dir = nullptr, int dadoNo = 0)
    {
        this->dir = dir;
        this->dadoNo = dadoNo;
    }

    NoLista *getNoDir()
    {
        return this->dir;
    }

    void setNoDir(NoLista *dir)
    {
        this->dir = dir;
    }

    int getDadoLista()
    {
        return this->dadoNo;
    }
};

class Lista
{
private:
    NoLista *topo, *calda;

public:
    Lista()
    {
        this->topo = this->calda = nullptr;
        size = 0;
    }

    bool isEmpty()
    {
        return topo == nullptr ? true : false;
    }

    int size;

    NoLista *getTopo()
    {
        return this->topo;
    }

    void setTopo(NoLista *no)
    {
        this->topo = no;
    }

    NoLista *getCalda()
    {
        return this->calda;
    }

    void setCalda(NoLista *no)
    {
        this->calda = no;
    }

    void addOrderedTreeERD(int);
    void deleteList();
    void deleteNode(int);
    void printList();
    void devideList(Lista &, Lista &, int);
};

// ---------- ARVORE BINARIA BALANCEADA ESTATICAMENTE ----------

// Classe No.
class No
{
private:
    No *esq, *dir; // Nos da direita e esquerda.
    int chave;     // valor do no.

public:
    // Construtor.
    No(int chave)
    {
        this->chave = chave;
        esq = nullptr;
        dir = nullptr;
    }

    // Metodos getters e setters.
    No *getEsq()
    {
        return esq;
    }
    No *getDir()
    {
        return dir;
    }
    int getChave()
    {
        return chave;
    }
    void setChave(int chave)
    {
        this->chave = chave;
    }
    void setEsq(No *esqNo)
    {
        this->esq = esqNo;
    }
    void setDir(No *dirNo)
    {
        this->dir = dirNo;
    }
};

// Classe Arvore.
class Arvore
{
private:
    No *raiz; // Raiz da arvore.

public:
    // Construtor da Arvore.
    Arvore()
    {
        raiz = nullptr;
    }

    No *getRaiz()
    {
        return raiz;
    }

    void setRaiz(No *raiz)
    {
        this->raiz = raiz;
    }

    // Metodo de Insercao.
    void inserirNo(int chave);

    // Metodo para Remocao.
    No *removerNo(No *no, int chave, No *&removido);

    // Metodo para Calcular o Balanceamento.
    bool fatorBalanceamento(No *no);

    // Metodo para Balancear a Arvore.
    No *balancearArvore(No *raiz, Lista lista);

    // Metodo para Deletar a Arvore.
    No *deleteTree(No *raiz);

    // Metodos de Busca.
    void preOrdem(No *raiz);
    void inOrdem(No *raiz);
    void posOrdem(No *raiz);
};

// ---------- ASSINATURA DE METODOS AUXILIARES ----------

void clearScreen();
void menuOptions();
int readValues();

// Auxiliares da Arvore
void inserirAux(No *no, int chave);
int calcularAltura(No *no, int esq, int dir);
void insertListTree(No *raiz, Lista &lista);
No *createBalancedTree(Lista &lista, No *raiz);

// Auxiliares da Lista
int getNoCentral(Lista &lista);

// ------------- PROGRAMA PRINCIPAL -----------

// Programa Principal.
int main()
{
    menuOptions();

    return 0;
}

// ------------ MÉTODOS AUXILIARES ------------

// Metodo para limpar tela.
void clearScreen()
{
    system(limpar_tela);
}

// Metodo que contem as opcoes do programa.
void menuOptions()
{
    Arvore arvore = Arvore();
    No *raiz, *removido;
    Lista lista = Lista();

    int op = 0;

    do
    {
        removido = nullptr;
        int value = 0;
        bool fb_verification = true;

        clearScreen();
        std::cout << "\n\n";
        std::cout << "[0] - Encerrar" << std::endl;
        std::cout << "[1] - Inserir No" << std::endl;
        std::cout << "[2] - Remover No" << std::endl;
        std::cout << "[3] - Busca Pre-Ordem" << std::endl;
        std::cout << "[4] - Busca In-Ordem" << std::endl;
        std::cout << "[5] - Busca Pos-Ordem" << std::endl;
        std::cin >> op;
        std::getchar();

        clearScreen();
        std::cout << "\n\n";

        switch (op)
        {
        case 0:
            std::cout << "Programa Encerrado!\n";
            break;
        case 1:
            value = readValues();
            arvore.inserirNo(value);
            raiz = arvore.getRaiz();

            fb_verification = arvore.fatorBalanceamento(raiz);
            if (fb_verification)
            {
                std::cout << "Arvore Balanceada!\n\n";
            }
            else
            {
                std::cout << "Arvore Desbalanceada! Iniciando Balanceamento\n\n";
                raiz = arvore.balancearArvore(raiz, lista);
                arvore.setRaiz(raiz);
            }

            std::getchar();
            break;
        case 2:
            value = readValues();
            raiz = arvore.removerNo(raiz, value, removido);
            if (removido != nullptr)
            {
                std::cout << "Valor removido: " << value << "\n";
            }
            else
            {
                std::cout << "Valor nao existente na arvore!\n";
            }

            fb_verification = arvore.fatorBalanceamento(raiz);
            if (fb_verification)
            {
                std::cout << "Arvore Balanceada!\n";
            }
            else
            {
                std::cout << "Arvore Desbalanceada! Iniciando Balanceamento\n\n";
                raiz = arvore.balancearArvore(raiz, lista);
                arvore.setRaiz(raiz);
            }

            std::getchar();
            break;
        case 3:
            std::cout << "Busca Pre-Ordem (RED): ";
            arvore.preOrdem(raiz);
            std::getchar();
            break;
        case 4:
            std::cout << "Busca In-Ordem (ERD): ";
            arvore.inOrdem(raiz);
            std::getchar();
            break;
        case 5:
            std::cout << "Busca Pos-Ordem (EDR): ";
            arvore.posOrdem(raiz);
            std::getchar();
            break;
        default:
            std::cout << "Opcao Invalida!\n";
            std::getchar();
            break;
        }
    } while (op != 0);
}

// Metodo para ler os valores stdin.
int readValues()
{
    int value = 0;
    std::cout << "Informe um valor para o no: ";
    std::cin >> value;
    std::getchar();
    return value;
}

// ------------------------- Metodos Auxiliares da Arvore.

// Metodo auxiliar de insercao que percorre a Arvore.
void inserirAux(No *no, int chave)
{
    // Se o valor for menor que o valor do no atual, entao prossegue para esquerda.
    if (chave < no->getChave())
    {
        // Verifica se o no a esquerda e nulo.
        if (no->getEsq() == nullptr)
        {
            No *novoNo = new No(chave); // Declara novo no.
            no->setEsq(novoNo);         // Insere novo no à esquerda do no atual.
        }
        else
        {
            // Caso o no esquerdo nao seja nulo, recursivamente iteramos sobre o ele.
            // Novamente a funcao é chamada, agora para este no esquerdo.
            inserirAux(no->getEsq(), chave);
        }
    }
    else if (chave > no->getChave()) // Prossegue para direita se valor maior que no atual.
    {
        // Mesmo processo de insercao à esquerda.
        if (no->getDir() == nullptr)
        {
            No *novoNo = new No(chave);
            no->setDir(novoNo);
        }
        else
        {
            inserirAux(no->getDir(), chave);
        }
    }
    else if (chave == no->getChave())
    {
        std::cout << "Valor ja existente na arvore!\n";
    }
    else
    {
        std::cout << "Valor invalido!\n";
    }
}

// Metodo que calcular a altura total a partir de um no dado.
int calcularAltura(No *no, int esq = 0, int dir = 0)
{
    // Retorna altura zero se o no for nulo.
    if (no == nullptr)
        return 0;

    int altura_esquerda = calcularAltura(no->getEsq(), esq + 1, dir);
    int altura_direita = calcularAltura(no->getDir(), esq, dir + 1);

    int altura_total = 1 + std::max(altura_esquerda, altura_direita);

    return altura_total;
}

// Metodo para inserir a arvore na lista.
void insertListTree(No *raiz, Lista &lista)
{
    // Percorre a árvore enquanto não for nula.
    if (raiz != nullptr)
    {
        insertListTree(raiz->getEsq(), lista);
        lista.addOrderedTreeERD(raiz->getChave());
        lista.size += 1;
        insertListTree(raiz->getDir(), lista);
    }
}

// Metodo para criar arvore balanceada.
No *createBalancedTree(Lista &lista, No *raiz)
{
    if (lista.size == 0 || lista.isEmpty())
    {
        return raiz;
    }

    // Salva o valor central da lista para a raiz da arvore.
    int elementoCentral;
    if (lista.size > 1)
    {
        elementoCentral = getNoCentral(lista);
        lista.size -= 1;
    }
    else
    {
        elementoCentral = lista.getTopo()->getDadoLista();
        lista.size = 0;
    }

    std::cout << elementoCentral << "\n";
    lista.printList();
    std::cout << lista.size << "\n";

    if (raiz == nullptr)
    {
        raiz = new No(elementoCentral);
    }
    else if (lista.size != 0)
    {
        inserirAux(raiz, elementoCentral);
    }

    Lista listaEsq, listaDir;
    if (lista.size > 1)
    {
        lista.devideList(listaEsq, listaDir, floor((lista.size / 2)));
        lista.deleteList();
    }
    else
    {
        inserirAux(raiz, lista.getTopo()->getDadoLista());
        lista.deleteList();
        return raiz;
    }

    listaEsq.printList();
    std::cout << listaEsq.size << "\n";

    listaDir.printList();
    std::cout << listaDir.size << "\n";

    raiz = createBalancedTree(listaEsq, raiz);
    raiz = createBalancedTree(listaDir, raiz);

    lista.deleteList();
    return raiz;
}

// ------------------------- Metodos Auxiliares da Lista.

// Metodo para encontrar o no central da lista.
int getNoCentral(Lista &lista)
{
    // Salva a metade do tamanho da arvore.
    int metade = floor((lista.size / 2));

    NoLista *tmp = lista.getTopo();
    // Se tamanho impar retorna o valor central.
    // Se tamanho par retorna o valor central da direita.
    for (int i = 0; i < metade; i++)
    {
        tmp = tmp->getNoDir();
    }

    int dado = tmp->getDadoLista();
    lista.deleteNode(dado);

    return dado;
}

// ------------ MÉTODOS DA ARVORE ------------

// Metodo de insercao na Arvore.
void Arvore::inserirNo(int chave)
{
    if (raiz == nullptr) // verifica se a arvore esta vazia.
    {
        raiz = new No(chave); // atribui novo no.
    }
    else
    {
        inserirAux(raiz, chave); // Caso nao esteja vazia avanca.
    }
}

// Metodo para remover no da arvore.
// Recebe a raiz da arvore.
// Método para remover nó da árvore.
// Retorna o novo ponteiro do nó após a remoção.
No *Arvore::removerNo(No *no, int chave, No *&removido)
{
    if (no == nullptr) // Caso base: nó não encontrado.
    {
        return nullptr;
    }
    else if (chave < no->getChave()) // Procura à esquerda.
    {
        no->setEsq(removerNo(no->getEsq(), chave, removido));
    }
    else if (chave > no->getChave()) // Procura à direita.
    {
        no->setDir(removerNo(no->getDir(), chave, removido));
    }
    else // Chave encontrada.
    {
        removido = no;

        // Remocao de Nó folha.
        if (no->getEsq() == nullptr && no->getDir() == nullptr)
        {
            delete no;
            return nullptr;
        }

        // Remocao de No sem filho a esquerda.
        if (no->getEsq() == nullptr)
        {
            No *temp = no->getDir();
            delete no;
            return temp;
        }

        // Remocao de No sem filho a direita.
        if (no->getDir() == nullptr)
        {
            No *temp = no->getEsq();
            delete no;
            return temp;
        }

        // Remocao de No com dois filhos.
        No *ant, *maiorSubEsq = no->getEsq();
        while (maiorSubEsq->getDir() != nullptr)
        {
            ant = maiorSubEsq;
            maiorSubEsq = maiorSubEsq->getDir();
        }

        // // Copia o valor do sucessor para o nó atual.
        no->setChave(maiorSubEsq->getChave());

        // // Remove o nó sucessor da subárvore esquerda.
        no->setEsq(removerNo(no->getEsq(), maiorSubEsq->getChave(), removido));
    }

    return no;
}

// Metodo para deletar a arvore.
No *Arvore::deleteTree(No *raiz)
{
    // Segue a travessia pós-ordem.
    if (raiz != nullptr)
    {
        // Deleta os nós a partir das folhas.
        raiz->setEsq(deleteTree(raiz->getEsq()));
        raiz->setDir(deleteTree(raiz->getDir()));

        // Deleta o nó raiz.
        delete raiz;
    }

    return nullptr;
}

// Metodo para calcular o fator de balanceamento.
bool Arvore::fatorBalanceamento(No *no)
{
    // Fator 0 se altura 0.
    if (no == nullptr)
    {
        return true;
    }

    int altura_esquerda = calcularAltura(no->getEsq());
    int altura_direita = calcularAltura(no->getDir());

    int dif_altura = std::abs(altura_esquerda - altura_direita);

    if (dif_altura > 1)
    {
        return false;
    }

    return (fatorBalanceamento(no->getEsq()) && fatorBalanceamento(no->getDir()));
}

// Metodo para balancear a arvore.
No *Arvore::balancearArvore(No *raiz, Lista lista)
{
    // Verifica se a arvore nao é nula.
    if (!raiz)
    {
        return nullptr;
    }

    // Verifica se a lista esta vazia.
    if (lista.isEmpty())
    {
        lista.size = 0;

        // Insere a arvore na lista.
        insertListTree(raiz, lista);

        // Deleta a arvore atual.
        raiz = deleteTree(raiz);
        setRaiz(nullptr);

        // Metodo para criar a arvore balanceada.
        raiz = createBalancedTree(lista, raiz);

        lista.printList();
        std::cout << lista.size << "\n";

        // Metodo para deletar a lista.
        lista.deleteList();
    }

    return raiz;
}

// Metodo de busca preOrdem (RED).
void Arvore::preOrdem(No *raiz)
{
    if (raiz != nullptr)
    {
        std::cout << raiz->getChave() << " ";
        preOrdem(raiz->getEsq());
        preOrdem(raiz->getDir());
    }
}

// Metodo de busca inOrdem (ERD).
void Arvore::inOrdem(No *raiz)
{
    if (raiz != nullptr)
    {
        inOrdem(raiz->getEsq());
        std::cout << raiz->getChave() << " ";
        inOrdem(raiz->getDir());
    }
}

// Metodo de busca posOrdem (EDR).
void Arvore::posOrdem(No *raiz)
{
    if (raiz != nullptr)
    {
        posOrdem(raiz->getEsq());
        posOrdem(raiz->getDir());
        std::cout << raiz->getChave() << " ";
    }
}

// ---------- MÉTODOS DA LISTA SIMPLES ENCADEADA ----------

// Metodo que adiciona elementos de forma ordenada na lista.
void Lista::addOrderedTreeERD(int chave)
{
    // Cria um novo nó com o valor fornecido
    NoLista *novoNo = new NoLista(nullptr, chave);

    // Se a lista estiver vazia ou o valor for menor que o primeiro elemento da lista,
    // insere o novo nó no início da lista.
    if (isEmpty() || chave < topo->getDadoLista())
    {
        novoNo->setNoDir(topo);
        topo = novoNo;
        if (calda == nullptr)
        {
            calda = topo;
        }
        return;
    }

    // Percorre a lista para encontrar a posição correta para inserir o novo nó
    NoLista *tmp = topo;
    while (tmp->getNoDir() != nullptr && tmp->getNoDir()->getDadoLista() < chave)
    {
        tmp = tmp->getNoDir();
    }

    // Insere o novo nó após o nó atual
    novoNo->setNoDir(tmp->getNoDir());
    tmp->setNoDir(novoNo);

    // Atualiza o ponteiro para a cauda, se necessário
    if (novoNo->getNoDir() == nullptr)
    {
        calda = novoNo;
    }
}

// Metodo que imprime toda a lista.
void Lista::printList()
{
    if (topo != nullptr && calda != nullptr)
    {
        // Percorre a lista ate o fim
        for (NoLista *tmp = topo; tmp != nullptr; tmp = tmp->getNoDir())
        {
            std::cout << tmp->getDadoLista() << " ";
        }
        std::cout << std::endl;
    }
    else
    {
        std::cout << "Lista Vazia" << std::endl;
    }
}

// Metodo que deleta toda a lista.
void Lista::deleteList()
{
    NoLista *tmp = topo;
    NoLista *prox;
    while (tmp != nullptr)
    {
        prox = tmp->getNoDir(); // Salva o próximo nó antes de excluir o atual
        delete tmp;             // Exclui o nó atual
        tmp = prox;             // Move para o próximo nó
    }
    // Após excluir todos os nós, atualiza os ponteiros e o tamanho da lista
    topo = nullptr;
    calda = nullptr;
    size = 0;
}

// Metodo para deletar qualquer elemento da lista.
void Lista::deleteNode(int el)
{
    // Verifica se a lista esta vazia.
    if (topo == nullptr && calda == nullptr)
    {
        return;
    }

    // No temporario
    NoLista *tmp = topo;

    // Verifica se o elemento procurado é o primeiro
    if (el == tmp->getDadoLista())
    {
        // Verifica se lista possui apenas um elemento
        if (topo == calda)
        {
            topo = calda = nullptr;
            delete tmp;
        }
        else
        {
            topo = topo->getNoDir();
            delete tmp;
        }
    }
    else
    {
        // Percorre a lista ate o fim ou ate achar o elemento
        NoLista *anterior = nullptr;
        while (el != tmp->getDadoLista() && tmp)
        {
            anterior = tmp;
            tmp = tmp->getNoDir();
        }

        // Verifica se é o elemento procurado
        if (tmp && el == tmp->getDadoLista())
        {
            anterior->setNoDir(tmp->getNoDir());
            // Atualiza resto caso seja o ultimo elemento
            if (!tmp->getNoDir())
            {
                calda = anterior;
            }
            delete tmp;
        }
    }
}

// Metodo para dividir a lista em duas partes.
void Lista::devideList(Lista &esq, Lista &dir, int elementoCentral)
{
    esq.deleteList();
    dir.deleteList();

    // Armazena lado esquerdo.
    NoLista *tmp = topo;
    for (int i = 0; i < elementoCentral; i++)
    {
        esq.addOrderedTreeERD(tmp->getDadoLista());
        tmp = tmp->getNoDir();
    }
    esq.size = elementoCentral;

    // Armazena lado direito.
    int i = 0;
    for (tmp; tmp != nullptr; tmp = tmp->getNoDir())
    {
        dir.addOrderedTreeERD(tmp->getDadoLista());
        i += 1;
    }
    dir.size = i;
}
