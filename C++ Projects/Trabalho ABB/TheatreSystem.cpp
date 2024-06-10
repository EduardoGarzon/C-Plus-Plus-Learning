/**
 * @file TheatreSystem.cpp
 * @author Luiz Eduardo Garzon.
 * @brief Sistema de Gerenciamento de Reservas em Teatro.
 *        Utiliza uma estrutura Arvore Binaria Balanceada Estaticamente.
 *        O usuario pode adicionar, remover, procurar, editar e exibir as informacoes.
 *        Compile: g++ TheatreSystem.cpp -o ThreatreSystem
 * @version 0.1
 * @date 2024-02-20
 * @copyright Copyright (c) 2024
 */

// Diretivas de Pre-Processamento.
#if defined(_WIN32) || defined(_WIN64) // Se for windows.
#define limpar_tela "cls"              // Limpa tela com cls.
#else                                  // Se for Linux.
#define limpar_tela "clear"            // Limpa tela com clear.
#endif

#include <iostream>
#include <cmath>

// ---------- LISTA SIMPLES ENCADEDA PARA BALANCEAMENTO DA ARVORE ----------

// Classe No da Lista.
class NoLista
{
private:
    NoLista *dir; // Proximo elemento da lista.
    int dadoNo;   // Dado.

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

    // Metodos Getters e Setters.
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

// Classe Lista.
class Lista
{
private:
    NoLista *topo; // Referencias para topo e calda da lista.

public:
    // Construtor Default.
    Lista()
    {
        this->topo = nullptr;
        size = 0;
    }

    // Metodo para verificar se a lista esta vazia.
    bool isEmpty()
    {
        return topo == nullptr ? true : false;
    }

    // Armazena o tamanho da lista.
    int size;

    // Metodos Getters e Setters.
    NoLista *getTopo()
    {
        return this->topo;
    }

    void setTopo(NoLista *no)
    {
        this->topo = no;
    }

    // Metodos da Lista

    // Metodo para adicionar um elemento de forma ordenada na lista.
    void addOrderedTreeERD(int);

    // Metodo para deletar toda a lista.
    void deleteList();

    // Metodo para deletar qualquer no da lista.
    void deleteNode(int);

    // Metodo par imprimir toda a lista.
    void printList();

    // Metodo para dividir a lista em duas partes.
    void devideList(Lista &, Lista &, int);
};

// ---------- ARVORE BINARIA BALANCEADA ESTATICAMENTE ----------

// Classe No da Arvore.
class No
{
private:
    No *esq, *dir; // Nos da direita e esquerda.
    int chave;     // Valor do no.

public:
    // Construtor Default.
    No(int chave)
    {
        this->chave = chave;
        esq = nullptr;
        dir = nullptr;
    }

    // Metodos Getters e Setters.
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
    // Armazena o numero de nos da arvore.
    int tamanho;

    // Construtor Default.
    Arvore()
    {
        raiz = nullptr;
        tamanho = 0;
    }

    // Metodos Getters e Setters.

    No *getRaiz()
    {
        return raiz;
    }

    void setRaiz(No *raiz)
    {
        this->raiz = raiz;
    }

    // Metodos da Arvore.

    // Metodo de insercao de no.
    void inserirNo(int chave);

    // Metodo para remocao de no.
    No *removerNo(No *no, int chave, No *&removido);

    // Metodo para buscar um elemento na arvore.
    int buscarNo(No *raiz, int chave);

    // Metodo para calcular o balanceamento da arvore.
    bool fatorBalanceamento(No *no);

    // Metodo para balancear a arvore.
    No *balancearArvore(No *raiz, Lista lista);

    // Metodo para deletar toda a arvore.
    No *deleteTree(No *raiz);

    // Metodo de busca (ERD) para imprimir a arvore de forma ordenada.
    void inOrdem(No *raiz);

