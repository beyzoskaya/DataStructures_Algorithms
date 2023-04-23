/*

Sorting in linear time?
Can be possible in some special cases?

Counting sort is an algorithm that sorts the elements of an array 
by counting the number of occurrences of each unique element in the array

It is not a comparison sort 
Insertion 
Selection
Bubble
Merge
Quick
bunlar mesela comparison sort algorithms
 
n -> number of elements in the array / k -> range of input
Time Complexity: O(n+k)
Space Complexity: O(n+k)

int arr[7] = {1, 4, 1, 2, 7, 5, 2}
range -> 0-9
            0 1 2 3 4 5 6 7 8 9 
input array:1 4 1 2 7 5 2 

count array:0 0 0 0 0 0 0
count array:0 1 0 0 0 0 0
count array:0 1 0 0 1 0 0 
count array:0 2 0 0 1 0 0
count array:0 2 1 0 1 0 0
count array:0 2 2 0 1 1 0 1 0 0  
count array:0 2 4 4 5 6 6 7 7 7  // cumulative olarak indexleri topla!

Pseudocode:
CountingSort()
{
1- take input_array[size]
2-create output_array[size]
3-take range (or number of unique elements)

4-for(int i = 0 to i < range)
    4.1-count_array[i] = 0 -> initializing all the values to zero
5-for(int i = 0 to i < size)    
    ++count_array[input_array[i]] --> count each element then put it in count_array
6-for(int i=0 to i<range)
    count_array[i] = count_array[i] + count_array[i-1] --> cumulative counting owing to the previous elements in the range array
7-for(int i=0 to i< size)
  
}
*/

/*
Comparison of different sorting algorithms
Insertion Sort -> O(n^2)
Shell Sort -> O(n^(7/6))
Heap Sort -> O(nlogn)
Quick Sort -> O(nlogn)



*/