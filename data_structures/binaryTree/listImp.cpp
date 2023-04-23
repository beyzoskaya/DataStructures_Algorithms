#include <iostream>
#include <queue>
using namespace std;

struct ListNode
{
    int data;
    ListNode *next;
};

struct BinaryTreeNode
{
    int data;
    BinaryTreeNode *right;
    BinaryTreeNode *left;
};

void push(ListNode *head, int data)
{
    ListNode *new_node = new ListNode();
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

BinaryTreeNode *newBinaryTreeNode (int data)
{
    BinaryTreeNode *temp = new BinaryTreeNode();
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void convertListToBinary(ListNode *head, BinaryTreeNode *root)
{
    queue<BinaryTreeNode *> q;
}