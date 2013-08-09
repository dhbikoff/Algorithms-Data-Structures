#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "heapsort.h"
#include "insertionsort.h"
#include "mergesort.h"
#include "quicksort.h"
#include "radixsort.h"
#include "selectionsort.h"
#include "shellsort.h"

int sorted(int arr[], int len);
void test(void *(sort)(int[],int));

void* fn[] = {hsort, isort, msort, qusort, rsort, ssort, shsort};
int fnsize = 7;

int main(int argc, char **argv) 
{
  srand(time(NULL)); 
  for (int i = 0; i < fnsize; i++) {
    test(fn[i]);
  }
}

int sorted(int arr[], int len) 
{
  for (int i = 0; i < len-1; i++) {
    if (arr[i] > arr[i+1])
      return 1;
  }
  return 0;
}

void test(void *(sort)(int[],int))
{
  int passed = 0;
  int failed = 0;
  for (int z = 0; z < 10000; z++) {
    int len = 100;
    int arr[len];

    for (int i = 0; i < len; i++) {
      arr[i] = rand() % 1000;
    }

    sort(arr, len);
    int res = sorted(arr, len);
    if (res == 0)
      passed++;
    else
      failed++;
    if (z == 99) {
      for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
      }
      printf("\n");
    }
  }
  printf("Passed = %d Failed = %d\n", passed, failed);
}

