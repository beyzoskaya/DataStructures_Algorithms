#include <iostream>

using namespace std;

class Node
{
    int data;
    Node* next;
};

class Stack
{
    node *front; // head of the list
    public:
        Stack()
        {
            front = NULL;
        }
    void push(int); // front'a yeni bir node ekler
    void pop();    // front'taki node'u remove eder
    int top();    // top node'u return eder
};

void Stack::push(int d)
{
    Node *temp = new Node();
    temp->data = d;

    if(front == NULL){
        temp->next = NULL;
    }
    else
    {
        temp->next = front;
    }
    front = temp;
}

void Stack::pop()
{
    if(front == NULL)
    {
        cout << "UNDERFLOW" << endl;
    } else {
        Node *temp = front;
        front = front-> next;
        delete(temp);
    }
}

class StackNode 
{
    public:
        int data;
        StackNode *next;
};

StackNode* newNode(int data)
{
    StackNode *newNode = new StackNode();
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int isEmpty(StackNode* root)
{
    return !root;
}