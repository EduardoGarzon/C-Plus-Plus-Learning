/**
 * @file ABB.cpp
 * @author Luiz Eduardo Garzon.
 * @brief Árvore Binária Balanceada Dinamicamente (AVL).
 * @version 0.1
 * @date 2024-03-01
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

// ---------- ARVORE BINARIA BALANCEADA ESTATICAMENTE ----------

// Classe No.
class No
{
private:
    No *esq, *dir; // Nos da direita e esquerda.
    int chave;     // Valor do no.

public:
    int balance_factor; // Fator de Balanceamento do No.

    // Construtor.
    No(int chave)
    {
        this->chave = chave;
        this->balance_factor = 0;
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
    int size;

    // Construtor da Arvore.
    Arvore()
    {
        raiz = nullptr;
        this->size = 0;
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
void inserirAux(No *no, No *&raiz, int chave, int size);
int calcularAltura(No *no, No *&unbalancedNode);
int fatorBalanceamento(No *no, No *&unbalancedNode);
No *searchPreviousNode(No *raiz, int chave, No *previous);
void balancearArvore(No *unbalancedNode, No *searchPreviousNode, No *&raiz);
No *rotacaoSD(No *unbalancedNode);
No *rotacaoSE(No *unbalancedNode);
No *rotacaoDDE(No *unbalancedNode);
No *rotacaoDED(No *unbalancedNode);

// ------------- PROGRAMA PRINCIPAL -----------

// Programa Principal.
int main()
{
    menuOptions();

    return 0;
}

// ------------------------- METODOS AUXILIARES.

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

            std::getchar();
            break;
        case 2:
            value = readValues();
            raiz = arvore.removerNo(raiz, value, removido);
            if (removido != nullptr)
            {
                std::cout << "Valor removido: " << removido->getChave() << "\n";
            }
            else
            {
                std::cout << "Valor nao existente na arvore!\n";
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

// ------------------------- METODOS AUXILIARES DA ARVORE.

// Metodo auxiliar de insercao que percorre a Arvore.
void inserirAux(No *no, No *&raiz, int chave, int size)
{

    // Se o valor for menor que o valor do no atual, entao prossegue para esquerda.
    if (chave < no->getChave())
    {
        // Verifica se o no a esquerda e nulo.
        if (no->getEsq() == nullptr)
        {
            No *novoNo = new No(chave); // Declara novo no.
            no->setEsq(novoNo);         // Insere novo no à esquerda do no atual.
            size += 1;

            No *unbalancedNode, *previousNode;

            do
            {
                unbalancedNode = nullptr, previousNode = nullptr;

                raiz->balance_factor = fatorBalanceamento(raiz, unbalancedNode);
                if (unbalancedNode)
                {
                    std::cout << "Arvore Desbalanceada!\n";
                    std::cout << "No: " << unbalancedNode->getChave() << "\n";
                    std::cout << "FB: " << unbalancedNode->balance_factor << "\n";

                    previousNode = searchPreviousNode(raiz, unbalancedNode->getChave(), nullptr);
                    balancearArvore(unbalancedNode, previousNode, raiz);
                }
                else
                {
                    std::cout << "Nao Precisa Balancear\n";
                    break;
                }

            } while (unbalancedNode);
        }
        else
        {
            // Caso o no esquerdo nao seja nulo, recursivamente iteramos sobre o ele.
            // Novamente a funcao é chamada, agora para este no esquerdo.
            inserirAux(no->getEsq(), raiz, chave, size);
        }
    }
    else if (chave > no->getChave()) // Prossegue para direita se valor maior que no atual.
    {
        // Mesmo processo de insercao à esquerda.
        if (no->getDir() == nullptr)
        {
            No *novoNo = new No(chave);
            no->setDir(novoNo);
            size += 1;

            No *unbalancedNode, *previousNode;

            do
            {
                unbalancedNode = nullptr, previousNode = nullptr;

                raiz->balance_factor = fatorBalanceamento(raiz, unbalancedNode);
                if (unbalancedNode)
                {
                    std::cout << "Arvore Desbalanceada!\n";
                    std::cout << "No: " << unbalancedNode->getChave() << "\n";
                    std::cout << "FB: " << unbalancedNode->balance_factor << "\n";

                    previousNode = searchPreviousNode(raiz, unbalancedNode->getChave(), nullptr);
                    balancearArvore(unbalancedNode, previousNode, raiz);
                }
                else
                {
                    std::cout << "Nao Precisa Balancear\n";
                    break;
                }

            } while (unbalancedNode);
        }
        else
        {
            inserirAux(no->getDir(), raiz, chave, size);
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

// Metodo para calcular o fator de balanceamento a partir do no dado.
int fatorBalanceamento(No *raiz, No *&unbalancedNode)
{
    int balanceDirFactor = calcularAltura(raiz->getDir(), unbalancedNode);
    int balanceEsqFactor = calcularAltura(raiz->getEsq(), unbalancedNode);

    if (((balanceDirFactor - balanceEsqFactor) > 1 || (balanceDirFactor - balanceEsqFactor) < -1) && !unbalancedNode)
    {
        unbalancedNode = raiz;
        unbalancedNode->balance_factor = balanceDirFactor - balanceEsqFactor;
    }

    return balanceDirFactor - balanceEsqFactor;
}

// Metodo que calcular a altura dos nos para o fator de balanceamento.
int calcularAltura(No *no, No *&unbalancedNode)
{
    // Retorna Fator 0.
    if (!no)
    {
        return 0;
    }

    // Retorna 1 para o pai caso o no atual tenha altura 0.
    if (!no->getDir() && !no->getEsq())
    {
        no->balance_factor = 0;
        if ((no->balance_factor > 1 || no->balance_factor < -1) && unbalancedNode == nullptr)
        {
            unbalancedNode = no;
        }
        return (no->balance_factor + 1);
    }

    int esq, dir;

    // Verifica os nos da esquerda e direita.
    esq = calcularAltura(no->getEsq(), unbalancedNode);
    dir = calcularAltura(no->getDir(), unbalancedNode);

    // Subtracao das alturas respectivas.
    no->balance_factor = dir - esq;
    if ((no->balance_factor > 1 || no->balance_factor < -1) && unbalancedNode == nullptr)
    {
        unbalancedNode = no;
    }

    // Retorna para o pai a maior altura + o proprio no.
    return (std::max(esq, dir) + 1);
}

// Metodo que retorna o no pai do no desbalanceado.
No *searchPreviousNode(No *raiz, int chave, No *previous)
{
    if (chave > raiz->getChave())
        return searchPreviousNode(raiz->getDir(), chave, raiz);
    else if (chave < raiz->getChave())
        return searchPreviousNode(raiz->getEsq(), chave, raiz);
    else
        return previous;
}

// Metodo que balanceia a arvore dinamicamente identificando o tipo de rotacao.
void balancearArvore(No *unbalancedNode, No *previousNode, No *&raiz)
{
    // Rotacao Simples -> Pivo tem mesmo sinal que o seu filho.
    if (((unbalancedNode->balance_factor > 0) && (unbalancedNode->getDir()->balance_factor > 0 || unbalancedNode->getEsq()->balance_factor > 0)) || ((unbalancedNode->balance_factor < 0) && (unbalancedNode->getDir()->balance_factor < 0 || unbalancedNode->getEsq()->balance_factor < 0)))
    {
        // Rotacao Simples para Esquerda -> Pivo com sinal positivo.
        if (unbalancedNode->balance_factor > 0)
        {
            std::cout << "Rotacao Simples Esquerda\n";
            std::getchar();
            if (previousNode)
                if (previousNode->getDir()->getChave() == unbalancedNode->getChave())
                    previousNode->setDir(rotacaoSE(unbalancedNode));
                else
                    previousNode->setEsq(rotacaoSE(unbalancedNode));
            else
                raiz = rotacaoSE(unbalancedNode);
        }
        else // Rotacao Siples para Direita -> Pivo com sinal negativo.
        {
            std::cout << "Rotacao Simples Direita\n";
            std::getchar();
            if (previousNode)
                if (previousNode->getDir()->getChave() == unbalancedNode->getChave())
                    previousNode->setDir(rotacaoSD(unbalancedNode));
                else
                    previousNode->setEsq(rotacaoSD(unbalancedNode));
            else
                raiz = rotacaoSD(unbalancedNode);
        }
    }
    else // Rotacao Dupla -> Pivo com sinal diferente do seu filho.
    {
        // Rotacao Dupla Direita Esquerda -> Pivo com sinal positivo.
        if (unbalancedNode->balance_factor > 0)
        {
            std::cout << "Rotacao Dupla Direita Esquerda\n";
            std::getchar();
            if (previousNode)
                if (previousNode->getDir()->getChave() == unbalancedNode->getChave())
                    previousNode->setDir(rotacaoDDE(unbalancedNode));
                else
                    previousNode->setEsq(rotacaoDDE(unbalancedNode));
            else
                raiz = rotacaoDDE(unbalancedNode);
        }
        else // Rotacao Dupla Esquerda Direita -> Pivo com sinal negativo.
        {
            std::cout << "Rotacao Dupla Esquerda Direita\n";
            std::getchar();
            if (previousNode)
                if (previousNode->getDir()->getChave() == unbalancedNode->getChave())
                    previousNode->setDir(rotacaoDED(unbalancedNode));
                else
                    previousNode->setEsq(rotacaoDED(unbalancedNode));
            else
                raiz = rotacaoDED(unbalancedNode);
        }
    }
}

// Metodo que realiza Rotacao Simples para Direita.
No *rotacaoSD(No *unbalancedNode)
{
    No *temp = unbalancedNode; // Recebe o no desbalanceado.
    No *esq = temp->getEsq();  // Recebe a esquerda do no desbalanceado.

    // No desbalanceado recebe
    // o no direito do seu filho esquerdo caso ele tenha.
    temp->setEsq(esq->getDir());
    esq->setDir(temp); // No rotacionado recebe o pivo desbalanceado a sua direita.

    // Retorna a nova raiz da arvore desbalanceada.
    return esq;
}

// Metodo que realiza Rotacao Simples para Esquerda
No *rotacaoSE(No *unbalancedNode)
{
    No *temp = unbalancedNode;
    No *dir = temp->getDir();

    temp->setDir(dir->getEsq());
    dir->setEsq(temp);

    return dir;
}

// Metodo que realiza Rotacao Dupla Direita e Esquerda
No *rotacaoDDE(No *unbalancedNode)
{
    No *p = unbalancedNode;
    No *z = p->getDir();
    No *y = z->getEsq();

    // Rotacao Direita
    z->setEsq(y->getDir());
    y->setDir(z);
    p->setDir(y);

    // Rotacao Esquerda
    p->setDir(y->getEsq());
    y->setEsq(p);

    return y;
}

// Metodo que realiza Rotacao Dupla Esquerda e Direita
No *rotacaoDED(No *unbalancedNode)
{
    No *p = unbalancedNode;
    No *u = p->getEsq();
    No *v = u->getDir();

    // Rotacao Esquerda
    u->setDir(v->getEsq());
    v->setEsq(u);
    p->setEsq(v);

    // Rotacao Direita
    p->setEsq(v->getDir());
    v->setDir(p);

    return v;
}

// ------------ MÉTODOS DA ARVORE ------------

// Metodo de insercao na Arvore.
void Arvore::inserirNo(int chave)
{
    if (raiz == nullptr) // verifica se a arvore esta vazia.
    {
        raiz = new No(chave); // atribui novo no.
        raiz->balance_factor = 0;
        size += 1;
    }
    else
    {
        inserirAux(raiz, raiz, chave, size); // Caso nao esteja vazia avanca.
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

        // Copia o valor do sucessor para o nó atual.
        no->setChave(maiorSubEsq->getChave());

        // Remove o nó sucessor da subárvore esquerda.
        no->setEsq(removerNo(no->getEsq(), maiorSubEsq->getChave(), removido));
    }

    No *unbalancedNode, *previousNode;
    do
    {
        unbalancedNode = nullptr, previousNode = nullptr;

        raiz->balance_factor = fatorBalanceamento(raiz, unbalancedNode);
        if (unbalancedNode)
        {
            std::cout << "Arvore Desbalanceada!\n";
            std::cout << "No: " << unbalancedNode->getChave() << "\n";
            std::cout << "FB: " << unbalancedNode->balance_factor << "\n\n";

            previousNode = searchPreviousNode(raiz, unbalancedNode->getChave(), nullptr);
            balancearArvore(unbalancedNode, previousNode, raiz);
        }
        else
        {
            std::cout << "Nao Precisa Balancear\n\n";
            break;
        }

    } while (unbalancedNode);

    return raiz;
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

// Metodo de busca preOrdem (RED).
void Arvore::preOrdem(No *raiz)
{
    if (raiz != nullptr)
    {
        std::cout << raiz->getChave() << "(" << raiz->balance_factor << ") ";
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
        std::cout << raiz->getChave() << "(" << raiz->balance_factor << ") ";
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
        std::cout << raiz->getChave() << "(" << raiz->balance_factor << ") ";
    }
}