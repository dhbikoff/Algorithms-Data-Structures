/*
 * queue.h
 *
 * Integer Queue. Has head and tail pointers for O(1) add and remove.  
 *
 */

#ifndef _queue_
#define _queue_

#include <stdio.h>
#include <stdlib.h>

typedef struct QueueNode
{
  int val;
  struct QueueNode *next;
} Queuenode;

typedef struct Queue
{
  int size;
  Queuenode *head;
  Queuenode *tail;
} queue;

queue* QueueNew();
void QueueAdd(queue *q, int num);
int QueueRemove(queue *q); 
int QueuePeek(queue *q);
void QueueFree(queue *q);
void QueuePrint(queue *q); 

#endif
