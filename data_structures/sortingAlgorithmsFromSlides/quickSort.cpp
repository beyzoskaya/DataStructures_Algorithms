/*
Fastest known generic sorting algorithm
O(NlogN) average running time
O(N^2) worst case running time ---> very low probability

Quick sort icin pivot selection var 
pivot sectikten sonra parititioning yapıyoruz 
sonra partition yaptıgımız icin recursive call yapıp sürekli sub parcalara ayırıyoruz

Selecting the pivot:
- first element 
- random element -> might be expensive to calculate
- median (n/2'th largest number) -> best choice but hard to calculate 

* divide and conquer algorithm
* it picks an element as a pivot and partitions the given array around the picked pivot
* there are many different versions of quikSort that pick pivot in different ways
        1- Always pick first element as pivot
        2- Always pick last element as pivot 
        3- Pick a random element as pivot
         
Quick sort is considered as in in-place sorting algorithm -> 
it reduces the space complexity and removes the use of the auxilary array 

in-place algorithm -> a sort algorithm in which the sorted items occupy the same storage as the original ones 
this is usually achieved by swapping ,shuffling etc of elements in the same array/list

bubble sort/ selection sort / insertion sort is also in-sort algorithms
mesela merge sort'ta her bir subarray sortlandıktan sonra merge'lemek icin temp bir array tutuyoruz 
bu temp array auxilary bir space kaplıyor extra -> some extra memory utilize

Time Complexity: O(nlogn)
Space Complexity: O(logn)

7 9 3 2 6 -> last element as a pivot
greater than 6 elements to the right of 6
smaller than 6 elements to the left of 6
pivot element'i middle element yaptıktan sonra subarrayler tekrar quick sortlanıyor
3 2 6 7 9
3 2       6       7 9 


Working
QuickSort(arr[], start_index,end_index){
    Step-1 Find parititon index (till start index < end index)
            p = Partition(arr[],start_index, end_index)
    Step-2 Call Quick sort for first half
            QuickSort(arr[], start_index, p-1)
    Step-3 Call Quick Sort for second half 
            QuickSort(arr[], p+1, end_index)                
}

pivot sectigimiz seye göre degisiyo mesela pivot = arr[end] -> en sondaki elemanın pivot secildigi durumlar icin 
*/

/*
Pseudecode
QuickSort(arr[], starting_index, ending_index)
{
    if(starting_index < ending_index){
        p = Partititon(arr[], starting_index,ending_index)
        QuickSort(arr[], starting_index, (p-1))
        QuickSort(arr[], (p+1), ending_index)
    }
}

Partition(arr[], s,e)
{
    pivot = arr[e]
    pivotIndex = s
    for(i=s to e-1)
    {
        if(arr[i] < pivot)
        {
            swap(arr[i], arr[pivotIndex])
            pivotIndex++;
        }
    }
            swap(arr[e], arr[pivotIndex])
            return pivotIndex
}


*/


#include <iostream>
using namespace std;

int Partition(int arr[], int s, int e)
{
    int pivot = arr[e];
    int pIndex = s;

    for(int i=s; i<= e-1; i++)
    {
        if(arr[i] < pivot)
        {
            // this is for swapping !!
            int temp = arr[i];
            arr[i] = arr[pIndex];
            arr[pIndex] = temp;
            // after swapping, we need to get the shifted index for other iteration
            pIndex = pIndex + 1;
        }
    }

    int temp = arr[e];
    arr[e] = arr[pIndex];
    arr[pIndex] = temp;

    return pIndex; // that what we are going to want to do partition!
                   // apply quick sort on the left of and right of the index (recursively)
}

void QuickSort(int arr[], int s, int e)
{
    if(s < e) // continue up to more than one array in the subarray
    {
        int p = Partition(int arr, s, e); // bu p'yi partition index olarak kullanacagız!
                                          // recursive bi sekilde quicksort cagırmamız gerektigi icin her itersyonda partition icin index degisiyor!
        QuickSort(arr,s,(p-1));           // Recursive QuickSort call for left subarray
        QuickSort(arr,(p+1),e);           // Recursive QuickSort call for right  subarray  

    }
}



int main()
{

    int size = 0;
    cout <<"Enter Size of array: "<<endl;
    cin >> size;
    int myarr[size];

    cout << "Enter" <<size << "integers in any order: " <<endl;
    for(int i=0; i<size; i++)
    {
        cin >>myarr[i];
    }

    cout <<"Before Sorting: "<<endl;
    for(int i=0; i<size; i++)
    {
        cout <<myarr[i]<<" ";
    } 
    cout<<endl;
    QuickSort(myarr,0,(size-1));

    cout <<"After Sorting: "<<endl;
    for(int i=0; i<size; i++)
    {
        cout <<myarr[i]<<" ";
    } 

    return 0;
}

/*
IntroSort:
• Start with Quicksort
• If the recursion depth gets too big, switch to
heapsort, which is O(n log n) 

Dual Pivot QuickSort:
• Instead of one pivot, pick two pivots
• Instead of partitioning the array into two pieces,
partition it into three pieces 

*/