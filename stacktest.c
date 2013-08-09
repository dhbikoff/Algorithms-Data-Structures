#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "stack.h"

int main() 
{
  int N = 50;
  srand(time(0));
  stack *s = StackNew();
  printf("Node size = %ld Stack size = %ld\n", sizeof(node), sizeof(stack));
  for (int i = 0; i < N; i++) {
    printf("Push %d\n", i);
    StackPush(s, i);
  }
 
  StackPrint(s);

  for (int i = 0; i < N; i++) {
    int n = StackPop(s);
    printf("Pop %d\n", n);
    if (i % 2 == 0)
      printf("Peek = %d\n", StackPeek(s));
  }
  
  printf("Size = %d\n", s->size);
  StackFree(s);
  long sum = sizeof(node) * 50 + sizeof(stack);
  printf("%ld total bytes\n", sum);
}
