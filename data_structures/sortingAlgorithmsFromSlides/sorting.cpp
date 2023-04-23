/*
External sorting -> if sorting must be done on disk due to the size of the input
input data is often stored in array -> allows random access
list -> only sequential access

Recursion: merge sort is a recursive algorithm
Stability: maintain the relative order of records with equal keys(values)
Serial/Parallel: concentrates upon serial algorithms
Adaptability: wheter or not the presortedness of the input affects the running time -> take into account are known as adaptive
In-place: needs only O(1) memory beyond the items being sorted 
sometimes O(logn) additional memory is considered "in-place"

several simple algorithms running in O(N^2) -> insertion sort / bubble sort / selection sort

sligthly more complicated algorithms running in O(NlogN)

Insertion Sort
--------------
At each step, the element at position p is placed in its correct place among positions 0 to p
keep the element in temp variable 
shif all the larger elements one spot to the right 

Original array
34 8 64 51 32 21
8 34 64 51 32 21
8 34 64 51 32 21
8 34 51 64 32 21
8 32 34 51 64 21
8 21 32 34 51 64

her iteration icin elemanı dogru yere koyuyor
yani her iterasyonda bütün array'i taramıs oluyor 

bir eleman icin kontrol yaptıgımız her bir iterasyonda o elemana kadar olan elemanlar ile kıyaslama yapılıp dogru yere konuyor

template<typename Comparable>
void insertionSort(vector<Comparable> & a){
    int j;

    for(int p = 1; p < a.size() ; p++){

            Comparable temp = a[p];
            for( j = p; j > 0 && temp < a[j-1]; j--)
                a[j] = a[j-1];
                a[j] = temp;
    }
}


a sorted array has no inversions
each swap of adjacent elements removes one inversion
running time of insertion sort O(I + N) -> I is the number of necessary inversions
I is N(N-1)/4 on average 



Shell Sort
----------
in-place comparison sort -> not require extra auxilary space
different implementation of insertion sort ot bubble sort
this algorithm avoids large shifts 
exchange of far (gap/interval)
more efficient compared to Insertion/Bubble Sort when
1-smaller value elements towards the end of the list
2-large sized list
3- efficiency depends on how we select the gap

Time Complexity:
Best case -> O(nlogn)
worst case -> o(n^2)
average case -> o(nlogn^2)

Space Complexity:
Auxilary space O(1) -> no extra space is required!

Step-1 : Take input array & size of array as n
Step-2 : Initialize the value of gap (iteratively)
Step-3 : Compare 2 elements at the distance of gap at every iteration

Pass 1
int array[9] --> gap = n/2 -> 9/2 = 4.5 -> 4
Pass 2
gap = gap / 2 -> 2
Pass 3
gap = gap / 2 -> 1
Pass 4
gap = gap / 2 -> 0.5 -> 0 Stop gapping 
! Gap needs to be greater than 0 for contionue the passes


Pseudocode for Shell Sort
ShellSort(arr,n){
    1. Loop:
    for(gap = n/2; gap>0; gap /= 2)
}
    1.1 Loop:
    for(int j = gap; j <n; j +=1){
     1.1.1 temp = arr[j]
     1.1.2 i=0
     1.1.2.1 Loop:
     for(i=j; i>=gap && arr[i-gap] > temp; i -= gap){
        1.1.2.1.1 arr[i] = arr[i-gap]
     }   
    }


Compares elements at distant 

Original
              81 94 11 96 12 35 17 95 28 58 41 75 15 
after 5-sort  

shellsort applies insertion sort in hk independent subarrays at each phase
asymptotic complexity of shellsort depends on the choice of increment sequence


Selection Sort
--------------
*/
