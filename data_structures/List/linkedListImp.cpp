#include <iostream>
using namespace std;

class Node
{
    public:
        Node(const Object&);
        Object data
        Node* next;
};

class LinkedList
{
    public:
        LinkedList();
        Node *find(int);
        Node *findkth(int);
        void insert(Node*, int);
        void remove(Node*);
        void printList();
        ~LinkedList();

    private:
        Node* head;    
};

// printing the list cost of ---> O(N)
void LinkedList::printList()
{
    Node *n = head;
    while(n != 0)
    {
        cout << n->data;
        n = n->next;
    }
}

// removing the element from a linkedList ---> O(1)
void LinkedList::remove(Node* current)
{
    Node *deletedNode = current->next;
    current->next = deletedNode->next;
    delete deletedNode;
}

// inserting an element ----> O(1)
void LinkedList::insert(Node* current, int put)
{
   Node *newNode = new Node(put);
   newNode->next = current->next;
   current->next = newNode;
}

void LinkedList::~LinkedList()
{
    Node *dNode = head;

    while(dNode != 0){
       head = head->next;
       delete dNode;
       dNode = head;
    }
}

/*
List implementation'ında random access olmuyor ama 
linked list implementasyonunda insert ve remove operasyonları constant time
linked list reprenst edilirken pointer kullanarak yanındaki elemente bagladımız icin extra memory usage

Linked list ile bir seyi implement etmek istersek
head'i olmalı ve next pointer'ı olmalı
*/

/*
for insertion in linked list --->
we need to traverse until we get the NULL node is found
create a new node and
connect the last node with new node
*/

/*
deletion icin base caseler var
eger linked list'in head'i siliniyorsa 
öncelikle bir temp variable'ında head'i tutmamız gerek
head = head -> next yapılmalı
sonra delete temp

baska bir casede delete ettikten sonra bir önceki node'u silinen node'un nextine bagla
*/