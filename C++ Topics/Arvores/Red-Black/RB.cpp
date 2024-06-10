/**
 * @file RB.cpp
 * @author Luiz Eduardo Garzon.
 * @brief Árvore Binária Rubro-Negra (RB).
 *        Exibicao dos nós seguem o formato -> key(color, predecessor).
 * @version 0.1
 * @date 2024-03-01
 *
 * @copyright Copyright (c) 2024
 * 
 * OBS: 1. PRECISA IMPLEMENTAR LÓGICA DE VERIFICACAO E BALANCEAMENTO NA REMOCAO.
 *      2. PRECISA IMPLEMENTAR CALCULO DA ALTURA NEGRA.
 *      3. PRECISA IMPLEMENTAR BUSCA POR 1 NÓ QUALQUER.
 */

#if defined(_WIN32) || defined(_WIN64)
#define limpar_tela "cls"
#else
#define limpar_tela "clear"
#endif

#include <iostream>
#include <cmath>

// ---------- ARVORE BINARIA RUBRO NEGRA ----------

// Classe No.
class No
{
private:
    No *esq, *dir, *pred; // Nos da direita, esquerda e predecessor.
    int chave;            // Valor do no.
    char cor;             // Cor do no. B (Black) ou R (Red).

public:
    // Construtor.
    No(int chave)
    {
        this->chave = chave;
        this->cor = 'R';
        esq = nullptr;
        dir = nullptr;
        pred = nullptr;
    }

    // Metodos getters.
    No *getEsq()
    {
        return esq;
    }
    No *getDir()
    {
        return dir;
    }
    No *getPred()
    {
        return pred;
    }
    char getColor()
    {
        return cor;
    }
    int getChave()
    {
        return chave;
    }

    // Métodos setters.
    void setEsq(No *esqNo)
    {
        this->esq = esqNo;
    }
    void setDir(No *dirNo)
    {
        this->dir = dirNo;
    }
    void setPred(No *predNo)
    {
        this->pred = predNo;
    }
    void setColor(char color)
    {
        this->cor = color;
    }
    void setChave(int chave)
    {
        this->chave = chave;
    }
};

// Classe Arvore.
class Arvore
{
private:
    No *raiz; // Raiz da arvore.

public:
    int size;       // Total de elementos da árvore.
    int black_size; // Altura preta da árvore.

    // Construtor da Arvore.
    Arvore()
    {
        raiz = nullptr;
        this->size = 0;
        this->black_size = 0;
    }

    // Metodos getters e setters.
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
void inserirAux(No *no, No *&raiz, int chave, int &size, int black_size);
No *balanceColors(No *&novoNo, No *&raiz);
No *rotacaoSD(No *&grandfather, No *&raiz);
No *rotacaoSE(No *&grandfather, No *&raiz);
No *rotacaoDED(No *&grandfather, No *&raiz);
No *rotacaoDDE(No *&grandfather, No *&raiz);

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
    No *raiz = nullptr, *removido;
    int op = 0;