    // Metodo de busca (RED) para imprimir a arvore balanceada.
    void preOrdem(No *raiz);
};

// ---------- ASSINATURA DE METODOS AUXILIARES ----------

void clearScreen(); // Limpa a tela.
void menuOptions(); // Exibe o menu interativo.
int readValues();   // Executa a leitura dos valores.

// Auxiliares da Arvore.
void inserirAux(No *no, int chave, int *tamanho);
int calcularAltura(No *no, int esq, int dir);
void insertListTree(No *raiz, Lista &lista);
No *createBalancedTree(Lista &lista, No *raiz, int *tamanho);
int searchElement(No *raiz, int);

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
    Arvore arvore = Arvore(); // Declara e instancia arvore.
    No *raiz, *removido;      // Declara no raiz.
    Lista lista = Lista();    // Declara e instancia nova lista.

    int op = 0; // Armazena a operacao escolhida pelo usuario.

    do
    {
        removido = nullptr;
        int value = 0,               // Armazena o valor informado para os nos.
            poltrona = 0;            // Armazena o numero da poltrona procurada.
        bool fb_verification = true; // Flag para indicar se a arvore esta desbalanceada.

        // Menu.
        clearScreen();
        std::cout << "\n\n";
        std::cout << "[0] - Encerrar Sistema" << std::endl;
        std::cout << "[1] - Comprar Poltrona" << std::endl;
        std::cout << "[2] - Remover Poltrona" << std::endl;
        std::cout << "[3] - Procurar Poltrona" << std::endl;
        std::cout << "[4] - Atualizar Poltrona" << std::endl;
        std::cout << "[5] - Exibir Poltronas" << std::endl;
        std::cout << "[6] - Exibir Arvore Balanceada" << std::endl;

        // Leitura dos dados.
        std::cout << "\nInforme a Opcao: ";
        std::cin >> op;
        std::getchar();

        clearScreen();
        std::cout << "\n\n";

        // Operacao.
        switch (op)
        {
        case 0:
            std::cout << "Programa Encerrado!\n";
            break;
        case 1:
            value = readValues();    // Leitura.
            arvore.inserirNo(value); // Insere no na arvore.
            raiz = arvore.getRaiz(); // Atualiza a raiz da arvore.

            // Inicia verificacao de balanceamento a partir do 5 elemento.
            if (arvore.tamanho >= 5)
            {
                // Verifica se arvore esta balanceada.
                fb_verification = arvore.fatorBalanceamento(raiz);
                if (!fb_verification)
                {
                    raiz = arvore.balancearArvore(raiz, lista); // Executa balanceamento.
                    arvore.setRaiz(raiz);                       // Atualiza raiz da arvore.
                }
            }

            std::getchar();
            break;
        case 2:
            value = readValues();                           // Leitura.
            raiz = arvore.removerNo(raiz, value, removido); // Remove o no indicado.

            // Se retorno for vazio indica que o elemento fo
            if (removido != nullptr)
            {
                std::cout << "Poltrona Removida: " << value << "\n";
                arvore.tamanho -= 1; // Decrementa o tamanho da arvore.
            }
            else
            {
                std::cout << "Poltrona nao Reservada!\n";
            }

            if (arvore.tamanho >= 5)
            {
                fb_verification = arvore.fatorBalanceamento(raiz);
                if (!fb_verification)
                {
                    raiz = arvore.balancearArvore(raiz, lista);
                    arvore.setRaiz(raiz);
                }
            }

            std::getchar();
            break;
        case 3:
            value = readValues(); // Leitura.

            // Retorna o numero da poltrona buscada.
            poltrona = arvore.buscarNo(raiz, value);
            if (poltrona == value && poltrona != -1)
            {
                std::cout << "Poltrona: " << poltrona << std::endl;
                std::cout << "Poltrona Reservada!\n";
            }
            else
            {
                std::cout << "Poltrona nao reservada!\n";
            }

            std::getchar();
            break;
        case 4:
            value = readValues();                 // Leitura.
            raiz = arvore.removerNo(raiz, value, removido); // Remove o no informado.

            // Se poltrona removida libera para atualizacao.
            if (removido != nullptr)
            {
                std::cout << "Poltrona Removida: " << value
                          << ". Informe a nova poltrona.\n";

                arvore.tamanho -= 1; // Tamanho da arvore decrementado.

                value = readValues();    // Leitura.
                arvore.inserirNo(value); // Insere novo no.
                raiz = arvore.getRaiz(); // Atualiza raiz da arvore.

                // Se raiz nao nula, atualizacao ok.
                if (raiz)
                {
                    std::cout << "Numero de Poltrona Atualizado!\n";
                }
                else
                {
                    std::cout << "Falha ao Atualizar Poltrona!\n";
                }

                if (arvore.tamanho >= 5)
                {
                    fb_verification = arvore.fatorBalanceamento(raiz);
                    if (!fb_verification)
                    {
                        raiz = arvore.balancearArvore(raiz, lista);
                        arvore.setRaiz(raiz);
                    }
                }
            }
            else
            {
                std::cout << "Poltrona nao Reservada!\n";
            }

            std::getchar();
            break;
        case 5:
            std::cout << "Poltronas Reservadas: " << arvore.tamanho << "\n";
            arvore.inOrdem(raiz); // Inicia processo de busca ordenada.
            std::getchar();
            break;
        case 6:
            std::cout << "Arvore Balanceada: " << arvore.tamanho << "\n";
            arvore.preOrdem(raiz); // Inicia processo de busca pre-ordem.
            std::getchar();
            break;
        default:
            std::cout << "Operacao Invalida!\n";
            std::getchar();
            break;
        }
    } while (op != 0); // Repete o menu enquanto a opcao for != 0.
}

