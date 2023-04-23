#include <iostream>
using namespace std;

void heapify(int arr[], int i, int N)
{
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

        if(largest < N && arr[left] > arr[largest])
            largest = left;
        if(right < N && arr[right] > arr[largest])
            largest = right;
        if(largest != i)
            swap(arr[i], arr[largest]);

            heapify(arr, N, largest);          
        
}

void buildHeap(int arr[], int N)
{
    
}