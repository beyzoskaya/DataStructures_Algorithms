/*
compare adjacent elements and swap them if they are in the wrong order
suitable for small data sets
Time comp -> O(N^2)

Working:
Step 1 -> starting from the first element (index = 0)compare the current element with the next element of the array
Step 2 -> ıf the current element is greater than the next element of the array,swap them 
Step 3 -> ıf the current element is less than the next element, move to the next element
Step 4 -> Repeat Step 1 till the list sorted


a: array of items
n: size of list

start
1- declare variables
2- loop:(i=0 to i <n ) // outer loop
  2.1-loop:(j=0 to j < n -i-1) // inner loop
    2.1.1 if(a[j] > a[j+1]) then
       2.1.1.1 swap(a[j], a[j+1])

       No 9 shifted to the end 
       9 7 3 6 2
       7 9 3 6 2
       7 3 9 6 2
       7 3 6 9 2
       7 3 6 2 9

       largest element ilk inner loop'un tamamlanmasıyla en sona gittigi icin outer loopta artık bir tane element az kontrol edicez mesela

       No 7 shifted to the end
        3 7 6 2 9
        3 6 7 2 9
        3 6 2 7 9
*/

#include <iostream>
using namespace std;

void bubbleSort(int a[]){
    for(int i=0; i<5; i++)
    {
        for(int j=0; j< (5-i-1); j++)
        {
            if(a[j] > a[j+1])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                
            }
        }
    }
}

int main(){
    int myarray[5];
    int size;
    cout << "Enter 5 integers in any order: " <<endl;
    for(int i=0; i<5; i++){
        cin >> myarray[i];
    }
    cout << "Before sorting: " <<endl;
    for(int i=0; i<5; i++){
        cout << myarray[i] << " ";
    }

    bubbleSort(myarray); // sorting

    cout << "After sorting: " <<endl;
    for(int i=0; i<5; i++){
        cout << myarray[i] << " ";
    } 

    return 0;
}