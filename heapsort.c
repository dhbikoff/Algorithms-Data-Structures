#include "heapsort.h"
#include "swap.h"

void heapsink(int arr[], int k, int N)
{
  while(2 * k <= N) {
    int j = 2 * k;
    if (j < N && arr[j] < arr[j+1]) j++;
    if(arr[k] >= arr[j]) break;
    swap(arr, k, j);
    k = j;
  }
}

void hsort(int arr[], int len) 
{
  for(int k = len/2; k >= 1; k--) {
    heapsink(arr, k, len);
  }
  while(len > 0) {
    swap(arr, 0, len--);
    heapsink(arr, 0, len);
  }
}

