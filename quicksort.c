#include "knuthshuffle.h"
#include "quicksort.h"
#include "swap.h"

int partition(int arr[], int len, int lo, int hi) 
{
  int i = lo;
  int j = hi+1;
  int v = arr[lo];

  for(;;) {
    while(arr[++i] < v)
      if (i == hi) break;
    while(v < arr[--j])
      if (j == lo) break;
    if (i >= j) break;
    swap(arr, i, j);
  }
  swap(arr, lo, j);
  return j;
}

void qusortHelper(int arr[], int len, int lo, int hi)
{
  if (hi <= lo) return;
  int j = partition(arr, len, lo, hi);
  qusortHelper(arr, len, lo, j-1);
  qusortHelper(arr, len, j+1, hi);
}

void qusort(int arr[], int len) 
{
  kshuffle(arr, len);
  qusortHelper(arr, len, 0, len-1);
}

