#include <iostream>
using namespace std;

/*
simple insertion sort

template<typename Comparable>
void insertionSort(vector<Comparable> & a)
{
    int j;
    for(int p = 1; p < a.size(); p++)
    {
        Comparable temp = a[p];
            for(j = p; j > 0 && temp < a[j-1]; j--)
                a[j] = a[j-1];
                a[j] = temp;
    }
}
*/

void insertionSort(int arr[], int n)
{
    int i;
    int j;
    int key;
    for(i = 0; i < n; i++)
        key = arr[i];
        j = i-1;

        while(j >=0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
}

void printArray(int arr[], int n)
{
    int i;
    for(i = 0; i < n; i++)
        cout << arr[i] << " ";
        cout << endl;
}

int main()
{
    int arr[] = { 12, 11, 13, 5, 6 };
    int N = sizeof(arr) / sizeof(arr[0]);
 
    insertionSort(arr, N);
    printArray(arr, N);
 
    return 0;
}