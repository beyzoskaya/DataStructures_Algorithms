/*
recursive algorithm
merging two sorted lists at each step

External Merge Sort:
for sorting 900 GB of data using only 100 GB of RAM

• 1- Read 100 GB of the data in main memory and
sort by some conventional method.
• 2- Write the sorted data to disk.
• 3- Repeat steps 1 and 2 until all the data is in sorted
100 GB chunks (there are 900 GB/100 GB = 9
chunks).

divide and conquer algorithm -> high level of efficiency
it divides input array in two halves -> calls itself for the two halves(recursively) 
and then merge as the two sorted halves
separate merge() function is used for merging two halves 
Time Complexity of O(nlogn)

one of the most efficient sorting algorithms

Working
-------

mergeSort(arr[], left,right){
    Step-1 Find the middle point to divide the array into two halves:
    middle m = (left + right) / 2
    Step-2 Call mergeSort for first half:
    mergeSort(arr[], left,m)
    Step-3 Call mergeSort for second half:
    mergeSort(arr,m + 1, right)
    Step-4 Merge the two halves sorted in step 2 and 3
    merge(arr,left,middle,right) 
}
*/

#include <iostream>
using namespace std;

// merge function
void merge(int arr[], int l,int m,int r)
{
    int i = l; // starting index for left subarray
    int j = m + 1; // starting index for right subarray
    int k = l; // starting index for temporary  array

    int temp[5];

    // first is for left subarray control + second one is for right subarray
    while(i <= m && j <= r)
    {
        if(arr[i] <= arr[j])
        {
            temp[k] = arr[i]; // arr[i] smaller than arr[j] 
            i++; // incremented the index for left subarray 
            k++; // for where to locate next element in temporary array -> shift one position

        }else { // arr[j] < arr[i]
        temp[k] = arr[j];
        j++;
        k++;
    }
}
    while(i <= m) // copying all elements from left subarray to temp as it is
    {
        temp[k] = arr[i];
        i++;
        k++;
    }
    while(j <= r) // copying all elements from right subarray to temp as it is
    {
        temp[k] = arr[j];
        j++;
        k++;
    }
    for(int s=l; s < r; s++)
    {
        arr[s] = temp[s];
    }    
}
// merge sort function
void mergeSort(int arr[], int left, int right)
{
    if(left<right)
    {
        int middle = (left + right) / 2;
        mergeSort(arr,left,middle); 
        mergeSort(arr,middle+1,right);
        merge(arr,left,middle,right); 
    }
}

int main()
{
    //int arr[5] = {4,6,1,2,7 }
      int myarr[5];
      for(int i=0; i<5; i++)
      { 
            cin >> myarr[i];
      }
      cout << "Before Merge Sort: " <<endl;
      for(int i=0; i<5; i++)
      {
        cout << myarr[i] <<" ";
      }

      // merge sort  function calling 
      mergeSort(myarr,0,4);

      cout << "After Merge Sort: " <<endl;
      for(int i=0; i<5; i++)
      {
        cout << myarr[i] <<" ";
      }

   return 0;
}