// Metodo para ler os valores stdin.
int readValues()
{
    int value = 0;
    std::cout << "Informe o numero da Poltrona: ";
    std::cin >> value;
    std::getchar();
    return value;
}

// ------------------------- Metodos Auxiliares da Arvore.

// Metodo auxiliar de insercao que percorre a Arvore.
void inserirAux(No *no, int chave, int *tamanho)
{
    // Se o valor for menor que o valor do no atual, entao prossegue para esquerda.
    if (chave < no->getChave())
    {
        // Verifica se o no a esquerda e nulo.
        if (no->getEsq() == nullptr)
        {
            No *novoNo = new No(chave); // Declara novo no.
            no->setEsq(novoNo);         // Insere novo no à esquerda do no atual.
            (*tamanho) += 1;            // Incrementa o tamanho da arvore.
        }
        else
        {
            // Caso o no esquerdo nao seja nulo,
            // recursivamente iteramos sobre a parte esquerda.
            inserirAux(no->getEsq(), chave, tamanho);
        }
    }
    else if (chave > no->getChave()) // Prossegue para direita se valor maior que no atual.
    {
        // Mesmo processo de insercao à esquerda.
        if (no->getDir() == nullptr)
        {
            No *novoNo = new No(chave);
            no->setDir(novoNo);
            (*tamanho) += 1;
        }
        else
        {
            inserirAux(no->getDir(), chave, tamanho);
        }
    }
    else if (chave == no->getChave()) // Verifica elemento repitido.
    {
        std::cout << "Poltrona ja Reservada!\n";
    }
    else
    {
        std::cout << "Numero da Poltrona invalido!\n";
    }
}

// Metodo que calcular a altura total a partir de um no dado.
int calcularAltura(No *no, int esq = 0, int dir = 0)
{
    // Retorna altura zero se o no for nulo.
    if (no == nullptr)
        return 0;

    // Armazena a altura da parte esquerda.
    int altura_esquerda = calcularAltura(no->getEsq(), esq + 1, dir);
    // Armazena a altura da parte direita.
    int altura_direita = calcularAltura(no->getDir(), esq, dir + 1);

    // Armazena altura total.
    // Raiz + maximo entre alturas esquerda e direita.
    int altura_total = 1 + std::max(altura_esquerda, altura_direita);

    return altura_total;
}

