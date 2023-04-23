/*
simple algorithm

7 5 4 2 -> choose the smallest one from entire array then sub it 
7 5 4 2 -> 2   5 4 7 
           2 4   5 7
           2 4 5   7
           2 4 5 7 
*/

/*
Pseudecode
for(i = 0; i < n-1; i++)
set current element as minimum
min = i
check the element to be minimum

for(j=i+1; j<n; j++)
    if(arr[j] < arr[min]) then
           min = j;
           end if
        end for

        if(min != i) then
           swap arr[min] and arr[i]
           end if
        end for      
*/

#include <iostream>
using namespace std;

void selectionSort(int arr[]){

    for(int i=0; i<4; i++){
        int min = i; 
        for(int j = i+1; j<5; j++){ // actual comparison happening
           if(arr[j] < arr[min]){
            min = j;
           }
        }
        if(min != i){
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
}

int main(){
    int myarr[5];
    cout << "Enter 5 integers in random order: " <<endl;
    for(int i=0; i<5; i++){
        cin >> myarr[i];
    }

   

     cout << "Unsorted Array: " <<endl;
    for(int i=0; i<5; i++){
        cout << myarr[i]<< " ";
    }
    cout <<endl;
    selectionSort(myarr); // sorting is actually happening
    cout << "Sorted Array: " <<endl;
    for(int i=0; i<5; i++){
        cout << myarr[i]<< " ";
    }
    cout <<endl;

     return 0;
}