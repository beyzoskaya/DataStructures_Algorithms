/*
not all operations have the same cost 
disk access is much slower than memory access

Goal ---> reduce the number of disk accesses 

Increasing branching reduces the depth and allows
faster access to the leaf nodes, where data is stored


balanced m-way tree 
generalization of BST in which a node can have 
more than one key and more than 2 children

all leaf nodes must be at same level

B-tree of order m has following prop:
every node has max m children

leaf node has 0 children

minimum children:
leaf -> 0
root -> 2
internal nodes -> [m/2]

maximum keys:
m-1

minimum key:
root node -> 1
all other nodes -> [m/2]-1

m = 3
max key -> m-1 -> 3-1=2

1|2 --> we cannot insert 3 here because max key element size is 2 due to m 

all search paths have same length 
--> as m increases/ height decreases


Example: 
-block size:8192 bytes
-key size: 32 bytes
data record size: 256 bytes
nonleaf B-tree node stores M-1 keys and M branches --> 32(M-1) + 4M


we have 2 options for implemented B-tree
option 1: dynamic node representation
option 2: array representation
 */

#include <iostrem>
using namespace std;

struct node{
    int *key;
    int n; // number of keys in tree for controlling the size is full or not
    node** child;
    bool leaf;
    node(int degree){
        key = new int[degree];
        leaf = true; // while creating a new node --> this is strictly leaf
        child = new node*[degree+1];
        n = 0;
        for(int i=0; i<degree; i++){
            child[i] = NULL; // initialize all the elements to Null 
        } 
    }

    node* findNode(int data,node* temp,int t){

    }
};

class bTree{
    private:
        node *root;
        int t; // degree
    public:
        bTree(int degree ){
            root = NULL;
            t = degree;
        }     
    void insert(int data){
        if(root == NULL){
             root = new node(t);
             root->leaf = true; 
             root->key[0] = data;
             root->n = 1;
        }
        else{
            root->findNode(data,root,t); 
        }
    }    
};

void node::findNode(int data,node* node_active,int t){
    if(leaf){
        int i = t;
    }
}