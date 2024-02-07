/*
    Implementacao de uma Arvore Binaria de Busca utilizando struct.
*/
#include <cstdio>
using namespace std;

// Estrutura Nó da Arvore
struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Funcao que retorna um no Nó da Arvore
Node *GetNewroot(int data)
{
    Node *newroot = new Node();
    newroot->data = data;
    newroot->left = NULL;
    newroot->right = NULL;
    return newroot;
}

// Funcao para inserir na Arvore
Node *Insert(Node *root, int data)
{
    if (root == NULL)
    {                            // Arvore vazia
        root = GetNewroot(data); // instancia novo nó
        return root;
    }
    else if (data <= root->data) // insere na esquerda da raiz
    {
        root->left = Insert(root->left, data);
    }
    else
    {
        root->right = Insert(root->right, data); // insere na direita da raiz
    }

    return root;
}

// Visitar em sequência a raiz, a subárvore esquerda e a subárvore direita.
void printPreOrder(struct Node *root)
{
    if (root == NULL)
        return;
    printf(" %i", root->data);
    printPreOrder(root->left);
    printPreOrder(root->right);
}

// visitar em sequência a subárvore esquerda, a raiz e a subárvore direita.
void printInOrder(struct Node *root)
{
    if (root == NULL)
        return;
    printInOrder(root->left);
    printf(" %i", root->data);
    printInOrder(root->right);
}

// visitar em sequência a subárvore esquerda, a subárvore direita e a raiz.
void printPosOrder(struct Node *root)
{
    if (root == NULL)
        return;
    printPosOrder(root->left);
    printPosOrder(root->right);
    printf(" %i", root->data);
}

int main()
{
    int c, n, x, count = 1;

    // Numero de testes
    scanf("%i", &c);

    for (int i = 0; i < c; ++i)
    {
        Node *root = NULL; // Declara Nó vazio
        scanf("%i", &n);   // Numero de elementos a serem inseridos na Arvore

        for (int j = 0; j < n; ++j)
        {
            scanf("%i", &x);
            root = Insert(root, x); // Insere elemento lido na arvore
        }

        printf("Case %i:\n", count);
        printf("Pre.:");
        printPreOrder(root);
        printf("\n");

        printf("In..:");
        printInOrder(root);
        printf("\n");

        printf("Post:");
        printPosOrder(root);
        printf("\n");

        count++;
        // if(i != (c - 1))
        printf("\n");
    }

    return 0;
}