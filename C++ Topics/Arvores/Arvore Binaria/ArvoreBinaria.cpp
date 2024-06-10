/**
 * @file ArvoreBinaria.cpp
 * @author Luiz Eduardo Garzon.
 * @brief Árvore Binária.
 * @version 0.1
 * @date 2024-02-09
 *
 * @copyright Copyright (c) 2024
 */

#include <iostream>

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

    // Metodo de Insercao.
    void inserirNo(int chave);

    // Metodo para Remocao.
    No *removerNo(No *no, int chave, No *&removido);

    // Metodos de Busca.
    void preOrdem(No *raiz);
    void inOrdem(No *raiz);
    void posOrdem(No *raiz);
};

void menuOptions();
int readValues();
void inserirAux(No *no, int chave);

int main()
{
    menuOptions();

    return 0;
}

void menuOptions()
{
    Arvore arvore = Arvore();
    No *raiz, *removido;

    int op = 0;

    do
    {
        removido = nullptr;
        int value = 0;

        system("clear");
        std::cout << "\n\n";
        std::cout << "[0] - Encerrar" << std::endl;
        std::cout << "[1] - Inserir No" << std::endl;
        std::cout << "[2] - Remover No" << std::endl;
        std::cout << "[3] - Busca Pre-Ordem" << std::endl;
        std::cout << "[4] - Busca In-Ordem" << std::endl;
        std::cout << "[5] - Busca Pos-Ordem" << std::endl;
        std::cin >> op;
        std::getchar();

        system("clear");
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

int readValues()
{
    int value = 0;
    std::cout << "Informe um valor para o no: ";
    std::cin >> value;
    std::getchar();
    return value;
}

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