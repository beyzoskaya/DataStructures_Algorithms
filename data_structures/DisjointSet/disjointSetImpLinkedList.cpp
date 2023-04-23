
#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct Item;

// to represent set of Linked list 
// Every node has a pointer to representative
struct Node
{
    int value;
    Node *next;
    Item *itemPtr;

};

// A list has a pointer to head and tail
struct Item 
{
    Node *head;
    Node *tail;
};

// to represent Union Set
class ListSet
{
    private:

    // Hash to store addresses of set representatives
    // for given values. It is made global for ease of
    // implementation. And second part of hash is actually
    // address of Nodes. We typecast addresses to long
    // before storing them.
        unordered_map<int,Node*> nodeAddress;
    public:
        void makeSet(int a);
        Item* find (int key);
        void Union(Item* i1, Item* i2);
};

// To make a set with one object
// with its representative
void ListSet::makeSet(int a)
{
    // Create a new Set
    Item *newSet = new Item;

    // Create a new linked list node
    // to store given key
    newSet->head = new Node;
    
    // Initialize head and tail
    newSet->tail = newSet->head;
    nodeAddress[a] = newSet->head;

    newSet->head->value = a;
    newSet->head->itemPtr = newSet;
    newSet->head->next = NULL;
}

void ListSet::find(int key)
{
    Node* ptr = nodeAddress[key];
    return (ptr->itemPtr);
}

// union function for joining two subsets
// of a universe. Merges set2 into set1
// and deletes set1.
void ListSet::Union(Item* set1, Item* set2)
{
    Node* current = set2->head;
    while(current ! = 0){
        current->itemPtr = set1;
        current = current->next;
    }

    (set1->tail)->next = set2->head;
    set1->tail = set2->tail;
}

int main()
{
    ListSet a;
    a.makeset(13); //a new set is made with one object only
    a.makeset(25);
    a.makeset(45);
    a.makeset(65);
 
    cout << "find(13): " << a.find(13) << endl;
    cout << "find(25): "
        << a.find(25) << endl;
    cout << "find(65): "
        << a.find(65) << endl;
    cout << "find(45): "
        << a.find(45) << endl << endl;
    cout << "Union(find(65), find(45)) \n";
 
    a.Union(a.find(65), a.find(45));
 
    cout << "find(65]): "
        << a.find(65) << endl;
    cout << "find(45]): "
        << a.find(45) << endl;
    return 0;
}
