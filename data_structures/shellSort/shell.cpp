#include <iostream>
using namespace std;

/*
template<typename Comparable>
void shellSort(vector<Comparable> & a)
{
    for(int gap = a.size()/ 2; gap > 0; gap /= 2)
        for(int i = gap; i < a.size(); i++)
        {
            Comparable temp = a[i];
            int j = i;

            for(; j >= gap && temp < a[j-gap]; j -= gap)
                a[j] = a[j-gap];
                a[j] = temp;
        }
}
*/

/*
variation of insertion sort
idea of ShellSort is to allow the exchange of far items

Pseudecode:
Initialize the value of gap size ---> h
Divide the list into smaller sub-part. Each must have equal intervals to h
Sort these sub-lists using insertion sort
*/

int shellSort(int arr[], int n)
{
    for(int gap = n/2; gap > 0; gap /=2)
    {
        for(int i = gap; i < n; i += 1)
        {
            int temp = arr[i];

            for(int j = i; j >= gap && arr[j-gap] > temp; j -= gap)
                arr[j] = arr[j-gap];

                arr[j] = temp;
        }
    }
    return 0;
}