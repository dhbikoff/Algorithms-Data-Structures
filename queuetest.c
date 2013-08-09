#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "queue.h"

int main() 
{
  int N = 50;
  srand(time(0));
  queue *q = QueueNew();
  printf("Node size = %ld Queue size = %ld\n", sizeof(Queuenode), sizeof(queue));
  for (int i = 0; i < N; i++) {
    printf("Adding %d\n", i);
    QueueAdd(q, i);
  }
 
  QueuePrint(q);

  for (int i = 0; i < N; i++) {
    int n = QueueRemove(q);
    printf("Removing %d\n", n);
    if (n != i) return -1;
    if (i % 2 == 0)
      printf("Peek = %d\n", QueuePeek(q));
  }
  QueueFree(q);
}
