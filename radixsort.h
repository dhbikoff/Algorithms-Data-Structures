/*
 * radixsort.h
 *
 * Basic radix sort. Only works for non-negative ints of 
 * 3 digits or less.
 *
 */

#ifndef _radixsort_
#define _radixsort_

#include "queue.h"

void rcopy(queue *qs[], int qsize, int arr[], int asize);

void rsort(int arr[], int len); 

#endif
