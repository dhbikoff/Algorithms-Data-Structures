#include "insertionsort.h"
#include "swap.h"

void isort(int arr[], int len)
{
  for (int i = 0; i < len; i++) {
    for (int j = i; j > 0; j--) {
      if(arr[j] < arr[j-1])
        swap(arr, j, j-1);
    }
  }
}

