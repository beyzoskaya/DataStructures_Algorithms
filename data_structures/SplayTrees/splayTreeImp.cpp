/*
AVL Tree 
B-tree
Red-Black Tree
These are can not be right or left skewed
These are already self balanced trees
O(logn)
Can we do better than this complexity ? YES --> Splay Tree

operations for splay tree: search, insert, delete, splaying
Splay trees are roughly balanced trees but AVL trees are strictly balanced trees

                    10 
                  /    \
                 7      20
                / \       \
               1   9       30

In this tree, we want to search 7
normal BTS searching kind of search ----> search + splaying
we are going to do 7 root of the tree ---> now 10 is the root 
after searching we found the 7 then do the 7 root
self-adjusted BST
rearrenge the tree so that this element can become the root of the tree (each iteration)

recently accessed elements are quick to access again 
splaying cost ---> O(h) h is the height of the tree
O(h) rotations each of which is O(1)

single right-rotation ---> ZIG           5                      3
                                      /     \                 /   \
                                     3       6               2      5
                                    / \                            /  \           
                                   2   4                          4    6


single left-rotation ---> ZAG            3                      5
                                      /     \                 /   \
                                     2       5               3      6
                                            /  \            /  \                       
                                           4    6          2    4

double right-rotation ---> ZIG-ZIG
                                        5                       2                                                                                      
                                      /   \                       \   
                                     3     6                        3
                                    /  \                              \   
                                   2    4                               5
                                                                       /  \ 
                                                                      4     6      
double left-rotation ---> ZAG-ZAG
                                        3                         6   
                                       /  \                     /          
                                      2    5                   5
                                          /  \                / 
                                         4    6              3                                                                
                                                            / \   
                                                           2   4
single right -single left-rotation ---> ZIG-ZAG
single left -single right-rotation ---> ZAG-ZIG                                                            
*/  

#include <iostream>
using namespace std;

class node{
    public:
    int key;
    node *left;
    node *right;
};

node *newNode(int key){
    node *Node = new node();
    Node->key = key;
    Node->left = NULL;
    Node->right = NULL;

    return (Node);
}

node *rightRotate(node *x){
    node *y = x->left;
    x->left = y->right;
    y->right = x;

    return y;
}

node *leftRotate(node *x){
    node *y = x->right;
    x->right = y->left;
    y->left = x;

    return y;
}

node *splay(node *root, int key){
    if(root == NULL || root->key = key)
         return root;
    // key lies in left subtree 
      if(root->key > key)
        if(root->key == NULL) return root;

        // Zig-zig (left-left)
        if(root->left->key > key){
           root->left->left = splay(root->left->left,key);

           root = rightRotate(root);
    }
        // Zig-Zag (left-right)
        else if (root->left->key < key){
            root->left->right = splay(root->left->right,key);

            if(root->left->right != NULL)
                 root->left = leftRotate(root->left);
        }
            return (root->left == NULL) ? root : rightRotate(root);

}

/*
inserting new element takes contant time if we have enough size (not depend on the n) ---> O(1)
if no space left buying a new facility ---> O(1)
                 move all elements to the new facility ---> O(n)

*/