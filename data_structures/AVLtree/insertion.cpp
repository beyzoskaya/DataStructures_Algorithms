#include <iostream>
using namespace std;

struct Node
{
    public:
        int key;
        Node *left;
        Node *right;
        int height;
};

int height(Node *N)
{
    if(N == NUL)
        return 0;
    return N->height;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

Node *newNode (int key)
{
    Node *newNode = new Node();
    newNode->key = key;
    newNode->right = NULL;
    newNode->left = NULL;
    newNode->height = 1;

    return newNode;
}

Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left),height(y->right))+1;
    x->height = max(height(x->left),height(x->right))+1;

    return x;
}

Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left),   
                    height(x->right)) + 1;
    y->height = max(height(y->left),
                    height(y->right)) + 1;
    return y;                
}

int getBalance(Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

Node *insert (Node *node, int key)
{
    if(node == NULL)
        return (newNode(key));

     if(key < node->key)
        node->left = insert(node->left, key)
    else if (key > node->key)
        node->right = insert(node->right,key)
    else 
        return node;

        node->height = 1 + max(height(node->left), height(node->right));

        int balance = getBalance(node);
                   
}