    do
    {
        removido = nullptr;
        int value = 0;

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
            if (raiz != nullptr)
            {
                std::cout << "Busca Pre-Ordem (RED)\n";
                std::cout << "Total de Elementos: " << arvore.size << "\n";
                arvore.preOrdem(raiz);
            }
            else
            {
                std::cout << "Arvore vazia!\n";
            }

            std::getchar();
            break;
        case 4:
            if (raiz != nullptr)
            {
                std::cout << "Busca In-Ordem (ERD)\n";
                std::cout << "Total de Elementos: " << arvore.size << "\n";
                arvore.inOrdem(raiz);
            }
            else
            {
                std::cout << "Arvore vazia!\n";
            }

            std::getchar();
            break;
        case 5:
            if (raiz != nullptr)
            {
                std::cout << "Busca Pos-Ordem (EDR)\n";
                std::cout << "Total de Elementos: " << arvore.size << "\n";
                arvore.posOrdem(raiz);
            }
            else
            {
                std::cout << "Arvore vazia!\n";
            }

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
void inserirAux(No *no, No *&raiz, int chave, int &size, int black_size)
{
    // Se o valor for menor que o valor do no atual, entao prossegue para esquerda.
    if (chave < no->getChave())
    {
        // Verifica se o no a esquerda e nulo.
        if (no->getEsq() == nullptr)
        {
            No *novoNo = new No(chave); // Declara novo no.
            no->setEsq(novoNo);         // Insere novo no à esquerda do no atual.
            novoNo->setPred(no);
            size += 1;

            No *checkNode = nullptr;
            checkNode = balanceColors(novoNo, raiz);

            // Enquanto retornar no filho vermelho com pai vermelho.
            while (checkNode != nullptr)
            {
                checkNode = balanceColors(checkNode, raiz);
            }
        }
        else
        {
            // Caso o no esquerdo nao seja nulo, recursivamente iteramos sobre o ele.
            // Novamente a funcao é chamada, agora para este no esquerdo.
            inserirAux(no->getEsq(), raiz, chave, size, black_size);
        }
    }
    else if (chave > no->getChave()) // Prossegue para direita se valor maior que no atual.
    {
        // Mesmo processo de insercao à esquerda.
        if (no->getDir() == nullptr)
        {
            No *novoNo = new No(chave);
            no->setDir(novoNo);
            novoNo->setPred(no);
            size += 1;

            No *checkNode = nullptr;
            checkNode = balanceColors(novoNo, raiz);

            while (checkNode != nullptr)
            {
                checkNode = balanceColors(checkNode, raiz);
            }
        }
        else
        {
            inserirAux(no->getDir(), raiz, chave, size, black_size);
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

// Metodo que verifica e realiza o balanceamento das cores da árvore.
No *balanceColors(No *&novoNo, No *&raiz)
{
    // O pai do nó inserido é vermelho.
    if (novoNo->getPred()->getColor() == 'R')
    {
        No *father = novoNo->getPred();
        No *grandfather = father->getPred();

        // O nó tio é vermelho.
        if ((grandfather->getEsq() != nullptr) &&
            (grandfather->getEsq()->getChave() != father->getChave()) &&
            (grandfather->getEsq()->getColor() == 'R')) // tio esquerdo.
        {
            father->setColor('B');                // Pai se torna preto.
            grandfather->getEsq()->setColor('B'); // Tio se torna preto.
            grandfather->setColor('R');

            if (grandfather->getPred() != nullptr && grandfather->getPred()->getColor() == 'R')
            {
                return grandfather;
            }
            else
            {

                return nullptr;
            }
        }
        else if ((grandfather->getDir() != nullptr) &&
                 (grandfather->getDir()->getChave() != father->getChave()) &&
                 (grandfather->getDir()->getColor() == 'R')) // tio direito.
        {
            father->setColor('B');                // Pai se torna preto.
            grandfather->getDir()->setColor('B'); // Tio se torna preto.
            grandfather->setColor('R');

            if (grandfather->getPred() != nullptr && grandfather->getPred()->getColor() == 'R')
                return grandfather;
            else
                return nullptr;
        }

        // O tio é preto (nil).
        if (grandfather->getEsq() == nullptr || grandfather->getEsq()->getColor() == 'B') // Tio esquerdo preto.
        {
            No *checkNode = nullptr;

            // Rotacao simples a esquerda.
            if (father->getDir() != nullptr && father->getDir()->getChave() == novoNo->getChave())
            {
                /*
                    Filho é direito do pai,
                    Pai é direito do avô,
                    Tio é esquerdo do avô.
                */
                father->setColor('B');                    // Pai se torna preto.
                grandfather->setColor('R');               // Avô se torna vermelho.
                checkNode = rotacaoSE(grandfather, raiz); // Rotacao simples esquerda.

                if (checkNode != nullptr)
                    return checkNode;
                else
                    return nullptr;
            }
            else if (father->getEsq() != nullptr && father->getEsq()->getChave() == novoNo->getChave())
            {
                // Rotacao dupla direita-esquerda.

                /*
                    Filho é esquerdo do pai,
                    Pai é filho direito do avô,
                    Tio é esquerdo do avô.
                */
                novoNo->setColor('B');
                father->setColor('R');
                grandfather->setColor('R');
                checkNode = rotacaoDDE(grandfather, raiz);

                if (checkNode != nullptr)
                    return checkNode;
                else
                    return nullptr;
            }
        }
        else if (grandfather->getDir() == nullptr || grandfather->getDir()->getColor() == 'B') // Tio direito preto.
        {
            No *checkNode = nullptr;

            // Rotacao simples a direita.
            if (father->getEsq() != nullptr && father->getEsq()->getChave() == novoNo->getChave())
            {
                /*
                    Filho é esquerdo do pai,
                    Pai é esquerdo do avô,
                    Tio é direito do avô.
                */
                father->setColor('B');                    // Pai se torna preto.
                grandfather->setColor('R');               // Avô se torna vermelho.
                checkNode = rotacaoSD(grandfather, raiz); // Rotacao simples direita.

                if (checkNode != nullptr)
                {
                    return checkNode;
                }
                else
                {
                    return nullptr;
                }
            }
            else if (father->getDir() != nullptr && father->getDir()->getChave() == novoNo->getChave())
            {
                // Rotacao dupla esquerda-direita.

                /*
                    Filho é direito do pai,
                    Pai é esquerdo do avô,
                    Tio é direito do avô.
                */
                novoNo->setColor('B');
                father->setColor('R');
                grandfather->setColor('R');
                checkNode = rotacaoDED(grandfather, raiz);

                if (checkNode != nullptr)
                    return checkNode;
                else
                    return nullptr;
            }
        }
    }

    return nullptr;
}

// Metodo que realiza Rotacao Simples para Direita.
No *rotacaoSD(No *&grandfather, No *&raiz)
{
    No *ant = grandfather->getPred(); // Recebe o pai do avô.
    No *temp = grandfather;           // Recebe o no desbalanceado.
    No *esq = temp->getEsq();         // Recebe a esquerda do no desbalanceado.

    // No desbalanceado recebe o no direito do seu filho esquerdo caso ele tenha.
    temp->setEsq(esq->getDir());
    if (esq->getDir() != nullptr)
        esq->getDir()->setPred(temp);

    // No rotacionado recebe o pivo desbalanceado a sua direita.
    esq->setDir(temp);

    // Ajusta predecessores.
    esq->setPred(ant);
    temp->setPred(esq);

    // Define o novo filho do bisavo.
    if (ant != nullptr && ant->getEsq()->getChave() == grandfather->getChave())
    {
        ant->setEsq(esq); // filho esquerdo do bisavo.
    }
    else if (ant != nullptr && ant->getDir()->getChave() == grandfather->getChave())
    {
        ant->setDir(esq); // filho direito do bisavo.
    }
    else
    {
        raiz = esq; // o bisavo é nullptr.
    }

    std::cout << "Rotacao Simples Direita.\n";

    if (ant != nullptr && (ant->getColor() == 'R' && esq->getColor() == 'R'))
    {
        return esq;
    }

    return nullptr;
}

// Metodo que realiza Rotacao Simples para Esquerda
No *rotacaoSE(No *&grandfather, No *&raiz)
{
    No *ant = grandfather->getPred();
    No *temp = grandfather;
    No *dir = temp->getDir();

    // Rotaciona.
    temp->setDir(dir->getEsq());
    if (dir->getEsq() != nullptr)
        dir->getEsq()->setPred(temp);
    dir->setEsq(temp);

    // Ajusta predecessor do pai e do avo.
    dir->setPred(ant);
    temp->setPred(dir);

    if (ant != nullptr && ant->getEsq()->getChave() == grandfather->getChave())
    {
        ant->setEsq(dir);
    }
    else if (ant != nullptr && ant->getDir()->getChave() == grandfather->getChave())
    {
        ant->setDir(dir);
    }
    else
    {
        raiz = dir;
    }

    std::cout << "Rotacao Simples Esquerda.\n";

    if (ant != nullptr && (ant->getColor() == 'R' && dir->getColor() == 'R'))
    {
        return dir;
    }

    return nullptr;
}

// Metodo que realiza Rotacao Dupla Direita-Esquerda
No *rotacaoDDE(No *&grandfather, No *&raiz)
{
    No *ant = grandfather->getPred();
    No *w = grandfather; // Avô
    No *v = w->getDir(); // Pai
    No *q = v->getEsq(); // Filho.

    // Pai recebe seu neto direito.
    v->setEsq(q->getDir());
    if (q->getDir() != nullptr)
        q->getDir()->setPred(v);

    // O filho aponta para o pai.
    q->setDir(v);
    v->setPred(q); // Ajusta o predecessor do pai.

    // Avo do filho recebe o filho esquerdo do seu neto.
    w->setDir(q->getEsq());
    if (q->getEsq() != nullptr)
        q->getEsq()->setPred(w);

    // Filho aponta para o avo.
    q->setEsq(w);
    w->setPred(q); // Ajusta o predecessor do avo.

    // Atualiza o pai do filho.
    if (ant != nullptr)
    {
        q->setPred(ant); // Ajusta predecessor do novo no que esta no topo.

        if (ant->getEsq() != nullptr && ant->getEsq()->getChave() == w->getChave())
            ant->setEsq(q);
        else if (ant->getDir() != nullptr && ant->getDir()->getChave() == w->getChave())
            ant->setDir(q);
    }
    else
    {
        raiz = q;            // se bisavô é nulo, então q é a nova raiz
        q->setPred(nullptr); // q é a nova raiz, seu predecessor é nulo
    }

    std::cout << "Rotacao Dupla Direita-Esquerda.\n";

    if (ant != nullptr && (ant->getColor() == 'R' && q->getColor() == 'R'))
    {
        return q;
    }

    return nullptr;
}

// Metodo que realiza Rotacao Dupla Esquerda-Direita
No *rotacaoDED(No *&grandfather, No *&raiz)
{
    No *ant = grandfather->getPred(); // bisavô
    No *w = grandfather;              // avô
    No *v = w->getEsq();              // pai
    No *q = v->getDir();              // filho

    // O pai recebe seu neto da esquerda.
    v->setDir(q->getEsq());
    if (q->getEsq() != nullptr)
        q->getEsq()->setPred(v);

    q->setEsq(v);  // Filho aponta para o pai.
    v->setPred(q); // Ajusta predecessor do pai.

    // Avo do filho, recebe o filho direito de seu neto.
    w->setEsq(q->getDir());
    if (q->getDir() != nullptr)
        q->getDir()->setPred(w);

    q->setDir(w);  // Filho aponta para seu avo.
    w->setPred(q); // Ajusta predecessor do avo.

    // Atualiza o pai do filho.
    if (ant != nullptr)
    {
        q->setPred(ant); // Ajusta predecessor do novo no que esta no topo.

        if (ant->getEsq() != nullptr && ant->getEsq()->getChave() == w->getChave())
            ant->setEsq(q);
        else if (ant->getDir() != nullptr && ant->getDir()->getChave() == w->getChave())
            ant->setDir(q);
    }
    else
    {
        raiz = q;            // se bisavô é nulo, então q é a nova raiz
        q->setPred(nullptr); // q é a nova raiz, seu predecessor é nulo
    }

    std::cout << "Rotacao Dupla Esquerda-Direita.\n";

    if (ant != nullptr && (ant->getColor() == 'R' && q->getColor() == 'R'))
    {
        return q;
    }

    return nullptr;
}

// ------------ MÉTODOS DA ARVORE ------------

// Metodo de insercao na Arvore.
void Arvore::inserirNo(int chave)
{
    if (raiz == nullptr) // verifica se a arvore esta vazia.
    {
        raiz = new No(chave);
        raiz->setColor('B');
        raiz->setPred(nullptr);
        size += 1;
        black_size = 0;
    }
    else
    {
        inserirAux(raiz, raiz, chave, size, black_size); // Caso nao esteja vazia avanca.
        raiz->setColor('B');
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

// Metodo de busca preOrdem (RED).
void Arvore::preOrdem(No *raiz)
{
    if (raiz != nullptr)
    {
        std::cout << "\033[47m";
        if (raiz->getColor() == 'B')
            if (raiz->getPred() != nullptr)
                std::cout << "\033[2;30;47m"
                          << raiz->getChave()
                          << "(" << raiz->getColor() << "," << raiz->getPred()->getChave() << ")"
                          << "\033[0m ";

            else
                std::cout << "\033[2;30;47m"
                          << raiz->getChave()
                          << "(" << raiz->getColor() << ")"
                          << "\033[0m ";

        else if (raiz->getColor() == 'R')
            if (raiz->getPred() != nullptr)
                std::cout << "\033[2;31m"
                          << raiz->getChave()
                          << "(" << raiz->getColor() << "," << raiz->getPred()->getChave() << ")"
                          << "\033[0m ";
            else
                std::cout << "\033[2;31m"
                          << raiz->getChave()
                          << "(" << raiz->getColor() << ")"
                          << "\033[0m ";

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

        std::cout << "\033[47m";
        if (raiz->getColor() == 'B')
            std::cout << "\033[2;30;47m"
                      << raiz->getChave()
                      << "(" << raiz->getColor() << ")"
                      << "\033[0m ";
        else if (raiz->getColor() == 'R')
            std::cout << "\033[2;31m"
                      << raiz->getChave()
                      << "(" << raiz->getColor() << ")"
                      << "\033[0m ";

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

        std::cout << "\033[47m";
        if (raiz->getColor() == 'B')
            std::cout << "\033[2;30;47m"
                      << raiz->getChave()
                      << "(" << raiz->getColor() << ")"
                      << "\033[0m ";
        else if (raiz->getColor() == 'R')
            std::cout << "\033[2;31m"
                      << raiz->getChave()
                      << "(" << raiz->getColor() << ")"
                      << "\033[0m ";
    }
}