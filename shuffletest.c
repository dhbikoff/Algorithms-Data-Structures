#include "knuthshuffle.h"
#include <stdio.h>

int main() {
  srand(time(NULL));
  for (int i = 0; i < 100; i++) {
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int len = 10;
    shuffle(arr, len);
    for (int j = 0; j < len; j++)
      printf("%d ", arr[j]);
    printf("\n");
  }  
}
