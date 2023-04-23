#include <iostream>
using namespace std;

int getMax(int arr[], int n){
    int max = arr[0];
    for(int i =0; i < n; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }

    return max;
}

void countSort(int arr[], int n, int exp){

    int output[n]; // output array
    int i; 
    int count[10] = {0};

    for(i =0; i <n ; i++)
       count[(arr[i]/ exp) % 10]++;

       for(i = 1; i<10; i++)
           count[i] += count[i-1];

        for(i=n-1; i >=0; i--){
            output[count[(arr[i]/exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }   

        for(i=0; i < n; i++)
           arr[i] = output[i];
}

/*
Radix Sort is lower bound for the Comparison based sorting algorithm (Merge/Heap/Quick...)
they cannot do better than nLogn 

Counting Sorting is a linear time sorting algorithm that sort in O(n + k) time 
when elements are in the range form 1 to k ---> WHAT IF THE ELEMENTS ARE IN THE RANGE FORM 1 TO N^2

We cannot use Counting Sorting because will take O(N^2) which is worse than comparison-based sorting algorithms

Starting from least significant digit to most significant digit. ---> Radix sort uses counting sort as a subroutine to sort
Radix sort is not an in-place algorithm as it uses a temporary count array

*/

void radixSort(int arr[], int n){
    int m = getMax(arr,n);

    for(int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr,n,exp);
}

void print(int arr[], int n){
    for(int i=0; i < n ;i++)
        cout << arr[i] << " ";
        cout << endl;
}

int main()
{
    int arr[] = { 170, 45, 75, 90, 802, 24, 2, 66 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
      
      // Function Call 
      radixsort(arr, n); 
    print(arr, n); 
    return 0; 
}