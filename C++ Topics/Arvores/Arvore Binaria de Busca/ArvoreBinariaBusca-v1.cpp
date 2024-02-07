/*
    Implementacao de uma Arvore Binaria de Busca utilizando classe.
*/
#include <iostream>
using namespace std;

// Classe Nó da Árvore
class Node
{
public:
    int data;    // Dado armazenado pelo nó
    Node *left;  // Filho esquerdo do nó
    Node *right; // Filho direito do nó

    // Construtor da Classe Node
    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Classe BinarySearchTree contém as operações principais da ABB
class BinarySearchTree
{
private:
    Node *root; // Raiz da árvore

public:
    BinarySearchTree();     // Construtor da Classe BinarySearchTree
    void insert(int value); // Insere um valor na árvore
    void remove(int value); // Remove um valor da árvore
    bool search(int value); // Verifica se um valor existe na árvore
    void printPreOrder();   // Imprime a árvore na ordem pré-ordem
    void printInOrder();    // Imprime a árvore na ordem in-ordem
    void printPostOrder();  // Imprime a árvore na ordem pós-ordem

private:
    Node *insertNode(Node *node, int value); // Insere um valor em um nó
    Node *removeNode(Node *node, int value); // Remove um valor de um nó
    Node *findMinNode(Node *node);           // Encontra o nó com o menor valor em uma subárvore
    bool searchNode(Node *node, int value);  // Verifica se um valor existe em um nó
    void printPreOrder(Node *node);          // Imprime a árvore na ordem pré-ordem recursivamente
    void printInOrder(Node *node);           // Imprime a árvore na ordem in-ordem recursivamente
    void printPostOrder(Node *node);         // Imprime a árvore na ordem pós-ordem recursivamente
};

/****************************
 *   METODOS CONSTRUTORES    *
 *****************************/

// Construtor da Classe BinarySearchTree
BinarySearchTree::BinarySearchTree()
{
    // Responsável por inicializar a raiz da árvore como nullptr.
    root = nullptr;
}

/****************************
 *   OPERACOES NA ARVORE     *
 *****************************/

void BinarySearchTree::insert(int value)
{
    // Insere um novo valor na árvore chamando a função auxiliar insertNode.
    root = insertNode(root, value);
}

Node *BinarySearchTree::insertNode(Node *node, int value)
{
    /*
       Percorre lado esquerdo e direito da árvore
       até que encontrem a sua respectiva posicao vazia
       de acordo com as regras estabelecidas.

       RAIZ----------SUB1 ---------VAZIO------------------
       node->left -> node->left -> nullptr (2x insertNode)
       node->left -> node->left -> creatNode(value)
       node->left -> node->left -> newNode
   */

    if (node == nullptr) // cria nó se árvore vázia
    {
        return new Node(value);
    }

    if (value < node->data) // Se valor for menor  que o do nó
    {
        node->left = insertNode(node->left, value);
    }
    else if (value > node->data) // Se valor for maior que o do nó
    {
        node->right = insertNode(node->right, value);
    }

    return node;
}

void BinarySearchTree::remove(int value)
{
    // Remove um valor da árvore chamando a função auxiliar removeNode.
    root = removeNode(root, value);
}

Node *BinarySearchTree::removeNode(Node *node, int value)
{
    if (node == nullptr) // Se arvore vazia
    {
        return node;
    }

    // Comeca a partir da raiz
    if (value < node->data)
    {
        node->left = removeNode(node->left, value); // lado esquerdo se for menor que o no atual
    }
    else if (value > node->data)
    {
        node->right = removeNode(node->right, value); // lado direiro se for maior que o no atual
    }
    else
    {
        // Encontrando o nó desejado verificamos os filhos dele
        if (node->left == nullptr && node->right == nullptr) // se ambos os filhos do no vazios
        {
            delete node;
            node = nullptr;
        }
        else if (node->left == nullptr) // se apenas lado esquerdo vazio
        {
            Node *temp = node;  // no auxiliar
            node = node->right; // posicao do elemento removido recebe o no direito copiado
            delete temp;        // deleta o no auxiliar com o no a ser removido
        }
        else if (node->right == nullptr) // se apenas lado direito vazio
        {
            Node *temp = node;
            node = node->left;
            delete temp;
        }
        else
        { // Se ambos os lados existentes percorre pelo sucessor
            Node *temp = findMinNode(node->right);
            node->data = temp->data;
            node->right = removeNode(node->right, temp->data);
        }
    }

    return node;
}

Node *BinarySearchTree::findMinNode(Node *node)
{
    // A funçao que encontra o nó com o menor valor em uma subárvore.
    while (node->left != nullptr)
    {
        node = node->left;
    }

    return node;
}

bool BinarySearchTree::search(int value)
{
    // Verifica se um determinado valor existe na árvore chamando a função auxiliar searchNode.
    return searchNode(root, value);
}

bool BinarySearchTree::searchNode(Node *node, int value)
{
    // A função searchNode busca recursivamente um valor na árvore.
    if (node == nullptr) // se arvore vazia
    {
        return false;
    }

    if (value == node->data) // se o valor estiver no primeiro no
    {
        return true;
    }
    else if (value < node->data)
    {
        return searchNode(node->left, value); // percorre pela esquerda se o valor for menor
    }
    else
    {
        return searchNode(node->right, value); // percorre pela direita se o valor for maior
    }
}

/*****************************************
 *   OPERACOES DE PERCURSO DA ARVORE     *
 *****************************************/

void BinarySearchTree::printPreOrder()
{
    printPreOrder(root);
    cout << endl;
}

void BinarySearchTree::printPreOrder(Node *node)
{
    if (node != nullptr)
    {
        cout << node->data << " ";
        printPreOrder(node->left);
        printPreOrder(node->right);
    }
}

void BinarySearchTree::printInOrder()
{
    printInOrder(root);
    cout << endl;
}

void BinarySearchTree::printInOrder(Node *node)
{
    if (node != nullptr)
    {
        printInOrder(node->left);
        cout << node->data << " ";
        printInOrder(node->right);
    }
}

void BinarySearchTree::printPostOrder()
{
    printPostOrder(root);
    cout << endl;
}

void BinarySearchTree::printPostOrder(Node *node)
{
    if (node != nullptr)
    {
        printPostOrder(node->left);
        printPostOrder(node->right);
        cout << node->data << " ";
    }
}

int main()
{
    BinarySearchTree A;

    /*
          8
        /   \
       3     10
      / \     \
     1   6     14
        / \   /
       4   7 13
    */

    // Inserindo valores na árvore
    A.insert(8);
    A.insert(3);
    A.insert(10);
    A.insert(14);
    A.insert(6);
    A.insert(4);
    A.insert(13);
    A.insert(7);
    A.insert(1);

    cout << "Pre-Ordem: raiz, subarvore esquerda, subarvore direita." << endl;
    A.printPreOrder(); // raiz, subárvore esquerda, subárvore direita.

    cout << "In-Ordem: subarvore esquerda, raiz, subarvore direita." << endl;
    A.printInOrder(); // subárvore esquerda, raiz, subárvore direita.

    cout << "Pos-Ordem: subarvore esquerda, subarvore direita, raiz." << endl;
    A.printPostOrder(); // subárvore esquerda, subárvore direita, raiz

    return 0;
}