// Metodo para inserir a arvore na lista.
void insertListTree(No *raiz, Lista &lista)
{
    // Percorre a árvore enquanto não for nula.
    if (raiz != nullptr)
    {
        // Percorre o lado esquerdo.
        insertListTree(raiz->getEsq(), lista);
        // Adiciona elemento.
        lista.addOrderedTreeERD(raiz->getChave());
        // Incrementa o tamanho da lista.
        lista.size += 1;
        // Percorre o lado direito.
        insertListTree(raiz->getDir(), lista);
    }
}

// Metodo para criar arvore balanceada.
No *createBalancedTree(Lista &lista, No *raiz, int *tamanho)
{
    // Verifica se lista vazia.
    if (lista.size == 0 || lista.isEmpty())
    {
        return raiz;
    }

    // Salva o valor central da lista para a raiz da arvore.
    int elementoCentral;

    // Se a lista tiver mais que 1 elemeno, entao
    // podemos dividir e pegar um elemento central.
    if (lista.size > 1)
    {
        elementoCentral = getNoCentral(lista);
        lista.size -= 1; // Decrementa o tamanho da lista.
    }
    else
    {
        // Lista com apenas 1 elemento, entao ele mesmo sera o elementro central.
        elementoCentral = lista.getTopo()->getDadoLista();
        lista.size = 0; // Define o tamanho da lista como 0.
    }

    // Impressoes para avaliacoes nos resultados.
    // std::cout << elementoCentral << "\n";
    // lista.printList();
    // std::cout << lista.size << "\n";

    // Se a raiz for nula entao cria o no raiz.
    if (raiz == nullptr)
    {
        raiz = new No(elementoCentral);
        (*tamanho) += 1; // Incrementa o tamanho da nova arvore.
    }
    else if (lista.size != 0)
    {

        inserirAux(raiz, elementoCentral, tamanho);
    }

    // Lista esquerda, e lista direita.
    Lista listaEsq, listaDir;

    // Se a lista for maior que 1 entao podemos divi-la.
    if (lista.size > 1)
    {
        lista.devideList(listaEsq, listaDir, floor((lista.size / 2)));
        lista.deleteList(); // Deleta a lista original.
    }
    else
    {
        // Senao adicionamos o ultimo elemento e retornamos a nova raiz.
        inserirAux(raiz, lista.getTopo()->getDadoLista(), tamanho);
        lista.deleteList();

        return raiz;
    }

    // Impressoes para avaliacoes.
    // listaEsq.printList();
    // std::cout << listaEsq.size << "\n";

    // listaDir.printList();
    // std::cout << listaDir.size << "\n";

    // Cria recursivamente a nova arvore.
    raiz = createBalancedTree(listaEsq, raiz, tamanho);
    raiz = createBalancedTree(listaDir, raiz, tamanho);

    lista.deleteList(); // deleta a lista original.

    return raiz; // retorna a nova arvore.
}

// Metodo para buscar recursivamente um elemento na arvore.
int searchElement(No *raiz, int chave)
{
    // Verifica se a raiz é nula, ou seja,
    // o elemento nao foi encontrado.
    if (raiz == nullptr)
    {
        return -1;
    }

    // Percore recursivamente a arvore pela esquerda e direita,
    // ate encontrar o elemento buscado.
    if (chave > raiz->getChave())
    {
        return searchElement(raiz->getDir(), chave);
    }
    else if (chave < raiz->getChave())
    {
        return searchElement(raiz->getEsq(), chave);
    }
    else
    {
        return raiz->getChave();
    }
}

// ------------------------- Metodos Auxiliares da Lista.

