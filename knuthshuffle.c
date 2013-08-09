#include <stdlib.h>
#include <time.h>
#include "knuthshuffle.h"
#include "swap.h"

void kshuffle(int arr[], int len)
{
  for (int i = 0; i < len; i++) {
    double d = ((double) rand() / (RAND_MAX));
    int r = i + (int)(d * (len-i));
    int swap = arr[r];
    arr[r] = arr[i];
    arr[i] = swap;
  }
}


