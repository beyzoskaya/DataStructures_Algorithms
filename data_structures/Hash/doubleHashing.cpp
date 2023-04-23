#include <iostream>
#include <vector>
#include <bitset>
using namespace std;
#define MAX_SIZE 10000001ll

class doubleHash
{
    int TABLE_SIZE;
    int keyPresent;
    int PRIME;
    vector<int> hashTable;
    bitset<MAX_SIZE> isPrime;

    void __setSieve(){
        isPrime[0] = isPrime[1] = 1;
        for(long long i = 2; i*i <= MAX_SIZE; i++)
            if(isPrime[i] == 0)
                for(long long j = i*i; j <= MAX_SIZE; j += i)
                    isPrime[j] = 1;
 
    }

    int inline hash1(int value)
    {
        return value % TABLE_SIZE;
    }

    int inline hash2(int value)
    {
        return PRIME - (value % PRIME);
    }

    bool inline isFull()
    {
        return (TABLE_SIZE == keyPresent);
    }
}


