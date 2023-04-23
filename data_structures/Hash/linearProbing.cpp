#include <iostream>
using namespace std;

template<typename K, typename V>
class HashNode
{
    public:
        V value;
        K key;

        HashNode(K key, V value)
        {
            this->value = value;
            this->key = key;
        }
};

template<typename K, typename V>
class HashMap
{
    HashNode<K,V>** arr;
    int capacity;
    int size;
    HashNode<K,V>* dummy;

    public:
        HashMap()
        {
            capacity = 20;
            size = 0;
            arr = new HashNode<K,V>*[capacity];

            for(int i =0; i< capacity; i++){
                arr[i] == NULL;
            }

            dummy = new HashNode<K,V>(-1,-1); 
        }

        int hashCode(K key)
        {
            return key % capacity;
        }

        void insert(V value, K key)
        {
            HashNode<K,V>* temp = new HashNode<K,V>(key,value);
            int hashIndex = hashCode(key);

            while (arr[hashIndex] != NULL
               && arr[hashIndex]->key != key
               && arr[hashIndex]->key != -1) {
            hashIndex++;
            hashIndex %= capacity;
        }
 
        // if new node to be inserted
        // increase the current size
        if (arr[hashIndex] == NULL
            || arr[hashIndex]->key == -1)
            size++;
        arr[hashIndex] = temp;
    }

        }
}