/*
AVL Tree is a self balancing Binary Search Tree 
difference between heights of left subtrees cannot be more than one for all nodes

                              12
                            /   \
                          8      18
                        /   \    /
                       5     11 17 
                      /
                     4   

Above tree is AVL Tree because the differences between the heights of left and right subtrees 
for every node are less than or equal to 1

                              12
                            /   \
                          8      18
                        /   \    /
                       5     11 17 
                      /  \
                     4    7 
                    /
                   2     
This is not an AVL Tree because different for left and right subtrees are more than 1 for 12 and 8

If we control after every insertion to the tree ---> tree's height is O(log(n)) --> n is the number of nodes 


Steps for Insertion to AVL Tree
1-Perform standart BST insert for w 
2- Starting from w, travel up and find the first unbalanced node.
3- Rebalance the tree by performing appropriate rotations on the subtree rooted with z.
*/


#include <iostream>
using namespace std;

class Node{
    public:
    int key;
    Node *left;
    Node *right;
    int height;
};

// we need to find heigth of a tree for controlling the balance condition for a new rotation

int height(Node *N){
    if (N==NULL){
        return 0; // in this case we do not have any root 
    }else{
        return N->height;
    }
}

// control for less or greater then get the maximum one from parent child nodes
int max(int a, int b){
    return (a > b) ? a:b;
}

Node *newNode(int key){
    Node *newNode = new Node();
    newNode->key = key;
    newNode->height = 1;
    newNode->left = NULL;
    newNode->right = NULL;

    return(newNode);
}

Node *rightRotate(Node *y){
    Node *x = y->left;
    Node *T2 = x->right;

    // rotation done here 
    x->right = y;
    y->left = T2;
    
    //after rotating the nodes we need to update heights

    y->height = max(height(y->left), 
                    height(y->right)) + 1;
    x->height = max(height(x->left), 
                    height(x->right))+1;  

     return x; // x is the new root node                              
}

Node *leftRotate(Node *y){
    Node *x = y->right;
    Node *T2 = x->left;

    x->left = y;
    y->right = T2;

    y->height = max(height(y->right), 
                    height(y->left)) + 1;
    x->height = max(height(x->left), 
                    height(x->right)) + 1;

     return y;               
}

// we need to calculate balance factor for rotation is needed or not 
int getBalanceFactor(Node *N){
    if(N == NULL)
       return 0;
    return height(N->left) - height(N->right);  
}

Node *insert(Node *node, int key){

    /*
    Perform normal BST first
    */

   if(node == NULL)
      return(newNode(key));

   if(key < node->key)
      node->left = insert(node->left, key);
   else if(key > node->key)
      node->right = insert(node->right, key);
   else
      return node;

   node->height = 1 + max(height(node->left), height(node->right));

   int balance = getBalanceFactor(node);

   /*
   If this node becomes unbalanced, then there are 4 cases 
   */            

  // Left-Left Case
  if(balance > 1 && key < node->left->key)
    return rightRotate(node);

  // Right-Right Case
  if(balance < -1 && key > node->right->key)
     return leftRotate(node);

  // Left-Right Case
  if(balance > 1 && key > node->left->key){
     node->left = leftRotate(node->left);
     return rightRotate(node);  
}
  // Right-Left Case
  if(balance < -1 && key < node->right->key){
     node->right = rightRotate(node->right);
     return leftRotate(node);
}
    return node;       
}


/*
void rotate WithLeftChild(AvlNode *& k2){
    AvlNode *k1 = k2->left;
    k2-> left = k1->right;
    k1->right = k2;
}
*/

/*
struct AvlNode{
    Comparable element;
    AvlNode *left;
    AvlNode *right;
    int height;
    
}


*/