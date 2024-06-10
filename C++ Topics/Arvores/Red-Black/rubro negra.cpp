#include <iostream>

enum Color
{
    RED,
    BLACK
};

template <typename T>
class Node
{
public:
    T data;
    Node<T> *left;
    Node<T> *right;
    Node<T> *parent;
    Color color;

    Node(T val) : data(val), left(NULL), right(NULL), parent(NULL), color(RED) {}
};

template <typename T>
class RedBlackTree
{
private:
    Node<T> *root;

    void rotateLeft(Node<T> *&root, Node<T> *node)
    {
        Node<T> *rightChild = node->right;
        node->right = rightChild->left;

        if (rightChild->left != NULL)
            rightChild->left->parent = node;

        rightChild->parent = node->parent;

        if (node->parent == NULL)
            root = rightChild;
        else if (node == node->parent->left)
            node->parent->left = rightChild;
        else
            node->parent->right = rightChild;

        rightChild->left = node;
        node->parent = rightChild;
    }

    void rotateRight(Node<T> *&root, Node<T> *node)
    {
        Node<T> *leftChild = node->left;
        node->left = leftChild->right;

        if (leftChild->right != NULL)
            leftChild->right->parent = node;

        leftChild->parent = node->parent;

        if (node->parent == NULL)
            root = leftChild;
        else if (node == node->parent->left)
            node->parent->left = leftChild;
        else
            node->parent->right = leftChild;

        leftChild->right = node;
        node->parent = leftChild;
    }

    void fixViolation(Node<T> *&root, Node<T> *node)
    {
        Node<T> *parent = NULL;
        Node<T> *grandParent = NULL;

        while ((node != root) && (node->color != BLACK) && (node->parent->color == RED))
        {
            parent = node->parent;
            grandParent = parent->parent;

            /*  Case : A
                Parent of node is left child of Grand-parent of node */
            if (parent == grandParent->left)
            {
                Node<T> *uncle = grandParent->right;

                /* Case : 1
                The uncle of node is also red Only Recoloring required */
                if (uncle != NULL && uncle->color == RED)
                {
                    grandParent->color = RED;
                    parent->color = BLACK;
                    uncle->color = BLACK;
                    node = grandParent;
                }
                else
                {
                    /* Case : 2
                    node is right child of its parent Left-rotation required */
                    if (node == parent->right)
                    {
                        rotateLeft(root, parent);
                        node = parent;
                        parent = node->parent;
                    }

                    /* Case : 3
                    node is left child of its parent Right-rotation required */
                    rotateRight(root, grandParent);
                    std::swap(parent->color, grandParent->color);
                    node = parent;
                }
            }
            else
            {
                /* Case : B
                Parent of node is right child of Grand-parent of node */
                Node<T> *uncle = grandParent->left;

                /* Case : 1
                The uncle of node is also red Only Recoloring required */
                if ((uncle != NULL) && (uncle->color == RED))
                {
                    grandParent->color = RED;
                    parent->color = BLACK;
                    uncle->color = BLACK;
                    node = grandParent;
                }
                else
                {
                    /* Case : 2
                    node is left child of its parent Right-rotation required */
                    if (node == parent->left)
                    {
                        rotateRight(root, parent);
                        node = parent;
                        parent = node->parent;
                    }

                    /* Case : 3
                    node is right child of its parent Left-rotation required */
                    rotateLeft(root, grandParent);
                    std::swap(parent->color, grandParent->color);
                    node = parent;
                }
            }
        }

        root->color = BLACK;
    }

    void inorderHelper(Node<T> *root)
    {
        if (root == NULL)
            return;

        inorderHelper(root->left);
        std::cout << root->data << " ";
        inorderHelper(root->right);
    }

public:
    RedBlackTree() : root(NULL) {}

    void insert(const T &value)
    {
        Node<T> *newNode = new Node<T>(value);
        root = insertNode(root, newNode);
        fixViolation(root, newNode);
    }

    Node<T> *insertNode(Node<T> *&root, Node<T> *newNode)
    {
        if (root == NULL)
            return newNode;

        if (newNode->data < root->data)
        {
            root->left = insertNode(root->left, newNode);
            root->left->parent = root;
        }
        else if (newNode->data > root->data)
        {
            root->right = insertNode(root->right, newNode);
            root->right->parent = root;
        }

        return root;
    }

    void inorder()
    {
        inorderHelper(root);
    }
};

int main()
{
    RedBlackTree<int> tree;

    tree.insert(7);
    tree.insert(3);
    tree.insert(18);
    tree.insert(10);
    tree.insert(22);
    tree.insert(8);
    tree.insert(11);
    tree.insert(26);

    std::cout << "Inorder traversal of the constructed Red-Black tree is: ";
    tree.inorder();
    std::cout << std::endl;

    return 0;
}