// Metodo para encontrar o no central da lista.
int getNoCentral(Lista &lista)
{
    // Salva a metade do tamanho da arvore.
    int metade = floor((lista.size / 2));

    // No temporario para percorrer a lista.
    NoLista *tmp = lista.getTopo();

    // Se tamanho impar retorna o valor central.
    // Se tamanho par retorna o valor central da direita.
    for (int i = 0; i < metade; i++)
    {
        tmp = tmp->getNoDir();
    }

    // Salva o dado do no central.
    int dado = tmp->getDadoLista();

    // Deleta o no central.
    lista.deleteNode(dado);

    return dado;
}

// ------------ MÉTODOS DA ARVORE ------------

// Metodo de insercao na Arvore.
void Arvore::inserirNo(int chave)
{
    // Verifica o limite das poltronas.
    if (chave > 100 || chave <= 0)
    {
        std::cout << "Numero de Poltrona Invalida!\n";
    }
    else if (tamanho >= 100) // Verifica se a arvore esta cheia.
    {
        std::cout << "Todas as poltronas ja estao reservadas!\n";
    }
    else
    {
        if (raiz == nullptr) // Verifica se a arvore esta vazia.
        {
            raiz = new No(chave); // Atribui novo no.
            tamanho += 1;         // Incrementa o tamanho da arvore.
        }
        else
        {
            inserirAux(raiz, chave, &tamanho); // Caso nao esteja vazia avanca.
        }
    }
}

// Metodo para remover no da arvore.
// Recebe a raiz da arvore.
// Retorna o novo ponteiro do nó após a remoção.
No *Arvore::removerNo(No *no, int chave, No *&removido)
{
    // Caso base: nó não encontrado.
    if (no == nullptr)
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

// Metodo para buscar um elemento na arvore.
int Arvore::buscarNo(No *raiz, int chave)
{
    // Verifica os limites das poltronas.
    if (chave > 100 || chave <= 0)
    {
        std::cout << "Numero de Poltrona Invalido\n!";
    }
    else if (tamanho == 0) // Verifica se a arvore esta vazia.
    {
        std::cout << "Nenhuma Poltrona Rerservada!\n";
    }
    else if (raiz->getChave() == chave) // Verifica se o elemento é a raiz.
    {
        return raiz->getChave();
    }
    else
    {
        // Busca recursivamente o elemento.
        int el = searchElement(raiz, chave);
        return el;
    }
    return -1;
}

// Metodo para calcular o fator de balanceamento.
bool Arvore::fatorBalanceamento(No *no)
{
    // Fator 0 se altura 0.
    if (no == nullptr)
    {
        return true;
    }

    // Armazenando a altura esquerda e direita.
    int altura_esquerda = calcularAltura(no->getEsq());
    int altura_direita = calcularAltura(no->getDir());

    // Armazena o valor absoluto da diferenca das alturas.
    int dif_altura = std::abs(altura_esquerda - altura_direita);

    // Se a diferenca for maior que 1 entao a arvore esta desbalanceada.
    if (dif_altura > 1)
    {
        return false;
    }

    // Calcula recursivamente para cada subarvore.
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
        // Inicia lista com tamanho 0.
        lista.size = 0;

        // Insere a arvore na lista.
        insertListTree(raiz, lista);

        // Deleta a arvore atual e reseta o tamanho.
        raiz = deleteTree(raiz);
        setRaiz(nullptr);
        tamanho = 0;

        // Metodo para criar a arvore balanceada.
        raiz = createBalancedTree(lista, raiz, &tamanho);

        // Impressao para verificacoes.
        // lista.printList();
        // std::cout << lista.size << "\n";

        // Deletaa a lista.
        lista.deleteList();
    }

    return raiz;
}

