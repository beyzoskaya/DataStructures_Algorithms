/*
insert remove find operations --> constant time
no support for findMin/findMax/sorting operations

hash table --> array of size n
each key --> mapped into an index between 0 and n-1 (mapping is called hash function)

Perfect Hash Function: 
maps each search key into a unique location
one-to-one not necessarily onto

Collisions:
Occur when the hash function maps more than one item into same array location

Hash function should be easy and fast to compute 

possible strategy is moduler arithmetic
hash function = key % table_size
base should be prime


Using an array 
search takes linear time 
if stored in sorted order --> search can be done in O(logn)

Using a Linked list
search takes linear time 

Using Balanced BST 
insertion take O(logn)
search take O(logn)
deletion take O(logn)


Separate Chaining ---> Collision Resolving Tech.

a Simple Hash Function:
int hash(const string & key, int tableSize){
    int hashValue = 0;

    for(int i=0; i < key.length(); i++)
        hashValue += key[i];

        return hashValue % tableSize;
}

Not always a very good idea,
if table size is large then keys are not distributed evenly


A good hash function:
int hash(const string & key, int tableSize){
    int hashValue = 0;

    for(int i=0; i<key.length(); i++)
      hashValue = 37 * hashValue + key[i];

      hashValue %= tableSize;

      if(hashValue < 0){
        hashValue += tableSize;

        return hashValue;
      } 
}


--> Three basic strategies to manage collisions:
1- Separate Chaining
2- Open Addressing(probing)
3- Double hashing

Separate Chaining: Keep a list of elements that hash to the same value --> with a linked list
any ADT can be used instead of linked list 
List --> O(n) --> n is the number of elements in the particular chain
Binary Search Tree --> O(logn)

Average length of a list is load factor 
load factor = number of elements / hash table size 
finding an element has two component:
1- hashing and finding the list: O(1)
2- traversing the list and finding the element: O(load factor)
effiency depends on the load factor not the size of the hash table
if load factor exceeds 1, restructure and extend the size of the hash table --> REHASING


Probing
-------
Linear probing: modunu aldıktan sonra eğer collision olursa bos olana kadar bir tane atlayarak ilerliyor

Primary Clustering
------------------
primary clustering increases probing time and decreases effiency

Cost of Insertion and Search
----------------------------
depends on expected number of probes
expected number of probes --> 1/(1-load factor)
cost of insertion = cost of unsuccessful search

*linear probing is a bad idea if the table is expected to be more than half full

Quadratic probing
-----------------
searching with increments of 1^2, 2^2,3^2...
f(i) = i^2

half empt + table size must be prime

prime of the form 4k+3 f(i) = i^2 ---> entire table can be probed 

Double Hashing
-------------
uses two hash functions

iki tane fonksiyon var modüler aritmetik uygulamak icin 
eger ilk mod aldıgımız functiondan gelen sonucun oldugu kutu doluysa bu mod sonucunu ikinci fonksiyonla topluyoruz
toplam eger table size'dan büyük cıkarsa da table size'ı cıkarıyoruz
geriye kalan sayı koymamız gereken yer oluyor 

ikinci fonksiyon için öndeki sayı prime olmalı



*/

// QUADRATIC PROBING (Open Addressing)
/*
If the slot hash(x) % S is full, then we try (hash(x) + 1*1) % S.
If (hash(x) + 1*1) % S is also full, then we try (hash(x) + 2*2) % S.
If (hash(x) + 2*2) % S is also full, then we try (hash(x) + 3*3) % S.
This process is repeated for all the values of i until an empty slot is found.
*/

#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

#define MAX_SIZE 10000001ll

void printArray(int array[], int n){

    for(int i=0; i<n; i++){
       cout << array[i] << " ";
    }
}

// Function to implement quadratic probing

void hashing(int table[], int tableSize, int array[], int N){

  // Iterating through the array
  for(int i =0; i<N; i++){
     // Computing the hash value

     int hashValue = array[i] % tableSize;

     // Insert in the table if there is no collision 
         if(table[hashValue] == -1)
             table[hashValue] = array[i];
         else{
          //if there is a collision
          // iterating through all possible quadratic values

          for(int j=0; j<tableSize; j++){
            // computing the new hash value
            int t = (hashValue + j * j) % tableSize;
                    if(table[t] == -1){
                        table[t] = array[i];
                        break;
                    }
              }
         }    
  }
  printArray(table,N);
}


// DOUBLE HASHING (Open Addressed Hash Tables)

/*
The advantage of Double hashing is that it is one of the best form of probing, producing a uniform distribution of records throughout a hash table.
This technique does not yield any clusters.
It is one of effective method for resolving collisions.
*/

/*
A good second Hash function is:
It must never evaluate zero
Must make sure that all cells can be probed
*/

class doubleHash {
  int TABLE_SIZE, keyPresent, PRIME;

  vector<int> hashTable;
  bitset<MAX_SIZE> isPrime;

}

/*
Rehasing is expensive --> O(N)
rehashing --> hashing again
load factor increase --> complexity increase 

*/

/*
Hashing is not efficient for
Traversal in sorted order 
Finding the largest and smallest value among keys
Range queries
*/

/*
Self balancing BTS ---> all operations guarantee to work in O(logn)
*/