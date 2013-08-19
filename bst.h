#ifndef _bst_
#define _bst_

#include "bst.h"
#include "queue.h"

typedef struct BSTNode
{
  int val;
  struct BSTNode *left;
  struct BSTNode *right;
} BSTnode;

typedef struct BST
{
  BSTnode *root;
  int size;
} bst;

bst* BST();
void BSTPut(bst *b, int num);
queue* BSTQueue(bst *b, queue *q);
void BSTPrint(bst *b) ;
int BSTMin(bst *b);
void BSTFree(bst *b);
int BSTSearch(bst *b, int key);
#endif
