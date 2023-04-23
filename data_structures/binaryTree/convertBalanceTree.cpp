#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

void storeBSTNodes(Node *root, vector<Node*> &nodes)
{
    if(root == NULL)
        return;

    // Inorder traverse
    storeBSTNodes(root->left, nodes);
    nodes.push_back(root);
    storeBSTNodes(root->right, nodes);    
}

Node *buildTreeUtil(vector<Node*> &nodes, int start, int end)
{
        if(start > end)
            return NULL;
        int middle = (start + end)/2;
        Node *root = nodes[middle];

        root->left = buildTreeUtil(nodes, start, middle-1);
        root->right = buildTreeUtil(nodes, mid+1, end);

        return root;    
}

Node *balanceTree(Node *root)
{
    vector<Node*> nodes;
    storeBSTNodes(root,nodes);

    int n = nodes.size();
    return buildTreeUtil(nodes,0,n-1);
}