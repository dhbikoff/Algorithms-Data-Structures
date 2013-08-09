#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

typedef struct StackNode
{
  int val;
  struct StackNode *next;
} Stacknode;

typedef struct Stack
{
  int size;
  Stacknode *head;
} stack;

stack* StackNew()
{
  stack *s = malloc(sizeof(stack));
  s->head = 0;
  s->size = 0;
  return s;
}

void StackPush(stack *s, int num)
{
  Stacknode *n = malloc(sizeof(Stacknode));
  n->val = num;
  n->next = s->head;
  s->head = n;
}

int StackPop(stack *s)
{
  int val = s->head->val;
  Stacknode *tmp = s->head;
  s->head = s->head->next;
  free(tmp);
  return val;
}

int StackPeek(stack *s)
{
  int val = s->head->val;
  return val;
}

void StackFree(stack *s)
{
  Stacknode *n = s->head;
  while(n != 0) {
    Stacknode *tmp = n;
    n = n->next;
    free(tmp);
  }
  free(s);
}

void StackPrint(stack *s)
{
  Stacknode *n = s->head;
  while(n != 0) {
    printf("%d ", n->val);
    n = n->next;
  }
  printf("\nSize = %d\n", s->size);
}

