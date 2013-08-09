#ifndef _stack_
#define _stack_

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

stack* StackNew();
void StackPush(stack *s, int num);
int StackPop(stack *s);
int StackPeek(stack *s);
void StackFree(stack *s);
void StackPrint(stack *s);

#endif
