#include "selectionsort.h"
#include "swap.h"

void ssort(int arr[], int len) 
{
  for (int i = 0; i < len-1; i++) {
    int minIndex = i;
    for (int j = i+1; j < len; j++) {
      if (arr[minIndex] > arr[j])
        minIndex = j; 
    }
    if (i != minIndex) {
      swap(arr, i, minIndex);
    }
  }
}


