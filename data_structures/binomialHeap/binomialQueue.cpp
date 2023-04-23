#include <iostream>
#include <list>
#include <queue>
using namespace std;

struct Node
{
    int data;
    int degree;
    Node *child;
    Node *sibling;
    Node *parent;
};

Node *newNode(int key)
{
    Node *temp = new Node();
    temp->data = key;
    temp->degree = 0;
    temp->child = temp->sibling = temp->parent = NULL;
    return temp;
}

Node *mergeBinomialTrees(Node *b1, Node *b2)
{
    if(b1->data > b2->data)
        swap(b1,b2);

    b2->parent = b1;
    b2->sibling = b1->child;
    b1->child = b2;
    b1->degree++;

    return b1;    
}

list<Node*> unionBinomialHeap(list<Node*> l1, list<Node*>l2)
{
    list<Node*> _new;
    list<Node*>::iterator it = l1.begin();
    list<Node*>::iterator ot = l2.begin();

    while(it != l1.end() && ot != l2.end())
    {
        if((*it)->degree <= (*ot)->degree)   
        {
            _new.push_back(*it);
            it++;
        } else {
            _new.push_back(*ot);
            ot++;
        }
    }

    while(it != l1.end())
    {
        _new.push_back(*it);
        it++;
    }
    while(ot != l2.end())
    {
        _new.push_back(*ot);
        ot++;
    }
    return _new;
} 

/*
Return the result of merging equal-sized t1 and t2

    BinomialNode *combineTrees(BinomialNode* t1, BinomialNode* t2)
    {
        if(t2->element < t1-> element)
            return combineTrees(t2,t1);
        t2->NextSibling = t1->leftChild;
        t1->leftChild = t2;
        return t1;
    }
*/

int main()
{
    priority_queue<int> *q = new priority_queue<int>();
    q->push(24);
    q->push(32);
    q->push(25);
    cout << q->top() << endl; // prints out --> 32
    delete q;
    
    return 0;
}

/*
#include <iostream>
#include <queue>
using namespace std;

typedef std :: priority_queue<int,
std::vector<int>,
std::greater<int>> min_heap;

int main()
{
    min_heap *mh = new min_heap();
    q->push(24);
    q->push(32);
    q->push(25);
    cout << q->top() << endl; ---> prints 24
}
*/
