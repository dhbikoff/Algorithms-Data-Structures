#include "shellsort.h"
#include "swap.h"

void shsort(int arr[], int len) 
{
  int h = 1;
  while (h < len/3)
    h = 3*h + 1;

  while(h >=1) {
    for (int i = h; i < len; i++) {
      for (int j = i; j >= h; j -=h) {
        if (arr[j] < arr[j-h])
          swap(arr, j, j-h); 
      }
    }
    h /= 3;
  }
}


