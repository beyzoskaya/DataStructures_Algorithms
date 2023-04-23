/*
recent element access ---> O(1)
splay tree runs on average O(logn) ---> n entries of a tree
*/

#include <iostream>
using namespace std;

struct node 
{
    int data;
    node *right;
    node *left;
};

node *newNode(int key)
{
    node *Node = new node();
    Node->data = key;
    Node->left = NULL;
    Node->right = NULL;
    return Node;
}

node *rightRotate(node *x)
{
    node *y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}

node *leftRotate(node *x)
{
    node *y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}