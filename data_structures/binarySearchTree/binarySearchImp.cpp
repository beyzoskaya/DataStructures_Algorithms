/*
breadth first traversal -> level'lara göre printleniyor 
önce level 0'da olan sonra level 1'de 
right left subtree fark etmiyor
*/

#include <iostream>
using namespace std;

class TreeNode
{
    public:
        int value;
        TreeNode *left;
        TreeNode *right;   
    TreeNode() // default constructor
    {
        value = 0;
        left = NULL;
        right = NULL;
    }     
    TreeNode(int value)
    {
        value = value;
        left = NULL;
        right = NULL;
    } 
};

class BST 
{
    public:
        TreeNode *root;
        
        boolIsEmpty()
        {
            if(root == NULL)
            return true;
            else
            return false;
        }
}

void insertNode(TreeNode *new_node)
{
    if(root == NULL){
        root = new_node;
        cout<<"Value inserted!" <<endl;
    } else {
        TreeNode *temp = root;
        while(temp !=NULL){
            if(new_node->value == temp->value)
            {
                cout << "Value already exist! Insert another value!" << endl;
                return;
            } else if((new_node->value < temp->value) && (temp->left==NULL))
            {
                temp->left = new_node;
                cout<<"Value inserted!"<<endl;
                break;
            } else if (new_node->value < temp->value)
            {
                temp = temp->left; 
            } else if ((new_node->value > temp->value) && temp->right == NULL)
            {
                temp->right = new_node;
                cout <<"Value inserted to the right! " << endl;
                break;
            }else{
                temp = temp->right;
            }

        }
    }
}

/*
Binary Search 
In array based implementation

function binary_search(A,n,T) is
L := 0
R := n-1
while L <= R do
m := floor(L + R)/2
if A[m] < T then
L := m+1
else if A[m] > T then
R := m-1
else 
return m
return unsucessfull

Binary Search Tree olma condition'ı left subtree'deki her element root node'dan kücük
right subtree'deki her element root node'dan büyük
sub'ların sub'ı alındıgında da bu condition devam etmeli


search-recursive pseudecode(key, node)
if node is NULL
   return EMPTY _TREE
if key < node.key
   return search -> recursive (key, node.left)
else if key > node.key
   return search -> recursive(key,node.right)
else 
   return node
------------------------------------------------
searchIterative(key,node)
  currentNode := node
  while currentNode is not NULL
        if currentNode.key = key
          return currentNode
        else if currentNode.key > key
           currentNode := currentNode.left
         else 
            currentNode := currentNode.right
------------------------------------------------

BinaryNode *findMax(BinaryNode *t) const 
{
    if(t != NULL)
       while(t -> right != NULL)
             t = t->right;
        return t;     
}
-------------------------------------------------

void remove(const Comparable & x, BinaryNode* & t)
{
    if(t == nullptr)
       return ; // item not found/do nothing 

    if(x < t->element)   
       remove(x, t->left)
    else if (t->element > x)
       remove(x, t->right)
          

}



*/

int main()
{
    return 0;
}