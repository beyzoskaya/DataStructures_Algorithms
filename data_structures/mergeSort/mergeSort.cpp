#include <iostream>
using namespace std;

void merge(int array[], int const left, int const mid, int const right)
{
    auto const subArrayOne = mid -left + 1;
    auto const subArrayTwo = right - mid;

    auto *leftArray = new int[subArrayOne];
    auto *rightArray = new int[subArrayTwo];
    
}