/*
height of a complete binary tree is ---> O(logn)

Heap is a binary tree that is completely filled
complete binary tree

height of a complete binary tree --> O(logn)

minHeap --> smallest element in the root
findMin --> constant time

ARRAY IMPLEMENTATION OF BINARY HEAP

for any element at position i
left child is at 2i
right child is at 2i+1
parent is at i/2


inserting new element into the bottom of the tree ---> percolate up operation 
efficiency O(logn)

Implementation of Insert
------------------------
void insert(const Comparable & x){
    if(currentSize == array.size()-1)
       array.resize(array.size() * 2);

       // Percolate up ---> hole is the index where the percolate begins
    int hole = ++currentSize;
    for(; hole > 1 && x < array[hole/2]; hole/=2)
         array[hole] = array[hole/2];
         array[hole] = x;   
}


inserting ---> percolate up 
delete --> percolate up

decrease key ---> percolate up 
increase key ---> percolate down


Building Heap
-------------
place the N items into the tree in any order (maintaining the structure prop.)
use percolate down
*/

/*
Binary Heap is a Binary Tree with following properties:
1- complete binary tree 
2- binary heap is either Min or Max heap
*/

#include <iostream>
#include <climits>
using namespace std;

void swap(int *x, int *y);

class minHeap{
    int *heapArray; // pointer to array of elements in heap
    int capacity;  // max possible size of min heap
    int heap_size; // current number of elements in min heap

    public:
    // constructor
    minHeap(int capacity);
    void minHeapify(int);
    int parent(int i){return (i-1)/2; }
    int left (int i){return (2*i+1);}
    int right(int i){2*i+2;}
    int extractMin();
    void decreaseKey(int i, int new_value);
    int getMin(){heapArray[0];} 
    void deleteKey(int i);
    void insertKey(int data);
};

//constructor 
minHeap::minHeap(int capacity){
    heap_size = 0;
    capacity = capacity;
    heapArray = new int[capacity];
}

// insert a new key 'data'
void minHeap::insertKey(int data){
      if(heap_size == capacity){
        cout << "\nOverflow: Could not insertKey\n";
        return; 
      }

      heap_size = heap_size +1; // first insert the new key to the end
      heapArray[heap_size -1] = data;

      // fix the min heap property if it is violated
      while(heap_size -1 != 0 && heapArray[parent(i)] > heapArray[i]){
        swap(&heapArray[i], &heapArray[parent(i)]);
        i = parent(i);
      }
}

void minHeap :: decreaseKey(int i, int new_val){
    heapArray[i] = new_val;
    while(i != 0 && heapArray[parent(i)] > heapArray[i]){
        swap(&heapArray[i], &heapArray[parent(i)]);
        i = parent(i);
    }
}

// method to remove minimum element
int minHeap::extractMin(){
    if(heap_size <= 0)
       return INT_MAX;
    if(heap_size == 1)   
        heap_size = heap_size -1;
        return heapArray[0];

        int root = heapArray[0];
        heapArray[0] = heapArray[heap_size-1];
        heap_size = heap_size -1;
        minHeapify(0);

        return root;
}

// Binomial queues derse eger 2^k seklinde forestler olusturarak implement ediyoruz
// priority queue'den farkı bu
// for example 13 is represented with b3 b2 b0 --> 2^3 + 2^2 + 2^0 = 13

// Implementation of Merging Binomial Queue
/*
BinomialNode * combineTrees(BinomiaLNode *t1, BinomialNode *t2){
    if(t2-> element < t1-> element){
       return combineTrees(t2,t1);
    }
    t2->nextSibling = t1->leftChild;
    t1->leftChild = t2;
    return t1;
}


minimum element can be found by scanning the roots of all the trees
there are at most logN different trees ---> minimum can be found in O(logn) time
for efficiency --> need to sorted way about heights

binomial heap is a collection of binomial trees
binomial tree has exactly 2^k nodes
it has depth as k
(each binomial tree follows min heap prop.)
union operation is combine two Binomial Heaps into one

*/
