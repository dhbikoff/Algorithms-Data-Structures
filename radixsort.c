#include "queue.h"
#include "radixsort.h"

void rcopy(queue *qs[], int qsize, int arr[], int asize)
{
  int arrIndex = 0;
  for (int i = 0; i < qsize; i++) {
    int size = qs[i]->size;
    for (int j = 0; j < size; j++) {
      arr[arrIndex] = QueueRemove(qs[i]);
      arrIndex++;
    }
  }
}

void rsort(int arr[], int len) 
{
  queue *qs[10];
  for (int i = 0; i < 10; i++) qs[i] = QueueNew();

  for (int i = 0; i < 3 ; i++) { // 3 digit mods
    for (int j = 0; j < len; j++) { // array index
      int tmp = arr[j];
      for (int k = 0; k < i; k++) tmp /= 10; // get current digit
      int index = (tmp % 10); // bucket
      QueueAdd(qs[index], arr[j]);
    }
    rcopy(qs, 10, arr, len); // dump back to array
  }
    
  for (int i = 0; i < 10; i++) QueueFree(qs[i]);
}

