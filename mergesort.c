#include "mergesort.h"

void merge(int arr[], int aux[], int lo, int mid, int hi) 
{
  // copy arr to aux
  for (int i = 0; i <= hi; i++) {
    aux[i] = arr[i];
  }

  // merge back to arr
  int i = lo;
  int j = mid + 1;
  for (int k = lo; k <= hi; k++) {
    if (i > mid)              arr[k] = aux[j++];
    else if (j > hi)          arr[k] = aux[i++];
    else if (aux[j] < aux[i]) arr[k] = aux[j++];
    else                      arr[k] = aux[i++];
  }
}

void msortHelper(int arr[], int aux[], int lo, int hi)
{
  if (hi <= lo) return;
  int mid = lo + (hi-lo) / 2;
  msortHelper(arr, aux, lo, mid);
  msortHelper(arr, aux, mid+1, hi);
  merge(arr, aux, lo, mid, hi);
}

void msort(int arr[], int len) 
{
  int aux[len];
  msortHelper(arr, aux, 0, len-1);
}
