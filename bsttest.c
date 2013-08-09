#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bst.h"
#include "queue.h"
#include "radixsort.h"

int test(int len, int range)
{
  queue *q = QueueNew();
  bst *b = BST();

  int arr[len];
  for (int i = 0; i < len; i++) {
    int n = rand() % range;
    arr[i] = n;
    BSTPut(b,n);
  }

  BSTQueue(b, q);
  sort(arr, len);
  int passed = 1;
  for (int i = 0; i < len; i++) {
    if (QueueRemove(q) != arr[i])
      passed = 0;
  }

  QueueFree(q);
  BSTFree(b);
  return passed;
}

int main() 
{
  srand(time(0));
  int x = 10000;
  int count = 0;  
  for (int i = 0; i < x; i++) {
    count += test(1000,1000);
  }
  printf("Passed %d%%\n", (int)((count/(double)x) * 100));
}
