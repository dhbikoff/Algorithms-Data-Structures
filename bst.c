#include <stdlib.h>
#include "bst.h"
#include "queue.h"

bst* BST()
{
  bst *b = malloc(sizeof(bst));
  b->size = 0;
  b->root = 0;
  return b;
}

BSTnode* BSTPutrec(BSTnode *ptr, int num)
{
  if (ptr == 0) {
    BSTnode *n = malloc(sizeof(BSTnode));
    n->val = num;
    n->left = 0;
    n->right = 0;
    return n;
  }

  if (num < ptr->val) 
    ptr->left = BSTPutrec(ptr->left,num);
  else 
    ptr->right = BSTPutrec(ptr->right, num);
  return ptr;
}

void BSTPut(bst *b, int num)
{
  BSTnode *n = b->root;
  b->root = BSTPutrec(n, num);
  b->size++;
}

queue* BSTQueuerec(BSTnode *n, queue *q)
{
  if (n != 0) {
    BSTQueuerec(n->left, q);
    QueueAdd(q, n->val);
    BSTQueuerec(n->right, q);
  }
  return q;
}

queue* BSTQueue(bst *b, queue *q)
{
  return BSTQueuerec(b->root, q);
}

void BSTPrintrec(BSTnode *n)
{
  if (n == 0) return;
  BSTPrintrec(n->left);
  printf("%d ", n->val);
  BSTPrintrec(n->right);
}

void BSTPrint(bst *b) 
{
  BSTPrintrec(b->root);
  printf("\nSize = %d\n", b->size);
}

int BSTMinrec(BSTnode *n)
{
  if (n->left == 0) return n->val;
  else return BSTMinrec(n->left);
}

int BSTMin(bst *b)
{
  return BSTMinrec(b->root);
}

void BSTFreerec(BSTnode *n)
{
  if (n == 0) return;
  BSTFreerec(n->left);
  free(n);
  BSTFreerec(n->right);
}

void BSTFree(bst *b)
{
  BSTFreerec(b->root);
}

