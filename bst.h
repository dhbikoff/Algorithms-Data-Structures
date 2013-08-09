#ifndef _bst_
#define _bst_

#include <stdlib.h>
#include "queue.h"

bst* BST();
BSTnode* BSTPutrec(BSTnode *ptr, int num);
void BSTPut(bst *b, int num);
queue* BSTQueuerec(BSTnode *n, queue *q);
queue* BSTQueue(bst *b, queue *q);
void BSTPrintrec(BSTnode *n);
void BSTPrint(bst *b) ;
int BSTMinrec(BSTnode *n);
int BSTMin(bst *b);
void BSTFreerec(BSTnode *n);
void BSTFree(bst *b);

#endif
