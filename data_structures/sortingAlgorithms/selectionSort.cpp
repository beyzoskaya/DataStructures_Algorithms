#include <iostream>
using namespace std;

void swap(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

/*
Repeatedly finding the minimum element (considering ascending order)
from the unsorted part and putting it at the beggining

Two subarrays in a given array
- the subarray which is already sorted
- remaining subarray was unsorted

for example: 64,25,12,22,11

1- whole array is traversed 0 to 4
2- after traversing 11 is the minimum element 
3- replace 64 with 11
4- after swapped 11 and 64 array turned out
11 25 12 22 64
5- again traverse the array starting from 25 up tp 64
6- 12 is the smallest element 
7- swap 25 with 12 
8- after swapped 25 and 12 array turned out 
11 12 25 22 64
*/

/*
Pseudecode for SELECTION SORT 
--> initialize minimum value(min_idx) to location 0
--> traverse the array for finding the minimum one 
--> while traversing if any element appear that is smaller than min_idx, swap both of them
--> then increment the min_idx for jumping the next index 
--> repeat until the array is sorted 
*/

void selectionSort(int arr[], int n){
    int i,j,min_idx;

    // One by one move boundary of unsorted subarray
    for(int i = 0; i < n-1; i++){
       // Find the minimum element in unsorted array  
       min_idx = i;
       for(j = i+1; j < n ; j++)
           if(arr[j] < arr[min_idx]){
            min_idx = j;
           }

           // swap the found minimum element with the first element 
           swap(&arr[min_idx], &arr[i]);
    }
}

/*
Bubble sort is the simplest sorting algorithm 
not suitable for large data sets 

Bubble sort exmple : 5,1,4,2,8
1 5 4 2 8
1 4 5 2 8 
1 4 2 5 8
1 2 4 5 8
*/

void bubbleSort(int arr[], int n){
    int i, j;
    for(i=0; i<n-1; i++)
        for(j = 0; j< n-i-1; j++)
            if(arr[j] > arr[j+1])
               swap(&arr[j], &arr[j+1]);
}


/*
Insertion sort is efficient for small data values

example: 12 11 13 5 6
1- control first two elements
2- 11 < 12
3- swap 11 with 12
4- compare second and third element
5- 12 < 13
6- already in this form so no swapping
7- 5 < 13
8- swap 5 with 13
......


Pseudecode for Insertion Sort
To sort an array of size N in ascending order:
1- iterate from arr[1] to arr[N] over the array
2- compare the current element(key) to its predecessor
3- if the key element is smaller than its predecessor, compare it to the elements before
*/

void insertionSort(int arr[], int n){
    int i,key,j;
    for(int i = 1; i < n; i++){
        key = arr[i];
        j = i -1;

        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j+1] = key;
    }
}

/*
Shell sort is a variation of Insertion Sort 
The idea of ShellSort is to allow the exchange of far items
We make the array h-sorted for a large value of h
We keep reducing the value of h until it becomes 1

Pseudecode for Shell Sort
Initialize the value of gap size. Example: h
Divide the list into smaller sub-part. Each must have equal intervals to h
Sort these sub-lists using insertion sort 
Repeat this until the list is sorted
*/

int shellSort(int arr[], int n){

    for(int gap = n/2; gap > 0; gap /=2){
        for(int i = gap; i<n; i++){

            int temp = arr[i];

            int j;
            for(int j=i; j >= gap && arr[j-gap] > temp; j -= gap)
                arr[j] = arr[j-gap];

                arr[j] = temp;
        }
    }

    return 0;
}

void printArray(int arr[], int size){
    int i;
    for(int i =0; i < size ; i++)
        cout << arr[i] << " ";
        cout << endl;
}

int main(){
    int arr[] = {64, 25, 12, 22, 11};  
    int n = sizeof(arr)/sizeof(arr[0]);  
    selectionSort(arr, n);  
    cout << "Selection Sorted array: \n";  
    printArray(arr, n);  

    int arr2[] = {64, 34, 25, 12, 22, 11, 90};  
    n = sizeof(arr2)/sizeof(arr2[0]);  
    bubbleSort(arr2, n);  
    cout<<"Bubble Sorted array: \n";  
    printArray(arr2, n);  

    int arr3[] = { 12, 11, 13, 5, 6 };  
    n = sizeof(arr3) / sizeof(arr3[0]);  
    insertionSort(arr3, n);  
    cout<<"Insertion Sorted array: \n";  
    printArray(arr3, n); 

    int arr4[] = {12, 34, 54, 2, 3}; 
    n = sizeof(arr4)/sizeof(arr4[0]); 
    cout << "Array before sorting: \n"; 
    printArray(arr4, n); 
    shellSort(arr4, n); 
    cout << "Array after shell sorting: \n"; 
    printArray(arr4, n); 

    return 0; 
}