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
void test(void *(sort)(int[],int), char *name, 
          int counter, int range, int size);

void* fn[] = {qusort, msort, rsort, hsort, ssort, isort, shsort};
char* names[] = {"quicksort", "mergesort", "radixsort", "heapsort",
                 "selectionsort", "insertionsort", "shellsort"};
int fnsize = 7;

int main(int argc, char **argv) 
{
  srand(time(0));  
    
  for (int i = 0; i < fnsize; i++) {
    test(fn[i], names[i], 1, 1000, 100000);
  }
}

int sorted(int arr[], int len) 
{
  int pass = 0;
  for (int i = 0; i < len-1; i++) {
    if (arr[i] > arr[i+1])
      pass = 1;
  }
  return pass;
}

void test(void *(sort)(int[],int), char *name, 
          int counter, int range, int size)
{
  clock_t begin = clock();
  
  int passed = 0;
  for (int z = 0; z < counter; z++) {
    int arr[size];

    for (int i = 0; i < size; i++) {
      arr[i] = rand() % range;
    }

    sort(arr, size);

    int res = sorted(arr, size);
    if (res == 0)
      passed++;
  }
  
  clock_t end = clock();
  double time_spent = (double)(end-begin) / CLOCKS_PER_SEC;
  int percent = (int)((passed/(double)counter) * 100);

  printf("%s, ", name);
  printf("Passed = %d%% Size = %d Time = %f\n", percent, size, time_spent);
}