// Metodo de busca inOrdem (ERD).
void Arvore::inOrdem(No *raiz)
{
    // Verifica se o no é vazio.
    if (raiz != nullptr)
    {
        // Percorre pela esquerda.
        inOrdem(raiz->getEsq());

        // Imprime o no.
        std::cout << raiz->getChave() << " ";

        // Percorre pela direita.
        inOrdem(raiz->getDir());
    }
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
        novoNo->setNoDir(topo); // Novo aponta para o primeiro elemento da lista.
        topo = novoNo;          // Inicio da lista recebe o novo no.
        return;
    }

    // Percorre a lista para encontrar a posição correta para inserir o novo nó
    NoLista *tmp = topo;

    // Percorre enquanto o no nao for nulo e a chave for maior que o no.
    while (tmp->getNoDir() != nullptr && tmp->getNoDir()->getDadoLista() < chave)
    {
        tmp = tmp->getNoDir();
    }

    // Insere o novo nó após o nó atual
    novoNo->setNoDir(tmp->getNoDir());
    tmp->setNoDir(novoNo);
}

// Metodo que imprime toda a lista.
void Lista::printList()
{
    if (topo != nullptr)
    {
        // Percorre a lista ate o fim.
        for (NoLista *tmp = topo; tmp != nullptr; tmp = tmp->getNoDir())
        {
            std::cout << tmp->getDadoLista() << " ";
        }
        std::cout << std::endl;
    }
    else
    {
        std::cout << "Nenhuma Poltrona Reservada" << std::endl;
    }
}

// Metodo que deleta toda a lista.
void Lista::deleteList()
{
    NoLista *tmp = topo;
    NoLista *prox;

    while (tmp != nullptr)
    {
        prox = tmp->getNoDir(); // Salva o próximo nó antes de excluir o atual.
        delete tmp;             // Exclui o nó atual.
        tmp = prox;             // Move para o próximo nó.
    }

    // Após excluir todos os nós, atualiza o topo e o tamanho da lista.
    topo = nullptr;
    size = 0;
}

// Metodo para deletar qualquer elemento da lista.
void Lista::deleteNode(int el)
{
    // Verifica se a lista esta vazia.
    if (topo == nullptr)
    {
        return;
    }

    // No temporario para percorrer a lista.
    NoLista *tmp = topo;

    // Verifica se o elemento procurado é o primeiro
    if (el == tmp->getDadoLista())
    {
        // Verifica se lista possui apenas um elemento
        if (topo->getNoDir() == nullptr)
        {
            topo = nullptr;
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

        // Percorre enquanto o elemento for diferento do procurado,
        // e enquanto nao chegar ao fim da lista.
        while (el != tmp->getDadoLista() && tmp)
        {
            anterior = tmp;
            tmp = tmp->getNoDir();
        }

        // Verifica se é o elemento procurado
        if (tmp && el == tmp->getDadoLista())
        {
            anterior->setNoDir(tmp->getNoDir());
            delete tmp;
        }
    }
}

// Metodo para dividir a lista em duas partes.
void Lista::devideList(Lista &esq, Lista &dir, int elementoCentral)
{
    // Limpa as listas.
    esq.deleteList();
    dir.deleteList();

    // Armazena lado esquerdo.

    // Armazena o inicio da lista para percorrer.
    NoLista *tmp = topo;

    // Armazena o lado esquerdo ate a primeira metade da lista original.
    for (int i = 0; i < elementoCentral; i++)
    {
        esq.addOrderedTreeERD(tmp->getDadoLista()); // Adiciona no no a lista esquerda.
        tmp = tmp->getNoDir();                      // Avanca sobre a lista original.
    }
    esq.size = elementoCentral;

    // Armazena lado direito.

    int i = 0;

    // Armazena o restante da lista original ate que seja nula.
    for (tmp; tmp != nullptr; tmp = tmp->getNoDir())
    {
        dir.addOrderedTreeERD(tmp->getDadoLista());
        i += 1;
    }
    dir.size = i;
}
