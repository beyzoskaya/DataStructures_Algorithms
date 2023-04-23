#include <iostream>
using namespace std;

void heapify(int arr[], int N, int i)
{
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < N && arr[left] > arr[largest])
        largest = left;
    if(right < N && arr[right] > arr[largest])
        largest = right;

    if(largest ! = i){
        swap(arr[i], arr[largest]);
    }        

    heapify(arr, N, largest);
}

void heapSort(int arr[], int N)
{
    for(int i = N/2 -1 ; i >=0; i--)
        heapify(arr,N, largest);

        for (int i = N - 1; i > 0; i--) {
 
        // Move current root to end
        swap(arr[0], arr[i]);
 
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}