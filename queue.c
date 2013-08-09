#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

queue* QueueNew()
{
  queue *q = malloc(sizeof(queue));
  q->head = 0;
  q->tail = 0;
  q->size = 0;
  return q;
}

void QueueAdd(queue *q, int num) 
{
  Queuenode *n = malloc(sizeof(Queuenode));
  n->val = num;
  n->next = 0;

  if (q->size == 0) {
    q->head = n;
    q->tail = n;
  } else if (q->size == 1) {
    q->head->next = n;
    q->tail = n;
  } else {
    q->tail->next = n;
    q->tail = n;
  }

  q->size++;
}

int QueueRemove(queue *q) 
{
  Queuenode *tmp = q->head;
  int num = tmp->val;
  q->head = q->head->next;
  free(tmp);
  q->size--;
  return num;
}

int QueuePeek(queue *q)
{
  return q->head->val;
}

void QueueFree(queue *q)
{
  Queuenode *n = q->head;
  while(n != 0) {
    Queuenode *tmp = n;
    n = n->next;
    free(tmp);
  }
  free(q);
}

void QueuePrint(queue *q) 
{
  Queuenode *n = q->head;
  while(n != 0) {
    printf("%d ", n->val);
    n = n->next;
  }
  printf("\nSize = %d\n", q->size);
}


