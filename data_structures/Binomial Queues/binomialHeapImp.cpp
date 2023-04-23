#include <iostream>
using namespace std;

// A binomial tree node
struct Node{
    int data;
    int degree;
    Node *child;
    Node *sibling;
    Node *parent;
};

Node* newNode(int key){
    Node *temp = new Node();
    temp->data = key;
    temp->child = NULL;
    temp->parent = NULL;
    temp->sibling = NULL;
    temp->degree = 0; // think about depth in tree 

    return temp; // returning the new node  
}

//This function merge two binomial trees
Node* mergeBinomialTree(Node *smaller, Node *bigger){
    // 
    if(smaller->data > bigger->data)
      swap(smaller,bigger);

      bigger->data = smaller;
      bigger->sibling = smaller->child;
      smaller->child = bigger;
      smaller->degree = smaller->degree + 1;

      return smaller;
}

//This function perform union operation on two binomial heap 
list<Node*> unionBinomialHeap (list<Node*> first, list<Node*> second){
    // _new to another binomial heap which contain
  // new heap after merging first & second
  list<Node*> _new;
  list<Node*>::iterator it = first.begin();
  list<Node*>::iterator ot = second.begin();
  
}